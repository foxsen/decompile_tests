#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long e = 1, p = 0;
    while (e < 10) {
      long long k = e;
      while (k <= n) {
        p++;
        k = 10 * k + e;
      }
      e++;
    }
    cout << p << endl;
  }
}
