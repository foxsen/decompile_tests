#include <bits/stdc++.h>
using namespace std;
char a[300005];
int main() {
  scanf("%s", a + 1);
  int n = strlen(a + 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int nl = min(i + 12, n + 1);
    ans += (n + 1 - nl);
    int fl = 0;
    for (int j = i; j < nl; j++) {
      int fl = 0;
      for (int k = i; k <= j; k++) {
        if (fl) break;
        for (int s = 1; s <= min(k - i, j - k); s++)
          if (a[k] == a[k - s] && a[k] == a[k + s]) {
            fl = 1;
            break;
          }
      }
      ans += fl;
    }
  }
  cout << ans << endl;
  return 0;
}
