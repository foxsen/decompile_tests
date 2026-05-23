#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long MOD = 1000000007;
long double EPS = 1e-9;
long long binpow(long long b, long long p, long long mod) {
  long long ans = 1;
  b %= mod;
  for (; p; p >>= 1) {
    if (p & 1) ans = ans * b % mod;
    b = b * b % mod;
  }
  return ans;
}
void pre() {}
namespace NT {
long long gcd(long long a, long long b) {
  return (a * b == 0) ? a ^ b : gcd(b, a % b);
}
vector<pair<long long, long long> > factorize(long long n) {
  vector<pair<long long, long long> > ans;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      long long cnt = 0;
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      ans.emplace_back(i, cnt);
    }
  }
  if (n > 1) ans.emplace_back(n, 1);
  return ans;
}
};  // namespace NT
using namespace NT;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > temp = factorize(n);
  long long ans = n;
  for (int i = 0; i < temp.size(); i++) {
    while (temp[i].second > 0) {
      n /= temp[i].first;
      temp[i].second--;
      ans += n;
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  pre();
  long long _t = 1;
  for (long long i = 1; i <= _t; i++) {
    solve();
  }
}
