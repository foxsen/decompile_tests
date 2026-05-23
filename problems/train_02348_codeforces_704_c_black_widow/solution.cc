#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
int x, k, X, Y, n, m, u[100005];
long long ans[2];
int f[2], g[2][2][2], G[2][2][2], vis[100005];
vector<int> a[100005], A[100005], e[100005], w[100005];
void dfs(int x) {
  if (vis[x]) return;
  vis[x] = 1;
  memset(G, 0, sizeof G);
  int j = a[x][0] == Y, i = j ^ 1;
  if (a[x].size() == 1) {
    for (int p = 0; p < 2; ++p)
      for (int q = 0; q < 2; ++q)
        for (int k = 0; k < 2; ++k)
          (G[p][q][k ^ q ^ w[x][0]] += g[p][q][k]) %= mo;
    memcpy(g, G, sizeof G);
    dfs(e[x][0]);
  } else {
    for (int p = 0; p < 2; ++p)
      for (int q = 0; q < 2; ++q)
        for (int k = 0; k < 2; ++k) {
          if (X == a[x][j]) {
            int t = p;
            (G[p][t][k ^ ((q ^ w[x][i]) | (t ^ w[x][j]))] += g[p][q][k]) %= mo;
          } else {
            for (int t = 0; t < 2; ++t)
              (G[p][t][k ^ ((q ^ w[x][i]) | (t ^ w[x][j]))] += g[p][q][k]) %=
                  mo;
          }
        }
    Y = a[x][j];
    memcpy(g, G, sizeof G);
    if (A[Y][0] != x)
      dfs(A[Y][0]);
    else if (A[Y].size() == 2)
      dfs(A[Y][1]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (scanf("%d", &k); k; --k) {
      scanf("%d", &x);
      a[i].push_back(abs(x));
      w[i].push_back(x < 0);
      A[abs(x)].push_back(i);
    }
  }
  ans[0] = 1;
  ans[1] = 0;
  for (int i = 1; i <= m; ++i)
    if (A[i].size() == 2 && A[i][0] != A[i][1]) {
      ++u[A[i][0]];
      ++u[A[i][1]];
      e[A[i][0]].push_back(A[i][1]);
      e[A[i][1]].push_back(A[i][0]);
    } else if (!A[i].size()) {
      ans[0] = ans[0] * 2 % mo;
    }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      if (!e[i].size()) {
        vis[i] = 1;
        f[0] = f[1] = 0;
        if (a[i].size() == 1) {
          f[0] = f[1] = 1;
        } else {
          if (a[i][0] != a[i][1]) {
            for (int p = 0; p < 2; ++p)
              for (int q = 0; q < 2; ++q) ++f[(p ^ w[i][0]) | (q ^ w[i][1])];
          } else {
            for (int p = 0; p < 2; ++p) ++f[(p ^ w[i][0]) | (p ^ w[i][1])];
          }
        }
        long long pp = f[0] * ans[0] + f[1] * ans[1],
                  qq = f[1] * ans[0] + f[0] * ans[1];
        ans[0] = pp % mo;
        ans[1] = qq % mo;
      } else if (u[i] == 1) {
        if (a[i].size() == 1 || A[a[i][0]].size() == 1)
          X = Y = a[i][0];
        else
          X = Y = a[i][1];
        memset(g, 0, sizeof g);
        g[0][0][0] = g[1][1][0] = 1;
        dfs(i);
        f[0] = f[1] = 0;
        for (int p = 0; p < 2; ++p)
          for (int q = 0; q < 2; ++q)
            for (int k = 0; k < 2; ++k) (f[k] += g[p][q][k]) %= mo;
        long long pp = f[0] * ans[0] + f[1] * ans[1],
                  qq = f[1] * ans[0] + f[0] * ans[1];
        ans[0] = pp % mo;
        ans[1] = qq % mo;
      }
    }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      X = Y = a[i][0];
      memset(g, 0, sizeof g);
      g[0][0][0] = g[1][1][0] = 1;
      dfs(i);
      f[0] = f[1] = 0;
      for (int p = 0; p < 2; ++p)
        for (int q = 0; q < 2; ++q)
          for (int k = 0; k < 2; ++k) (f[k] += g[p][q][k]) %= mo;
      long long pp = f[0] * ans[0] + f[1] * ans[1],
                qq = f[1] * ans[0] + f[0] * ans[1];
      ans[0] = pp % mo;
      ans[1] = qq % mo;
    }
  printf("%lld\n", ans[1] % mo);
  return 0;
}
