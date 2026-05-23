#include <bits/stdc++.h>
using namespace std;
int N, M, lg;
vector<pair<long long, pair<int, int> > > edge, edge1;
vector<pair<long long, pair<int, int> > > mst;
vector<vector<pair<int, long long> > > adj;
vector<vector<int> > p;
vector<vector<long long> > maxi;
vector<int> dep;
int log(int x) {
  int cnt = 0;
  while (x != 1) {
    x /= 2;
    cnt++;
  }
  return cnt;
}
void dfs(int now, int bf, long long l) {
  p[now][0] = bf;
  maxi[now][0] = l;
  for (int i = 1; i <= lg + 1; i++) {
    p[now][i] = p[p[now][i - 1]][i - 1];
    maxi[now][i] = max(maxi[now][i - 1], maxi[p[now][i - 1]][i - 1]);
  }
  for (int i = 0; i < adj[now].size(); i++) {
    int nxt = adj[now][i].first;
    if (nxt == bf) continue;
    int w = adj[now][i].second;
    dep[nxt] = dep[now] + 1;
    dfs(nxt, now, w);
  }
}
struct DJS {
  vector<int> parent, rank;
  int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
  }
  void merge(int v, int u) {
    v = find(v);
    u = find(u);
    if (u == v) return;
    if (rank[v] > rank[u]) swap(u, v);
    parent[v] = u;
    if (rank[u] == rank[v]) rank[u]++;
  }
};
int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int d = dep[u] - dep[v];
  int cnt = 0;
  while (true) {
    if (d == 0) break;
    if (d % 2 == 1) {
      u = p[u][cnt];
    }
    cnt++;
    d /= 2;
  }
  if (u == v) return u;
  for (int i = lg + 1; i >= 0; i--) {
    if (p[u][i] != p[v][i]) {
      u = p[u][i];
      v = p[v][i];
    }
  }
  return p[u][0];
}
int main() {
  scanf("%d %d", &N, &M);
  lg = log(N);
  for (int i = 0; i < M; i++) {
    int p, q;
    long long w;
    scanf("%d %d %ld", &p, &q, &w);
    edge.push_back(make_pair(w, make_pair(p - 1, q - 1)));
  }
  edge1 = edge;
  sort(edge.begin(), edge.end());
  DJS djs;
  djs.parent.resize(N);
  djs.rank.resize(N);
  for (int i = 0; i < N; i++) {
    djs.parent[i] = i;
    djs.rank[i] = 0;
  }
  long long sum = 0;
  for (int i = 0; i < edge.size(); i++) {
    int p = edge[i].second.first;
    int q = edge[i].second.second;
    if (djs.find(p) == djs.find(q)) continue;
    mst.push_back(edge[i]);
    djs.merge(p, q);
    sum += edge[i].first;
  }
  adj.resize(N);
  for (int i = 0; i < mst.size(); i++) {
    int p = mst[i].second.first;
    int q = mst[i].second.second;
    long long w = mst[i].first;
    adj[p].push_back(make_pair(q, w));
    adj[q].push_back(make_pair(p, w));
  }
  p = vector<vector<int> >(N, vector<int>(lg + 3));
  maxi = vector<vector<long long> >(N, vector<long long>(lg + 3));
  dep = vector<int>(N, 0);
  dfs(0, 0, 0);
  for (int i = 0; i < M; i++) {
    int u = edge1[i].second.first;
    int v = edge1[i].second.second;
    int lca = LCA(u, v);
    long long l = 0;
    int d = dep[u] - dep[lca];
    int cnt = 0;
    while (true) {
      if (d == 0) break;
      if (d % 2 == 1) {
        l = max(l, maxi[u][cnt]);
        u = p[u][cnt];
      }
      cnt++;
      d /= 2;
    }
    long long r = 0;
    d = dep[v] - dep[lca];
    cnt = 0;
    while (true) {
      if (d == 0) break;
      if (d % 2 == 1) {
        r = max(r, maxi[v][cnt]);
        v = p[v][cnt];
      }
      cnt++;
      d /= 2;
    }
    cout << sum + edge1[i].first - max(l, r) << endl;
  }
}
