#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 50;
int fa[MAXN], p[MAXN], high[MAXN], a[MAXN], n, cnt = 0;
vector<int> e[MAXN], ans;
inline int read() {
  int res = 0;
  char ch;
  ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    res = (res << 3) + (res << 1) + ch - 48;
    ch = getchar();
  }
  return res;
}
inline bool cmp(int i, int j) { return high[i] < high[j]; }
void dfs1(int u) {
  if (!e[u].size()) {
    high[u] = 1;
    return;
  }
  for (int i = 0; i < e[u].size(); i++) dfs1(e[u][i]);
  int maxx = 0;
  for (int i = 0; i < e[u].size(); i++) maxx = max(maxx, high[e[u][i]]);
  high[u] = maxx + 1;
  return;
}
void dfs2(int u) {
  a[++cnt] = u;
  sort(e[u].begin(), e[u].end(), cmp);
  for (int i = 0; i < e[u].size(); i++) dfs2(e[u][i]);
  return;
}
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int t;
    t = read();
    e[t].push_back(i);
    fa[i] = t;
  }
  dfs1(0);
  dfs2(0);
  for (int i = 1; i <= n; i++) printf("%d%c", a[i], i == n ? '\n' : ' ');
  for (int i = 2; i <= n; i++) p[a[i]] = a[i - 1];
  for (int i = 2; i <= n; i++) {
    int u = a[i];
    while (p[u] != fa[u]) {
      ans.push_back(u);
      p[u] = p[p[u]];
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
