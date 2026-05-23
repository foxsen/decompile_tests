#include <bits/stdc++.h>
using namespace std;
int a[200], ans[200];
int v[1000001];
int main() {
  int T, n;
  cin >> T;
  while (T--) {
    memset(v, 0, sizeof v);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) v[a[j] - a[i]] = 1;
    }
    memset(ans, 0, sizeof ans);
    ans[1] = 1;
    int len = 2;
    for (int j = 1; j <= 1e6; j++) {
      int tag = 1;
      for (int k = 1; k < len; k++) {
        if (v[j - ans[k]]) {
          tag = 0;
          break;
        }
      }
      if (tag) ans[len++] = j;
      if (len > n) break;
    }
    int tag = 1;
    for (int i = 1; i <= n; i++)
      if (ans[i] == 0) tag = 0;
    if (tag) {
      puts("YES");
      for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
    } else
      puts("NO");
  }
  return 0;
}
