#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long mod = 1e9 + 7;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, sum = 0, res = 0, max = 0;
    cin >> n;
    long long a[n + 1], b[n + 1];
    vector<pair<long long, long long> > v(n + 1);
    for (i = 1; i < n + 1; i++) cin >> a[i];
    for (i = 1; i < n + 1; i++) {
      cin >> b[i];
      v[i] = {a[i], b[i]};
    }
    sort((v).begin() + 1, (v).end());
    for (int i = n; i >= 1; i--) {
      if (sum + v[i].second <= v[i].first) {
        sum += v[i].second;
      } else {
        max = v[i].first;
        break;
      }
    }
    if (sum > max)
      cout << sum << endl;
    else
      cout << max << endl;
  }
  return 0;
}
