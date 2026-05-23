#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

#define rep(i, n) for(int i = 0; i< n; i++)
typedef long long ll;
typedef pair<ll, ll> P;
const int maxn = 100010;

ll dist[maxn];
vector<P> G[maxn];

vector<ll> bfs(){
  queue<ll> que;
  vector<ll> res;
  memset(dist, -1, sizeof(dist));
  dist[0] = 0;
  que.push(0);
  
  while(!que.empty()){
    int v = que.front(); que.pop();
    rep(i, (int)G[v].size()){
      int to = G[v][i].first;
      ll cost = G[v][i].second;
      if(dist[to] == -1){
	dist[to] = dist[v] ^ cost;
	que.push(to);
      }else{
	if(dist[to] ^ dist[v] ^ cost) res.push_back(dist[to] ^ dist[v] ^ cost);
      }
    }
  }
  return res;
}

vector<ll> collect(vector<ll> cycle){
  int n = cycle.size();
  vector<ll> res(60, 0);
  for(int i = 59; i >= 0; i--){
    rep(j, n){
      if((cycle[j] >> i) & 1){
	res[i] = cycle[j];
	rep(k, n){
	  if(k != j && ((cycle[k] >> i) & 1)) cycle[k] ^= cycle[j];
	}
	cycle[j] = 0;
	break;
      }
    }
  }
  return res;
}

ll calc(ll res, const vector<ll> &base){
  for(int i = 59; i >= 0; i--){
    if(((base[i] ^ res) >> i) & 1) res ^= base[i]; 
  }
  return res;
}

int main(){
  ll N, M, Q, a, b, f, t, p;
  
  cin >> N >> M >> Q;
  rep(i, M) {
    cin >> f >> t >> p;
    G[f].push_back(P(t, p));
    G[t].push_back(P(f, p));
  }
  
  vector<ll> cycle = bfs();
  vector<ll> base = collect(cycle);
  
  rep(i, Q){
    cin >> a >> b;
    cout << calc(dist[a] ^ dist[b], base) << endl;
  }
  return 0;
}