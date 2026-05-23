#include <bits/stdc++.h>
using namespace std;
int n, q, k, a[60005], p, P;
bool u[20000005];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    u[a[i]] = 1;
  }
  scanf("%d", &q);
  while (q--) {
    int c, ans = 100;
    scanf("%d", &c);
    for (int x = 0; x <= k; ++x) {
      for (int y = 0; y <= k - x; ++y) {
        for (int i = 1; i <= n; ++i) {
          p = c - a[i] * x;
          if (p < 0) continue;
          if (p == 0)
            ans = min(ans, x + y);
          else {
            if (y != 0 && p % y == 0) {
              P = p / y;
              if (P <= a[n] && u[P]) ans = min(ans, x + y);
            }
          }
        }
      }
    }
    if (ans == 100)
      puts("-1");
    else
      printf("%d\n", ans);
  }
  return 0;
}
