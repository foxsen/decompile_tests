#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0LL) return a;
  return gcd(b, a % b);
}
long long bigmod(long long a, long long b, long long mod) {
  if (b == 0LL) return 1LL;
  long long sq = bigmod(a, b / 2LL, mod);
  sq = (sq * sq) % mod;
  if (b & 1LL) return (sq * (a % mod)) % mod;
  return sq;
}
vector<int> primes;
vector<int> sieve(const int n) {
  vector<int> primes(n + 1, 0);
  primes[1] = 1;
  for (int p = 2; p * p <= n; p++) {
    if (!primes[p]) {
      for (int i = p * p; i <= n; i += p) primes[i] = p;
    }
  }
  for (int i = 2; i <= n; i++)
    if (!primes[i]) primes[i] = i;
  return primes;
}
map<int, int> getDivs(int x) {
  map<int, int> divs;
  while (x > 1) {
    int div = primes[x];
    int cnt = 0;
    while (x % div == 0) {
      x /= div;
      cnt++;
    }
    divs[div] = cnt;
  }
  return divs;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  sort((a).begin(), (a).end());
  vector<int> ans(n);
  int mx = 0;
  int k = 0;
  for (int i = 1; i < n; i += 2) {
    ans[i] = a[k++];
  }
  for (int i = 0; i < n; i += 2) {
    ans[i] = a[k++];
  }
  for (int i = 1; i < n - 1; i++) {
    if (ans[i - 1] > ans[i] && ans[i] < ans[i + 1]) mx++;
  }
  cout << mx << endl;
  for (auto x : ans) cout << x << " ";
  cout << endl;
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
