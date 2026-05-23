#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
int t, n, k;
long long st(long long a, long long b) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0) {
    long long aa = (a * a) % M;
    return (st(aa, b / 2) % M);
  } else {
    return ((a * st(a, b - 1)) % M);
  }
}
int main() {
  vector<long long> f = vector<long long>(500005);
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i < 500005; i++) {
    f[i] = i * f[i - 1];
    f[i] %= M;
  }
  cin >> n >> k;
  k--;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int N = n / i;
    N--;
    if (N >= k) ans += (f[N] * st(((f[k] * f[N - k]) % M), M - 2));
    ans %= M;
  }
  cout << ans << "\n";
}
