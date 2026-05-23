#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int LogN = 20;
struct Node {
  vector<int> adj;
  vector<int> idx;
} g[N];
bool mark[N];
int way[N];
int sol[N];
int n, m;
int t;
int in[N], out[N];
int st[N][LogN];
int dist[N], disc[N];
int depth[N];
int indegree[N];
void dfs(int v, int prev, int d, int edge) {
  in[v] = ++t;
  depth[v] = d;
  disc[v] = edge;
  for (int i = 0; i < g[v].adj.size(); i++) {
    int u = g[v].adj[i];
    int idx = g[v].idx[i];
    if (u == prev) continue;
    dfs(u, v, d + 1, idx);
    st[u][0] = v;
  }
  out[v] = ++t;
}
void init() {
  for (int d = 1; d <= 18; d++) {
    for (int i = 1; i <= n; i++) {
      st[i][d] = st[st[i][d - 1]][d - 1];
    }
  }
}
bool subTree(int a, int b) { return (in[a] > in[b] && out[a] < out[b]); }
int lca(int a, int b) {
  if (a == b) return a;
  if (subTree(a, b)) return b;
  if (subTree(b, a)) return a;
  for (int i = 18; i >= 0; i--)
    if (!subTree(b, st[a][i])) a = st[a][i];
  return st[a][0];
}
pair<int, int> edges[N];
int parent[N];
int parentEdge[N];
int decr[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    edges[i] = make_pair(a, b);
    g[a].adj.push_back(b);
    g[b].adj.push_back(a);
    g[a].idx.push_back(i);
    g[b].idx.push_back(i);
  }
  dfs(1, 1, 0, 0);
  for (int i = 1; i < n; i++) {
    int prev =
        (depth[edges[i].first] < depth[edges[i].second] ? edges[i].first
                                                        : edges[i].second);
    int bot = edges[i].first + edges[i].second - prev;
    indegree[prev]++;
    parent[bot] = prev;
    parentEdge[bot] = i;
  }
  st[1][0] = 1;
  init();
  int k;
  scanf("%d", &k);
  while (k--) {
    int a, b;
    scanf("%d%d", &a, &b);
    way[a]++;
    way[b]++;
    way[lca(a, b)] -= 2;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (indegree[i] == 0) q.push(i);
  while (!q.empty()) {
    int src = q.front();
    q.pop();
    if (src == 1) break;
    sol[parentEdge[src]] = way[src];
    way[parent[src]] += way[src];
    if (--indegree[parent[src]] == 0) q.push(parent[src]);
  }
  for (int i = 1; i < n; i++) printf("%d ", sol[i]);
  return 0;
}
