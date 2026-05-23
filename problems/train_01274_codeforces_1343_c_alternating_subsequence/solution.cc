#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int n;
    cin >> n;
    long long ans = 0;
    int last;
    int x;
    cin >> x;
    last = x;
    if (n == 1) ans += last;
    for (int i = 2; i <= n; i++) {
      cin >> x;
      if (last > 0 and x > 0) {
        last = max(last, x);
        if (i == n) {
          ans += last;
        }
      } else if (last > 0 and x < 0) {
        ans += last;
        last = x;
        if (i == n) ans += last;
      } else if (last < 0 and x < 0) {
        last = max(last, x);
        if (i == n) {
          ans += last;
        }
      } else if (last < 0 and x > 0) {
        ans += last;
        last = x;
        if (i == n) ans += last;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
