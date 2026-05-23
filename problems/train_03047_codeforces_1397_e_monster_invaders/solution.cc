#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, c = getchar();
  for (; !(c > 47 && c < 58); c = getchar())
    ;
  for (; (c > 47 && c < 58); c = getchar()) x = x * 10 + c - 48;
  return x;
}
void upd(long long &a, long long b) { a = (a < b) ? a : b; }
const int N = 1e6 + 5;
long long f[N][2];
int n, r1, r2, r3, d, a[N];
int main() {
  n = read(), r1 = read(), r2 = read(), r3 = read(), d = read();
  for (int i = 1; i <= n; a[i++] = read())
    ;
  for (int i = 2; i <= n; ++i) f[i][0] = f[i][1] = 1e18;
  f[1][0] = 1ll * r1 * a[1] + r3;
  f[1][1] = min(0ll + r2, 1ll * r1 * a[1] + r1);
  for (int i = 1; i < n; ++i) {
    upd(f[i + 1][0], f[i][0] + d + 1ll * r1 * a[i + 1] + r3);
    upd(f[i + 1][1], f[i][0] + d + min(0ll + r2, 1ll * r1 * a[i + 1] + r1));
    upd(f[i + 1][0], f[i][1] + d + 1ll * r1 * a[i + 1] + r3 + 2 * d + r1);
    upd(f[i + 1][0], f[i][1] + d + 1ll * r1 * a[i + 1] + r1 + d + r1 + d + r1);
    upd(f[i + 1][0], f[i][1] + d + r2 + d + r1 + d + r1);
    upd(f[i + 1][1], f[i][1] + d + r2 + d + r1 + d);
    upd(f[i + 1][1], f[i][1] + d + 1ll * r1 * a[i + 1] + r1 + d + r1 + d);
    if (i == n - 1) {
      upd(f[i + 1][0], f[i][1] + d + 1ll * r1 * a[i + 1] + r3 + d + r1);
    }
  }
  cout << f[n][0] << endl;
}
