#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, a[3505], uncontrolled, mi, ans;
int main() {
  cin >> t;
  while (t--) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    uncontrolled = m - k - 1;
    if (uncontrolled > 0) {
      ans = 0;
      for (int i = 0; i <= k; i++) {
        mi = 2000000000;
        for (int j = 0; j <= uncontrolled; j++) {
          mi = min(mi, max(a[i + j + 1], a[n - k - uncontrolled + i + j]));
        }
        ans = max(ans, mi);
      }
      printf("%d\n", ans);
    } else {
      ans = 0;
      for (int i = 1; i <= m; i++) ans = max(ans, a[i]);
      for (int i = n; i >= n - m + 1; i--) ans = max(ans, a[i]);
      printf("%d\n", ans);
    }
  }
}
