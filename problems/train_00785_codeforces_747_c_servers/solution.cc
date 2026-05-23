#include <bits/stdc++.h>
using namespace std;
int en[100 + 100];
int e[100 + 100];
int main() {
  int n, q;
  while (~scanf("%d%d", &n, &q)) {
    memset(en, -1, sizeof(en));
    memset(e, -1, sizeof(e));
    for (int i = 1; i <= q; i++) {
      int T, K, D;
      scanf("%d%d%d", &T, &K, &D);
      int ans = 0;
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (en[i] == -1 || en[i] < T) {
          cnt++;
          e[i] = T + D - 1;
          ans += i;
          if (cnt == K) break;
        }
      }
      if (cnt == K) {
        for (int i = 1; i <= n; i++) en[i] = e[i];
        printf("%d\n", ans);
      } else {
        for (int i = 1; i <= n; i++) e[i] = en[i];
        printf("-1\n");
      }
    }
  }
  return 0;
}
