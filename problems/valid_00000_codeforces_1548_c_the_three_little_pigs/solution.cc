#include <bits/stdc++.h>
using namespace std;
vector<long long> inverses(int n, int P) {
  vector<long long> inv(n + 1, 1);
  for (int i = 2; i <= n; ++i) inv[i] = inv[P % i] * (P - P / i) % P;
  return inv;
}
const int mod = 1e9 + 7;
namespace combi {
const int N = 3e6 + 10;
int fac[N], ifac[N];
void init() {
  fac[0] = ifac[0] = 1;
  auto inv = inverses(N, mod);
  for (int i = 1; i < N; ++i) {
    fac[i] = (long long)fac[i - 1] * i % mod;
    ifac[i] = (long long)ifac[i - 1] * inv[i] % mod;
  }
}
int comb(int n, int k) {
  return (long long)fac[n] * ifac[n - k] % mod * ifac[k] % mod;
}
}  // namespace combi
using namespace combi;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  init();
  int n, Q;
  cin >> n >> Q;
  int sz = 3 * (n + 1);
  vector<int> p(sz + 1);
  for (int i = 1; i <= sz; ++i) p[i] = comb(sz, i);
  for (int i = sz; i >= 3; --i) {
    p[i - 1] = ((p[i - 1] - 3LL * p[i]) % mod + mod) % mod;
    p[i - 2] = ((p[i - 2] - 3LL * p[i]) % mod + mod) % mod;
  }
  p.erase(p.begin(), p.begin() + 3);
  for (int x; Q--;) {
    cin >> x;
    cout << p[x] << "\n";
  }
  return 0;
}
