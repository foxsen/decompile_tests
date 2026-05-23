#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long m = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (ans * x) % m;
    }
    x = (x * x) % m;
    y /= 2;
  }
  return ans % m;
}
long long modInverse(long long a, long long m = 1000000007) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, i, j, ans = 0;
    cin >> n >> k;
    long long a[n + 1];
    a[0] = 0;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] += a[i - 1];
    }
    vector<long long> res;
    long long p = 0;
    for (i = 1; i <= n; i++) {
      if (k == 1) break;
      if ((a[i] - a[p]) & 1) {
        res.push_back(i);
        p = i;
        k--;
      }
    }
    if (res.size() < (k - 1) || ((a[n] - a[p]) % 2 == 0))
      cout << "NO\n";
    else {
      cout << "YES\n";
      res.push_back(n);
      for (auto it : res) cout << it << " ";
      cout << "\n";
    }
  }
  return 0;
}
