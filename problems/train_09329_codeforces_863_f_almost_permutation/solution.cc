#include <bits/stdc++.h>
using namespace std;
bool print = 0;
struct Edge {
  Edge() { x = y = c = f = w = 0; }
  Edge(long long _x, long long _y, long long _c, long long _f, long long _w)
      : x(_x), y(_y), c(_c), f(_f), w(_w) {}
  long long x, y, c, f, w;
};
struct MinCostMaxFlow {
  int n, m, idm = 0, s, t;
  int totCost, totFlow, oo = int(1e9);
  vector<Edge> EdgeList;
  vector<int> dist;
  vector<vector<int>> adj;
  vector<int> trace;
  MinCostMaxFlow() { n = 0; }
  MinCostMaxFlow(int n) {
    this->n = n;
    adj.assign(n + 5, vector<int>(0, 0));
    EdgeList.clear();
    dist = vector<int>(n + 5);
    trace = vector<int>(n + 5);
  }
  void addEdge(int u, int v, int c, int w) {
    adj[u].push_back(EdgeList.size());
    EdgeList.push_back(Edge(u, v, c, 0, w));
    adj[v].push_back(EdgeList.size());
    EdgeList.push_back(Edge(v, u, 0, 0, -w));
  }
  bool FordBellman(int s, int t) {
    for (int i = 1; i <= n; ++i) dist[i] = oo, trace[i] = -1;
    vector<bool> inq = vector<bool>(n + 5, false);
    queue<int> q;
    q.push(s);
    inq[s] = true;
    dist[s] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      inq[u] = false;
      for (int id : adj[u])
        if (EdgeList[id].c > EdgeList[id].f) {
          int v = EdgeList[id].y;
          Edge e = EdgeList[id];
          int co = 0;
          if (e.w == 1) co = (e.f + 1) * (e.f + 1) - (e.f) * (e.f);
          if (co != 0)
            if (print)
              cerr << "Cost from " << e.x << " to " << e.y << " is " << co
                   << "  " << e.f + 1 << endl;
          if (dist[v] > dist[u] + co) {
            dist[v] = dist[u] + co;
            trace[v] = id;
            if (!inq[v]) {
              q.push(v);
              inq[v] = true;
            }
          }
        }
    }
    return (dist[t] < oo);
  }
  void solve() {
    totFlow = totCost = 0;
    while (FordBellman(s, t)) {
      long long delta = oo;
      if (print) cerr << "Found path from s to t : ";
      for (int u = t; u != s; u = EdgeList[trace[u]].x) {
        if (print) cerr << u << " <- ";
        delta = min(delta, EdgeList[trace[u]].c - EdgeList[trace[u]].f);
      }
      if (print) cerr << s << " with the cost " << dist[t] << endl;
      for (int u = t; u != s; u = EdgeList[trace[u]].x) {
        EdgeList[trace[u]].f += delta;
        EdgeList[trace[u] ^ 1].f -= delta;
      }
      totCost += dist[t];
      totFlow += delta;
    }
  }
};
const int N = 55, oo = 1e8 + 7;
int n, q, lwb[N], upb[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) upb[i] = n, lwb[i] = 1;
  for (int i = 1; i <= q; ++i) {
    int t, l, r, v;
    cin >> t >> l >> r >> v;
    if (t == 1) {
      for (int j = l; j <= r; j++) lwb[j] = max(lwb[j], v);
    } else {
      for (int j = l; j <= r; ++j) upb[j] = min(upb[j], v);
    }
  }
  for (int i = 1; i <= n; ++i)
    if (print) cerr << "Upb[" << i << "] : " << upb[i] << endl;
  for (int i = 1; i <= n; ++i)
    if (lwb[i] > upb[i]) {
      cout << -1;
      return 0;
    }
  MinCostMaxFlow mcmf = MinCostMaxFlow(2 * n + 2);
  mcmf.s = 2 * n + 1;
  mcmf.t = mcmf.s + 1;
  for (int i = 1; i <= n; ++i) {
    mcmf.addEdge(n + i, mcmf.t, oo, 1);
    mcmf.addEdge(mcmf.s, i, 1, 0);
    for (int j = lwb[i]; j <= upb[i]; j++) {
      mcmf.addEdge(i, n + j, 1, 0);
    }
  }
  mcmf.solve();
  if (mcmf.totFlow < n) {
    cout << -1;
    if (print) cerr << mcmf.totFlow << endl;
    return 0;
  } else
    cout << mcmf.totCost << endl;
  return 0;
}
