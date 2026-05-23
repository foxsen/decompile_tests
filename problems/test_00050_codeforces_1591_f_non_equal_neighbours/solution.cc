#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
long long powmod(long long a, long long b) {
  b %= p - 1;
  long long r = 1;
  while (b) {
    if (b & 1) r = r * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return r;
}
long long C(long long n, long long m) {
  if (n < m) return m;
  static vector<int> fac({1});
  for (int i = fac.size(); i < n + 1; i++)
    fac.push_back(1ll * i * fac.back() % p);
  return fac[n] * powmod(m, p - 2) % p * powmod(n - m, p - 2) % p;
}
int main() {
  int n;
  cin >> n;
  vector<long long> f(n + 1, 0), sf(n + 1, 0);
  auto sum = [&sf](const int &l, const int &r) {
    if (!l) return sf[r];
    return (sf[r] + p - sf[l - 1]) % p;
  };
  sf[0] = 1;
  auto add = [](long long &a, long long b) { a = (a + b) % p; };
  stack<array<int, 2> > st;
  st.push({0, 0});
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    while (!st.empty() && st.top()[0] > x) st.pop();
    int fa = st.top()[1];
    st.push({x, i});
    f[i] = (1ll * x * (i - 1 & 1 ? p - 1 : 1) % p * sum(fa, i - 1) % p +
            (i - fa & 1 ? p - 1ll : 1ll) * f[fa] % p) %
           p;
    sf[i] = (sf[i - 1] + (i & 1 ? p - 1ll : 1ll) * f[i]) % p;
  }
  cout << f[n] << endl;
  return 0;
}
