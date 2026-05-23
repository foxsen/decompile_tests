#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
struct Edg {
  int v, c;
};
int bad = 0;
int vis[maxn];
vector<Edg> g[maxn];
int n, m;
vector<int> num[2];
void dfs(int u, int flg, int col) {
  vis[u] = flg;
  num[flg].push_back(u);
  for (int i = 0; i < g[u].size(); i++) {
    Edg& e = g[u][i];
    if (vis[e.v] != -1) {
      if (e.c ^ col ^ vis[e.v] ^ vis[u]) {
        bad = 1;
        return;
      } else
        continue;
    }
    if (e.c ^ col) {
      dfs(e.v, flg ^ 1, col);
    } else {
      dfs(e.v, flg, col);
    }
  }
}
vector<int> ans, ans_tmp;
int main() {
  scanf("%d%d", &n, &m);
  int u, v;
  char s[222];
  int b, r;
  b = r = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%s", &u, &v, s);
    u--, v--;
    int c = (s[0] == 'B') ? 0 : 1;
    g[u].push_back((Edg){v, c});
    g[v].push_back((Edg){u, c});
    if (c)
      b++;
    else
      r++;
  }
  if (b == 0 || r == 0) {
    printf("0\n");
    return 0;
  }
  for (int c = 0; c < 2; c++) {
    bad = 0;
    ans_tmp.clear();
    memset(vis, -1, sizeof(vis));
    for (int i = 0; i < n; i++) {
      if (vis[i] == -1) {
        num[0].clear(), num[1].clear();
        dfs(i, 0, c);
        if (bad) break;
        if (num[0].size() > num[1].size()) {
          for (int j = 0; j < num[1].size(); j++) ans_tmp.push_back(num[1][j]);
        } else {
          for (int j = 0; j < num[0].size(); j++) ans_tmp.push_back(num[0][j]);
        }
      }
    }
    if (bad == 0 && (ans.size() == 0 || ans_tmp.size() < ans.size()))
      ans = ans_tmp;
  }
  if (ans.size() == 0)
    printf("-1\n");
  else {
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i] + 1);
  }
  return 0;
}
