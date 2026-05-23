#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch - '0');
    ch = getchar();
  }
  return f == 1 ? x : -x;
}
inline void print(int a[], int n, int offset) {
  for (int i = 0; i < n; i++) printf("%d ", a[i + offset]);
  printf("\n");
}
const int maxn = 50 + 10;
const int inf = 1e8;
int n, m, g1, g2, s1, s2;
int dis[maxn][maxn], toprk[maxn], btmrk[maxn];
long long f[maxn][maxn];
pair<int, int> a[maxn];
inline void init() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dis[i][j] = inf;
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), w = read();
    dis[u][v] = dis[v][u] = w;
  }
  g1 = read();
  g2 = read();
  s1 = read();
  s2 = read();
}
inline void doit() {
  for (int i = 1; i <= n; i++) dis[i][i] = 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  for (int i = 1; i <= n; i++) sort(dis[i] + 1, dis[i] + n + 1);
  for (int i = 1; i <= n; i++) a[i] = make_pair(dis[i][2], i);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) toprk[a[i].second] = i;
  for (int i = 1; i <= n; i++) a[i] = make_pair(dis[i][n], i);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) btmrk[a[i].second] = n + 1 - i;
  long long ans = 0;
  for (int p = 0; p <= n; p++)
    for (int q = 0; q <= n; q++) {
      if (p == q && p) continue;
      memset(f, 0, sizeof(f));
      f[0][0] = 1;
      for (int i = 1; i <= n; i++) {
        bool gold = false, silver = false, bronze = false;
        if (i == p)
          gold = true;
        else if (i == q)
          bronze = true;
        else {
          if (p && toprk[i] < toprk[p]) gold = true;
          if (q && btmrk[i] < btmrk[q]) bronze = true;
          for (int j = 2; j <= n; j++)
            if ((!p || (dis[i][j] > dis[p][2] ||
                        (dis[i][j] == dis[p][2] && i > p))) &&
                (!q || (dis[i][j] < dis[q][n] ||
                        (dis[i][j] == dis[q][n] && i < q)))) {
              silver = true;
              break;
            }
        }
        for (int g = min(i, g2); g >= 0; g--)
          for (int s = min(i - g, s2); s >= 0; s--) {
            if (!bronze || g + s == i) f[g][s] = 0;
            if (gold && g) f[g][s] += f[g - 1][s];
            if (silver && s) f[g][s] += f[g][s - 1];
          }
      }
      for (int g = g1; g <= g2; g++)
        for (int s = s1; s <= s2; s++) ans += f[g][s];
    }
  printf("%lld\n", ans);
}
int main() {
  init();
  doit();
  return 0;
}
