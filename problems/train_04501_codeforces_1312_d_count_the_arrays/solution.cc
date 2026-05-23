#include <bits/stdc++.h>
using namespace std;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
long long F[200010], IF[200010];
long long power(long long x, unsigned long long y = 998244353 - 2,
                long long p = 998244353) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long ncr(long long n, long long r) {
  if (n < r) return 0;
  long long x = F[n];
  long long y = IF[r];
  long long z = IF[n - r];
  long long ans = ((x * y) % 998244353 * z % 998244353) % 998244353;
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  F[0] = F[1] = 1;
  for (long long i = 2; i < 200010; i++) {
    F[i] = (F[i - 1] * i) % 998244353;
  }
  for (long long i = 0; i < 200010; i++) {
    IF[i] = power(F[i]);
  }
  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  for (long long i = 1; i <= m; i++) {
    long long y =
        ((n - 2) % 998244353 * (power(2, n - 3)) % 998244353) % 998244353;
    long long x = (ncr(i - 1, n - 2) % 998244353 * y % 998244353) % 998244353;
    ans = (x % 998244353 + ans % 998244353) % 998244353;
  }
  if (n == 2) {
    ans = 0;
  }
  cout << ans % 998244353 << endl;
}
