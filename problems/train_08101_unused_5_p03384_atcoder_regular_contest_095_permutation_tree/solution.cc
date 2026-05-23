#include <bits/stdc++.h>

using std::cerr;
using std::endl;

inline int rd() {
  int x; scanf("%d", &x);
  return x;
}

const int N = 1e5 + 233;

int n, dis[N], tag[N], deg[N], stk[N], top, A[N], B[N];
std::vector<int> G[N];

int dfs(int x, int fa) {
  dis[x] = dis[fa] + 1;
  int ret = 0;
  for (int y : G[x]) if (y != fa) {
    int z = dfs(y, x);
    if (dis[z] > dis[ret])
      ret = z;
  }
  if (!ret) return x;
  return ret;
}

int find_path(int x, int fa, int t) {
  if (x == t) {
    tag[x] = 1;
    stk[++top] = x;
    return 1;
  }
  for (int y : G[x]) if (y != fa) {
    if (find_path(y, x, t)) {
      tag[x] = 1;
      stk[++top] = x;
      return 1;
    }
  }
  return 0;
}

inline void work(int st, int f[]) {
  if (stk[1] != st)
    std::reverse(stk + 1, stk + top + 1);
  int sum = 0, w = 0;
  for (int i = 1; i <= top; ++i) {
    int x = stk[i], s = G[x].size() - 1;
    if (i != 1 && i != top) s -= 1;
    for (int j = 1; j <= s; ++j)
      f[++w] = sum + j + 1;
    f[++w] = sum + 1;
    sum += s + 1;
  }
}

int main() {
  /// freopen("data", "r", stdin);
  n = rd();
  for (int i = 1; i < n; ++i) {
    int x = rd(), y = rd();
    G[x].push_back(y);
    G[y].push_back(x);
  }
  int x = dfs(1, 0), y = dfs(x, 0);
  find_path(x, 0, y);
  for (int x = 1; x <= n; ++x) {
    if (tag[x]) continue;
    int ok = 0;
    for (int y : G[x])
      if (tag[y]) {
        ok = 1; break;
      }
    if (!ok)
      return puts("-1"), 0;
  }
  work(x, A), work(y, B);
  for (int i = 1; i <= n; ++i) {
    if (A[i] < B[i] || i == n) {
      for (int j = 1; j <= n; ++j)
        printf("%d ", A[j]);
      break;
    }
    if (A[i] > B[i]) {
      for (int j = 1; j <= n; ++j)
        printf("%d ", B[j]);
      break;
    }
  }
  putchar('\n');
  return 0;
}

