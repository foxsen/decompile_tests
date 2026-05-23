#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 110;
int g[N][N];
int ans, cnt[N], n, m, vis[N];
map<string, int> M;
int ppp;
bool dfs(int u, int dep) {
  for (int i = u + 1; i <= n; i++) {
    int flag = 1;
    if (cnt[i] + dep <= ans) return 0;
    for (int j = 0; j < dep; j++)
      if (!g[i][vis[j]]) {
        flag = 0;
        break;
      }
    if (flag) {
      vis[dep] = i;
      if (dfs(i, dep + 1)) return 1;
    }
  }
  if (dep > ans) {
    ans = dep;
    return 1;
  }
  return 0;
}
void run() {
  ans = -1;
  for (int i = n; i; i--) {
    vis[0] = i;
    dfs(i, 1);
    cnt[i] = ans;
  }
}
int main() {
  scanf("%d%d", &m, &n);
  vector<int> Q;
  memset(g, 1, sizeof g);
  while (m--) {
    int x;
    scanf("%d", &x);
    if (x == 1)
      Q.clear();
    else {
      string str;
      cin >> str;
      if (!M[str]) M[str] = ++ppp;
      for (int i = 0; i < Q.size(); i++) g[Q[i]][M[str]] = g[M[str]][Q[i]] = 0;
      Q.push_back(M[str]);
    }
  }
  run();
  printf("%d\n", ans);
  return 0;
}
