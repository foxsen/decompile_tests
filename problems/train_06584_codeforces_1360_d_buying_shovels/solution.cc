#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int ans = n;
    for (int i = 1; i * i <= n; i++) {
      if (i <= k && n % i == 0) {
        ans = min(ans, n / i);
        if (n / i <= k) ans = min(ans, i);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
