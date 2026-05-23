#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long long n, x;
    cin >> x >> n;
    if (x & 1) {
      if (n & 1) {
        if ((n / 2) & 1)
          x = x - n - 1;
        else
          x = x + n;
      } else {
        if (((n / 2) & 1)) x = x - 1;
      }
    } else {
      if (n & 1) {
        if ((n / 2) & 1)
          x = x + n + 1;
        else
          x = x - n;
      } else {
        if ((n / 2) & 1) x = x + 1;
      }
    }
    printf("%lld", x);
    if (t) printf("\n");
  }
}
