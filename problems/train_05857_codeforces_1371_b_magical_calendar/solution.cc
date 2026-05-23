#include <bits/stdc++.h>
using namespace std;
const long long int ll_MAX = 19223372036859;
const long long int MOD = 1e9 + 7;
long long int fast_expo(long long int x, long long int p) {
  if (p == 0)
    return 1;
  else if (p % 2 == 0) {
    long long int t = fast_expo(x, p / 2) % MOD;
    return (t * t) % MOD;
  } else
    return (x * (fast_expo(x, p - 1)) % MOD) % MOD;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0 || b == 0)
    return a + b;
  else
    return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t_c;
  t_c = 1;
  cin >> t_c;
  for (long long int t_i = 0; t_i < t_c; ++t_i) {
    long long int n, r;
    cin >> n >> r;
    long long int ans;
    if (n > r) {
      ans = (r * (r + 1)) / 2;
    } else {
      ans = ((n - 1) * n) / 2 + 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
