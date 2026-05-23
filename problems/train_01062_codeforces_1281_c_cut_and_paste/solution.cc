#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
const long long mod = 1e9 + 7;
long long t, n, x, a[N];
string s;
int main() {
  cin >> t;
  while (t--) {
    cin >> x >> s;
    for (int i = 1; i <= s.length(); i++) {
      a[i] = s[i - 1] - 48;
    }
    long long len = s.length(), kt = 0;
    for (long long i = 1; i <= x; i++) {
      if (kt == 0) {
        int luu = len;
        for (int j = 1; j <= a[i] - 1; j++) {
          for (int k = i + 1; k <= luu; k++) {
            len++;
            a[len] = a[k];
          }
        }
        if (len >= x) kt = 1;
      } else {
        long long tmp = (len - i + mod * mod) % mod;
        len = (i + (a[i] * tmp) % mod) % mod;
      }
    }
    cout << len << "\n";
  }
}
