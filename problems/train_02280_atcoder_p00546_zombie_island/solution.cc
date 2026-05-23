#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll n,m,k,u;
ll p,q;

class dijkstra{
  public:
	struct edge{ ll to, cost;};
	ll V;
	vector<vector<edge> > G;
	vector<ll> d;
	dijkstra(ll nv){
		nv += 10;
		d = vector<ll>(nv); 
		V = nv;
		G = vector<vector<edge> >(nv);
	}
		
	void run(ll s){
		priority_queue<P, vector<P>, greater<P> > que;
		fill(d.begin(), d.end(), LLONG_MAX);
		d[s] = 0;
		que.push(P(0, s));

		while(!que.empty()){
			P p = que.top(); que.pop();
			ll v = p.second;
			if(d[v] < p.first) continue;
			for (ll i = 0;i < G[v].size();i++){
				edge e = G[v][i];
				if(d[e.to] > d[v] + e.cost){
					d[e.to] = d[v] + e.cost;
					que.push(P(d[e.to],e.to));
				}
			}
		}
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k >> u;
	cin >> p >> q;

	ll s[100005]; memset(s,-1,sizeof(s)); //-1:正常 それ以外：ゾンビからの距離
	queue<ll> que;
	vector<ll> edge[100005];
	
	for (ll i = 0;i < k;i++){
		ll tmp; cin >> tmp; tmp--;
		s[tmp] = 0;
		que.push(tmp);
	}

	for (ll i = 0;i < m;i++){
		ll a,b; cin >> a >> b;
		a--; b--;
		edge[a].push_back(b); edge[b].push_back(a);
	}

	while(que.size()){
		ll now = que.front(); que.pop();
		for (ll i = 0;i < edge[now].size();i++){
			ll next = edge[now][i];
			if(s[next] == -1){
				s[next] = s[now]+1;
				que.push(next);
			}
		}
	}

	dijkstra D(n);

	for (ll i = 0;i < n;i++){
		for (ll j = 0;j < edge[i].size();j++){
			ll next = edge[i][j];
			if(next == n-1){
				D.G[i].push_back({next,0});
			}else if(s[next] == -1 || s[next] > u){
				D.G[i].push_back({next,p});
			}else if(s[next] != 0){
				D.G[i].push_back({next,q});
			}
		}
	}

	D.run(0);

	cout << D.d[n-1] << endl;

	return 0;

}

