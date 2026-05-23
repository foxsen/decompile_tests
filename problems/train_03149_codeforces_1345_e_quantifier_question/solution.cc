#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int n, m;
vector<int> G[N], GG[N];
int vis[N], mn[N], mn2[N];
bool dfs(int u) {
  vis[u] = 1;
  mn[u] = u;
  for (int v : G[u]) {
    if (vis[v] == 1) return false;
    if (!vis[v]) {
      if (!dfs(v)) return false;
    }
    mn[u] = min(mn[u], mn[v]);
  }
  vis[u] = 2;
  return true;
}
bool dfs2(int u) {
  vis[u] = 1;
  mn2[u] = u;
  for (int v : GG[u]) {
    if (vis[v] == 1) return false;
    if (!vis[v]) {
      if (!dfs2(v)) return false;
    }
    mn2[u] = min(mn2[u], mn2[v]);
  }
  vis[u] = 2;
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[v].push_back(u);
    GG[u].push_back(v);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      if (!dfs(i)) {
        puts("-1");
        return 0;
      }
    }
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      if (!dfs2(i)) {
        puts("-1");
        return 0;
      }
    }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (mn[i] >= i && mn2[i] >= i) ans++;
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    printf("%c", mn[i] >= i && mn2[i] >= i ? 'A' : 'E');
  puts("");
  return 0;
}
