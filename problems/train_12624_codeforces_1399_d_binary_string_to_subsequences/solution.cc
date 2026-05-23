#include <bits/stdc++.h>
using namespace std;
long long mul(long long x, long long y) { return (x * y) % 1000000007; }
long long add(long long x, long long y) { return (x + y) % 1000000007; }
long long power(long long a, long long b) {
  long long res = 1;
  a = a % 1000000007;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
      b--;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long fermat_inv(long long y) { return power(y, 1000000007 - 2); }
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, z = 0, maxx = 0;
    string s;
    cin >> n;
    long long a[n], b[n + 1];
    cin >> s;
    for (i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (z > 0) {
          a[i] = z;
          z--;
        } else {
          maxx++;
          a[i] = maxx;
        }
      } else {
        z++;
        a[i] = z;
        maxx = max(maxx, z);
      }
    }
    cout << maxx << endl;
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
