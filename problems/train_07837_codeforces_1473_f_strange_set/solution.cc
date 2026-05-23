#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int,int>;

struct Dinic {
  // Edge u->v with capacity cap
  struct FlowEdge {
    int u,v;
    ll cap, flow = 0;
    FlowEdge(int u, int v, ll cap) : u(u),v(v),cap(cap) {}
  };

  const ll INF = 1e18;
  vector<FlowEdge> edges;
  vector<vector<int>> adj;
  int n,m = 0;
  int s,t;
  vector<int> level, ptr;
  queue<int> q;

  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n); level.resize(n); ptr.resize(n);
  }
  void add_edge(int u,int v, ll cap) {
    edges.push_back({u,v,cap});
    edges.push_back({v,u,0});
    adj[u].push_back(m);
    adj[v].push_back(m+1);
    m += 2;
  }
  bool bfs() {
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for (int e : adj[u]) {
        if (edges[e].cap - edges[e].flow < 1) continue;
        if (level[edges[e].v] != -1) continue;
        level[edges[e].v] = level[u]+1;
        q.push(edges[e].v);
      }
    }
    return level[t] != -1;
  }
  ll dfs(int u, ll pushed) {
    if (pushed == 0) return 0;
    if (u==t) return pushed;
    for (int& cid = ptr[u]; cid < (int) adj[u].size(); cid++) {
      int id = adj[u][cid];
      int v = edges[id].v;
      if (level[u]+1!=level[v]||edges[id].cap -edges[id].flow<1) continue;
      ll tr = dfs(v,min(pushed,edges[id].cap-edges[id].flow));
      if (tr==0) continue;
      edges[id].flow += tr;
      edges[id^1].flow -= tr;
      return tr;
    }
    return 0;
  }
  ll flow() {
    ll f = 0;
    while(1) {
      fill(level.begin(),level.end(),-1);
      level[s] = 0;
      q.push(s);
      if (!bfs()) break;
      fill(ptr.begin(),ptr.end(),0);
      while(ll pushed = dfs(s,INF))
        f += pushed;
    }
    return f;
  }
  vector<bool> min_cut() {
    vector<bool> res(n);
    for (int i = 0; i < n; i++)
      res[i] = (level[i] != -1);
    return res;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  int s = N;
  int t = N+1;
  Dinic d(N+2,s,t);
  vector<int> last(101,-1);
  for (int i = 0; i < N; i++) {
    if (b[i] > 0)
      d.add_edge(s,i,b[i]);
    if (b[i] < 0)
      d.add_edge(i,t,-b[i]);
    for (int k = 1; k <= 100; k++) 
      if (last[k] != -1 && a[i]%k == 0)
        d.add_edge(i,last[k],(int)1e9);
    last[a[i]] = i;
  }
  int sum = 0;
  for (int i = 0; i < N; i++) 
    sum += max(0,b[i]);
  cout << sum - d.flow() << '\n';
}

