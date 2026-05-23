#include <bits/stdc++.h>
using namespace std;
const signed int MOD = 1e9 + 7;
signed long long sum_ap(signed long long i, signed long long j) {
  if (i >= j) return 0;
  i = i % MOD;
  j = j % MOD;
  signed long long tmp1 = (j * (j + 1)) >> 1;
  signed long long tmp2 = (i * (i + 1)) >> 1;
  return (tmp1 - tmp2) % MOD;
}
signed int main() {
  signed long long n, m;
  cin >> n >> m;
  signed long long ans = ((n % MOD) * (m % MOD)) % MOD;
  signed long long sq = sqrt(n);
  m = min(n, m);
  signed long long limit = m;
  signed long long sum = 0;
  for (signed int i = (1); i <= (sq); ++i) {
    if (i > limit) break;
    sum = (sum + i * (n / i)) % MOD;
  }
  for (signed int i = (1); i <= (sq); ++i) {
    signed long long arg1 = n / (i + 1);
    if (arg1 < sq) arg1 = sq;
    sum = (sum + i * sum_ap(arg1, min(m, n / i))) % MOD;
  }
  ans = (ans - sum) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}
