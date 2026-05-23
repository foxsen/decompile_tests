#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[30005];
int vis[30005];
void euler(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int v = 0; v < g[u].size(); v++) {
    euler(g[u][v]);
  }
  printf("%d ", u);
}
int main() {
  memset(vis, 0, sizeof(vis));
  scanf("%d %d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) euler(i);
  }
  puts("");
  return 0;
}
