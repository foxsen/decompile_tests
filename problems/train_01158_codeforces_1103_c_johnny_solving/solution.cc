#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n, m, k;
vector<int> E[maxn], leaf, anc[maxn];
int dis[maxn], fa[maxn];
void dfs(int x) {
  dis[x] = dis[fa[x]] + 1;
  bool isleaf = 1;
  for (auto v : E[x]) {
    if (v == fa[x]) continue;
    if (!dis[v]) {
      isleaf = 0;
      fa[v] = x;
      dfs(v);
    } else if (anc[x].size() < 2)
      anc[x].push_back(v);
  }
  if (isleaf) leaf.push_back(x);
}
void outputPath(int v) {
  puts("PATH");
  printf("%d\n", dis[v]);
  while (v) {
    printf("%d ", v);
    v = fa[v];
  }
  puts("");
}
void outputRoute(vector<int>& ans, int v, int x) {
  while (v != fa[x]) {
    ans.push_back(v);
    v = fa[v];
  }
  printf("%d\n", ans.size());
  for (auto v : ans) printf("%d ", v);
  puts("");
}
void outputCycle() {
  puts("CYCLES");
  for (int i = 0; i < k; ++i) {
    int v = leaf[i];
    int x = anc[v][0], y = anc[v][1];
    vector<int> ans;
    if ((dis[v] - dis[x] + 1) % 3)
      outputRoute(ans, v, x);
    else if ((dis[v] - dis[y] + 1) % 3)
      outputRoute(ans, v, y);
    else {
      if (dis[x] > dis[y]) swap(x, y);
      ans.push_back(v);
      outputRoute(ans, y, x);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(1);
  for (auto v : leaf) {
    if (dis[v] * k >= n) {
      outputPath(v);
      return 0;
    }
  }
  outputCycle();
  return 0;
}
