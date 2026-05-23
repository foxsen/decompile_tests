#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return (binpow(a, n - 1) * a) % mod;
  else {
    long long b = binpow(a, n / 2);
    return (b * b) % mod;
  }
}
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<long long> fac(n + m + 1);
  fac[0] = 1;
  for (int i = 1; i <= n + m; ++i) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
  vector<long long> obr(n);
  for (int i = 0; i < n; ++i) {
    obr[i] = binpow(fac[i], mod - 2);
  }
  long long obrm = binpow(fac[m], mod - 2);
  long long obrm1 = binpow(fac[m - 1], mod - 2);
  long long ans = 0;
  for (int y = 1; y <= n; ++y) {
    long long b = (((fac[n + m - 1 - y] * obrm1) % mod) * obr[n - y]) % mod;
    long long a = (((fac[y + m - 1] * obrm) % mod) * obr[y - 1]) % mod;
    ans += (a * b) % mod;
  }
  cout << (ans + mod) % mod << endl;
}
