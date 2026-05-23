#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
const double eps = 1e-1;
const long long mod = 1e9 + 7;
bool check_pow_2(long long n) { return (n & (n - 1) == 0); }
bool is_prime(long long a, long long p) {
  for (long long i = 2; i <= sqrt(a) && i <= p; i++)
    if (a % i == 0) return false;
  return true;
}
long long div_up(long long x, long long y) {
  if (x == 0) return 0;
  return (x - 1) / y + 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long i = 0; i < 61; i++)
      if ((n & (1LL << i)) > 0) ans += (1LL << i + 1) - 1;
    cout << ans << '\n';
  }
  return 0;
}
