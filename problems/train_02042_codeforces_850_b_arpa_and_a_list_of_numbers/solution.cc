#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, x, y, a[500010];
long long b[1000010], c[1000010];
int m;
long long ans;
struct IntervalSum {
  long long pre[1000010];
  void init(long long a[], int n) {
    pre[1] = a[1];
    for (int i = 2; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  }
  long long sum(int L, int R) {
    if (R < L) return 0;
    return pre[R] - pre[L - 1];
  }
} s1, s2;
int main() {
  n = read(), y = read(), x = read();
  for (int i = 1; i <= n; i++) a[i] = read(), b[a[i]]++, m = max(m, a[i]);
  if (m == 1) m = 2;
  for (int i = 1; i <= m; i++) c[i] = b[i] * i;
  s1.init(b, m), s2.init(c, m);
  for (int d = 2, i = 1; d <= m; d++) {
    while (i < d && 1ll * y < 1ll * (d - i) * x) i++;
    long long tans = 0;
    for (int j = 0; j * d + 1 <= m; j++) {
      long long t1 = s1.sum(j * d + 1, min(m, j * d + i - 1));
      tans += t1 * y;
      if (i == d || j * d + i > m) continue;
      t1 = s1.sum(j * d + i, min(m, j * d + d - 1));
      long long t2 = s2.sum(j * d + i, min(m, j * d + d - 1));
      tans += (t1 * (j + 1) * d - t2) * x;
    }
    if (d == 2)
      ans = tans;
    else
      ans = min(ans, tans);
  }
  printf("%I64d\n", ans);
  return 0;
}
