#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 100;
long long n, k;
vector<pair<long long, long long>> sieve(long long n) {
  vector<pair<long long, long long>> v;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) {
      long long kk = 0;
      while (n % i == 0) {
        n /= i;
        kk++;
      }
      v.push_back({i, kk});
    }
  if (n > 1) v.push_back({n, 1});
  return v;
}
pair<long long, long long> check(long long x) {
  long long u = 1, v = 1;
  auto z = sieve(x);
  for (auto it : z) {
    it.second %= k;
    if (it.second > 0) {
      for (int i = 0; i < it.second; i++) u *= it.first;
      for (int i = 0; i < k - it.second; i++) {
        v *= it.first;
        if (v > 1e5) return (make_pair(-1, -1));
      }
    }
  }
  return (make_pair(u, v));
}
void solve() {
  map<long long, long long> hash;
  long long res = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    pair<long long, long long> ok;
    ok = check(x);
    if (ok.second != -1) {
      if (hash.count(ok.second)) res += hash[ok.second];
      hash[ok.first]++;
    }
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
