#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
long long n, m, q, a[maxn][maxn], s[maxn][maxn], xa, ya, xb, yb;
char ch;
long long bitcnt(long long x) {
  long long ret = 0;
  while (x) {
    if (x & 1) ret++;
    x >>= 1;
  }
  return ret;
}
bool rev(long long x, long long y) {
  x--;
  y--;
  return (bitcnt(x) + bitcnt(y)) & 1;
}
long long sum(long long x, long long y) {
  if (x == 0 || y == 0) return 0;
  long long ret = 0, fx = (x + n - 1) / n, fy = (y + m - 1) / m;
  ret += (fx - 1) * (fy - 1) / 2 * n * m;
  if (fx % 2 == 0 && fy % 2 == 0) {
    if (rev(fx - 1, fy - 1))
      ret += n * m - s[n][m];
    else
      ret += s[n][m];
  }
  ret += (fx - 1) / 2 * n * (y - (fy - 1) * m);
  if (fx % 2 == 0) {
    if (rev(fx - 1, fy))
      ret += n * (y - (fy - 1) * m) - s[n][y - (fy - 1) * m];
    else
      ret += s[n][y - (fy - 1) * m];
  }
  ret += (fy - 1) / 2 * (x - (fx - 1) * n) * m;
  if (fy % 2 == 0) {
    if (rev(fx, fy - 1))
      ret += (x - (fx - 1) * n) * m - s[x - (fx - 1) * n][m];
    else
      ret += s[x - (fx - 1) * n][m];
  }
  if (rev(fx, fy))
    ret += (x - (fx - 1) * n) * (y - (fy - 1) * m) -
           s[x - (fx - 1) * n][y - (fy - 1) * m];
  else
    ret += s[x - (fx - 1) * n][y - (fy - 1) * m];
  return ret;
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf(" %c", &ch), a[i][j] = ch - '0';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
  while (q--) {
    scanf("%lld%lld%lld%lld", &xa, &ya, &xb, &yb);
    printf("%lld\n", sum(xa - 1, ya - 1) + sum(xb, yb) - sum(xa - 1, yb) -
                         sum(xb, ya - 1));
  }
  return 0;
}
