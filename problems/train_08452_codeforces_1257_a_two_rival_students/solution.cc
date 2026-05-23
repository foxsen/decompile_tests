#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, x, a, b;
    cin >> n >> x >> a >> b;
    long long ans = min(abs(a - b) + x, n - 1);
    cout << ans << "\n";
  }
}
