#include <bits/stdc++.h>
const int M = 15;
const int N = 3005;
const int S = 4505;
using namespace std;
int k;
int T, s;
int n, m;
int dI[N];
int Id[S];
int val[N];
int sum[S];
int f[N][S];
int row[N][M];
const int I = 1000000007;
void out_p(int x) {
  while (x) {
    if (x & 1)
      putchar('1');
    else
      putchar('0');
    x >>= 1;
  }
  putchar(' ');
}
bool comp(int a, int b) { return val[a] > val[b]; }
int main() {
  for (int i = 0; i <= 12; ++i) Id[1 << i] = i + 1;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    memset(f, -63, sizeof(f));
    memset(val, 0, sizeof(val));
    s = (1 << n) - 1, k = min(n, m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        cin >> row[j][i];
        f[0][0] = 0;
        val[j] = max(val[j], row[j][i]);
      }
    for (int i = 1; i <= m; ++i) dI[i] = i;
    sort(dI + 1, dI + m + 1, comp);
    for (int i = 1; i <= k; ++i) {
      int* now = row[dI[i]];
      for (int p = 1; p <= s; ++p) {
        sum[p] = sum[p - (p & -p)] + now[Id[(p & -p)]];
      }
      for (int p = 1; p <= s; ++p)
        for (int o = 0; o < n; ++o) {
          int q = ((p >> o) | (p << (n - o))) & s;
          sum[p] = max(sum[p], sum[q]);
        }
      f[i][0] = f[i - 1][0];
      for (int p = 1; p <= s; ++p) {
        f[i][p] = f[i - 1][p];
        for (int q = p; q; q = (q - 1) & p)
          f[i][p] = max(f[i][p], f[i - 1][p ^ q] + sum[q]);
      }
    }
    printf("%d\n", f[k][s]);
  }
  return 0;
}
