#include <bits/stdc++.h>
using namespace std;
const int maxn = 501;
const long long mod = 1000000007;
const long long ool = 1e18 + 7;
const long long o = 1;
long long a[maxn];
long long b[maxn];
long long k[maxn];
int n;
long long minz;
long long cx[maxn];
long long cy[maxn];
int px[maxn];
int py[maxn];
long long we[maxn][maxn];
int visx[maxn];
int visy[maxn];
long long slack[maxn];
int dfs(int u) {
  visx[u] = 1;
  for (int v = (0); v < (n); ++v) {
    if (visy[v]) continue;
    long long t = cx[u] + cy[v] - we[u][v];
    if (t == 0) {
      visy[v] = 1;
      if (py[v] == -1 || dfs(py[v])) {
        py[v] = u;
        px[u] = v;
        return 1;
      }
    } else if (t < slack[v])
      slack[v] = t;
  }
  return 0;
}
int main(void) {
  scanf("%lld", &n);
  for (int i = (0); i < (n); ++i) {
    scanf("%lld%lld%lld", &a[i], &b[i], &k[i]);
  }
  for (int i = (0); i < (n); ++i) px[i] = py[i] = -1;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j)
      we[i][j] = max(0LL, a[j] - b[j] * min(k[j], (long long)i)),
      cx[i] = max(cx[i], we[i][j]);
  for (int i = (0); i < (n); ++i) {
    for (int i = 0; i < n; ++i) slack[i] = ool;
    for (;;) {
      memset(visx, false, sizeof(visx));
      memset(visy, false, sizeof(visy));
      if (dfs(i)) break;
      long long minz = ool;
      for (int i = (0); i < (n); ++i)
        if (!visy[i]) minz = min(minz, slack[i]);
      for (int i = (0); i < (n); ++i) {
        if (visx[i]) cx[i] -= minz;
        if (visy[i])
          cy[i] += minz;
        else
          slack[i] -= minz;
      }
    }
  }
  long long ans = 0;
  for (int i = (0); i < (n); ++i)
    if (py[i] != -1) ans += we[py[i]][i];
  printf("%lld\n", ans);
  return 0;
}
