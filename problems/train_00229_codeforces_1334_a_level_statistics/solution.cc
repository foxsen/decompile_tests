#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n = 0;
    cin >> n;
    long long mp = 0, mc = 0, is = 1;
    do {
      long long p, c;
      cin >> p >> c;
      if ((p < mp || c < mc || c > p || p - mp < c - mc) && is) {
        cout << "NO" << endl;
        is = 0;
      }
      mp = p;
      mc = c;
    } while (--n);
    if (is) cout << "YES" << endl;
  }
  return 0;
}
