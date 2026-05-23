#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
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
int T, n, b, t;
int a[1000005], f[1000005];
int main() {
  T = read();
  n = read();
  b = read();
  t = read();
  t = min(t, min(n, b));
  while (T--) {
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= t; i++)
      for (int j = 1; j <= n; j++) {
        f[a[j]] = f[a[j] - 1] + 1;
        for (int k = a[j] + 1; k <= b && f[a[j]] > f[k]; k++) f[k] = f[a[j]];
      }
    printf("%d\n", f[b]);
  }
  return 0;
}
