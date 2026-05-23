#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long maxn = 2 * (long long)1e5 + 10;
const long double EPS = 1e-9;
const long long INF = (long long)1e18 + 18;
const long long mod = (long long)1e9 + 9;
long long a, b, ans = 0;
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b;
  if (a < b) swap(a, b);
  while (b > 0) {
    ans += (a / b);
    a %= b;
    if (a < b) swap(a, b);
  }
  cout << ans << '\n';
  return 0;
}
