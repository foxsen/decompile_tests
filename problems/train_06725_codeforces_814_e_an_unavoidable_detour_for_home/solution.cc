#include <bits/stdc++.h>
using namespace std;
static const int maxn = 50 + 5;
static const int mod = 1000000007;
int n, d[maxn];
long long f[2][maxn][maxn][maxn][maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &d[i]);
  memset(f[0], 0, sizeof f[0]);
  f[0][d[0] == 2][d[0] == 3][d[1] == 2][d[1] == 3] = 1;
  int cur = 0, next = 1;
  for (int i = 1; i < n - 1; i++) {
    memset(f[next], 0, sizeof f[next]);
    for (int p1 = 0; p1 <= n; p1++)
      for (int p2 = 0; p1 + p2 <= n; p2++)
        for (int c1 = 0; p1 + p2 + c1 <= n; c1++)
          for (int c2 = 0; p1 + p2 + c1 + c2 <= n; c2++)
            if (f[cur][p1][p2][c1][c2]) {
              long long val = f[cur][p1][p2][c1][c2];
              if (!p1 && !p2) {
                f[cur][c1][c2][0][0] = (f[cur][c1][c2][0][0] + val) % mod;
                continue;
              }
              for (int last_level = 0; last_level < 2; last_level++) {
                int last_ways;
                if (!last_level) {
                  last_ways = p1;
                  if (--p1 < 0) {
                    p1++;
                    continue;
                  }
                } else {
                  last_ways = p2;
                  if (--p2 < 0) {
                    p2++;
                    continue;
                  } else
                    p1++;
                }
                if (d[i + 1] == 2) {
                  f[next][p1][p2][c1 + 1][c2] =
                      (f[next][p1][p2][c1 + 1][c2] + val * last_ways) % mod;
                  if (c1)
                    f[next][p1][p2][c1 - 1][c2] =
                        (f[next][p1][p2][c1 - 1][c2] + val * last_ways * c1) %
                        mod;
                  if (c2)
                    f[next][p1][p2][c1 + 1][c2 - 1] =
                        (f[next][p1][p2][c1 + 1][c2 - 1] +
                         val * last_ways * c2) %
                        mod;
                } else {
                  f[next][p1][p2][c1][c2 + 1] =
                      (f[next][p1][p2][c1][c2 + 1] + val * last_ways) % mod;
                  if (c1)
                    f[next][p1][p2][c1][c2] =
                        (f[next][p1][p2][c1][c2] + val * last_ways * c1) % mod;
                  if (c2)
                    f[next][p1][p2][c1 + 2][c2 - 1] =
                        (f[next][p1][p2][c1 + 2][c2 - 1] +
                         val * last_ways * c2) %
                        mod;
                  if (c1 > 1)
                    f[next][p1][p2][c1 - 2][c2] =
                        (f[next][p1][p2][c1 - 2][c2] +
                         val * last_ways * c1 * (c1 - 1) / 2) %
                        mod;
                  if (c2 > 1)
                    f[next][p1][p2][c1 + 2][c2 - 2] =
                        (f[next][p1][p2][c1 + 2][c2 - 2] +
                         val * last_ways * c2 * (c2 - 1) / 2) %
                        mod;
                  if (c1 && c2)
                    f[next][p1][p2][c1][c2 - 1] = (f[next][p1][p2][c1][c2 - 1] +
                                                   val * last_ways * c1 * c2) %
                                                  mod;
                }
                if (!last_level)
                  p1++;
                else
                  p2++, p1--;
              }
            }
    cur ^= 1, next ^= 1;
  }
  cout << f[cur][0][0][0][0] << endl;
  return 0;
}
