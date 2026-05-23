#include <bits/stdc++.h>
using namespace std;
int a[1111111];
int q;
int n;
int64_t gt[1111111];
int64_t Powe(int a, int n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  int64_t b = Powe(a, n / 2);
  b = (b * b) % 998244353;
  if (n % 2 == 1)
    return (b * a) % 998244353;
  else
    return b;
}
int main() {
  scanf("%d", &q);
  gt[0] = 1;
  for (int i = 1; i <= 1000000; i++) gt[i] = (gt[i - 1] * i) % 998244353;
  for (int z = 1; z <= q; z++) {
    scanf("%d", &n);
    int an, as = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (as < a[i]) {
        an = as;
        as = a[i];
      } else
        an = max(an, a[i]);
    }
    sort(a + 1, a + n + 1);
    int A = upper_bound(a + 1, a + n + 1, a[n]) -
            lower_bound(a + 1, a + n + 1, a[n]);
    if (A > 1) {
      cout << gt[n] << endl;
      ok = false;
    }
    if (a[n] - an > 1) {
      cout << 0 << endl;
      ok = false;
    }
    if (ok) {
      int B =
          upper_bound(a + 1, a + n + 1, an) - lower_bound(a + 1, a + n + 1, an);
      int64_t dd = (gt[B] * gt[n - B - 1]) % 998244353;
      int T = n - B - 1;
      int64_t X = 1;
      for (int i = B + 2; i <= n; i++) {
        int u = i - B - 1;
        int64_t cc = (gt[u] * gt[T - u]) % 998244353;
        cc = (gt[T] * Powe(cc, 998244353 - 2)) % 998244353;
        dd = (dd + (((gt[i - 1] * cc) % 998244353) * gt[n - i]) % 998244353) %
             998244353;
      }
      cout << (gt[n] - dd + 998244353) % 998244353 << endl;
    }
  }
}
