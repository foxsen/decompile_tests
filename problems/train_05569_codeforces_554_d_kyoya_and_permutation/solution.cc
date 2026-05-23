#include <bits/stdc++.h>
using namespace std;
long long G(long long a, long long b) {
  if (b == 0) return a;
  return G(b, a % b);
}
long long s[1111], a[1111], ans[1111], fac[1111], ifac[1111];
long long f[55];
int main() {
  ios_base::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  f[0] = f[1] = 1;
  for (int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
  long long cur = 1;
  while (n) {
    if (k <= f[n - 1]) {
      cout << cur << " ";
      n--;
      cur++;
    } else {
      cout << cur + 1 << " " << cur << " ";
      cur += 2;
      k -= f[n - 1];
      n -= 2;
    }
  }
}
