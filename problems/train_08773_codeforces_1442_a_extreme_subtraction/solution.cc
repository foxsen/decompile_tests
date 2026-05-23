#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e18;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, i;
    cin >> n;
    long long a[n + 1], ac[n + 1], dec[n + 1];
    for (i = 1; i <= n; i++) {
      cin >> a[i];
    }
    ac[0] = 0;
    dec[0] = INF;
    bool ok = true;
    for (i = 1; i <= n; i++) {
      dec[i] = min(dec[i - 1], a[i] - ac[i - 1]);
      ac[i] = a[i] - dec[i];
      if (ac[i] < ac[i - 1] || dec[i] > dec[i - 1] || ac[i] < 0 || dec[i] < 0)
        ok = false;
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
