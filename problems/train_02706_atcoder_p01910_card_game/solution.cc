#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long W;

const W INF = 1LL << 58;

struct edge {
	int to;
	W cost;
};
typedef pair<W, int> P;
typedef vector<vector <edge > > Graph;

void dijkstra(vector<int> st, const Graph& G, vector<W>& d) {
	priority_queue< P, vector<P>, greater<P> > que;
	fill(d.begin(), d.end(), INF);
	for(auto s : st) {
		d[s] = 0;
		que.push(P(0, s));
	}
	while(!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		for(int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int a[200000];
int b[200000];
int c[200000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M, R, Q;
	cin >> N >> M >> R >> Q;

	map<int, int> id;
	for(int i = 0; i < M; i++) {
		cin >> a[i] >> b[i] >> c[i];
		id[a[i]] = id[b[i]] = 0;
	}

	int K = 0;
	for(auto v : id) {
		id[v.first] = K++;
	}

	Graph G(K);
	for(int i = 0; i < M; i++) {
		G[id[b[i]]].push_back({ id[a[i]], c[i] });
	}

	vector<W> d[10];
	for(int r = 0; r < R; r++) {
		d[r] = vector<W>(K);
		vector<int> st;
		for(int i = 0; i < M; i++) {
			if(b[i] % R == r) st.push_back(id[b[i]]);
		}
		dijkstra(st, G, d[r]);
	}

	ll sum = 0;
	for(int q = 0; q < Q; q++) {
		int x[2];
		ll z;
		cin >> x[0] >> x[1] >> z;

		ll s = 0;
		for(int r = 0; r < R; r++) {
			bool ok = true;
			ll cost_sum = 0;
			for(int i = 0; i < 2; i++) {
				if(x[i] % R != r) {
					if(!id.count(x[i]) || d[r][id[x[i]]] == INF) ok = false;
					else cost_sum += d[r][id[x[i]]];
				}
			}
			if(ok && z > cost_sum) {
				//cerr << "z - cost_sum : " << z - cost_sum << endl;
				s = max(s, z - cost_sum);
			}
		}
		//cerr << "s : " << s << endl;
		sum += s;
	}
	cout << sum << endl;
}