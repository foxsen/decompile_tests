#include <bits/stdc++.h>
using namespace std;
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T1, class T2>
inline void gmax(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
inline void gmin(T1 &a, T2 b) {
  if (b < a) a = b;
}
const int N = 5005, M = 0, Z = 1e9 + 7;
const int inf = 0x3f3f3f3f;
template <class T1, class T2>
inline void gadd(T1 &a, T2 b) {
  a = (a + b) % Z;
}
int casenum, casei;
int n, m;
int f[N][N];
int d[N][N];
int v[N];
int c[N];
vector<int> a[N];
int sz[N];
void dfs(int x) {
  f[x][0] = d[x][0] = sz[x] = 0;
  for (auto y : a[x]) {
    dfs(y);
    for (int i = sz[x]; ~i; --i) {
      for (int j = 1; j <= sz[y]; ++j) {
        gmin(f[x][i + j], f[x][i] + f[y][j]);
        gmin(f[x][i + j], f[x][i] + d[y][j]);
        gmin(d[x][i + j], d[x][i] + d[y][j]);
      }
    }
    sz[x] += sz[y];
  }
  ++sz[x];
  for (int i = sz[x]; i; --i) {
    f[x][i] = min(f[x][i - 1] + v[x] - c[x], inf);
    gmin(d[x][i], d[x][i - 1] + v[x]);
  }
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    memset(f, 63, sizeof(f));
    memset(d, 63, sizeof(d));
    for (int i = 1; i <= n; ++i) {
      a[i].clear();
      scanf("%d%d", &v[i], &c[i]);
      if (i > 1) {
        int fa;
        scanf("%d", &fa);
        a[fa].push_back(i);
      }
    }
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (f[1][i] <= m || d[1][i] <= m) {
        gmax(ans, i);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
