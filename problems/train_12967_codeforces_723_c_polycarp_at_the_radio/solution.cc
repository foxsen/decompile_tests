#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[2010];
int cot[2010];
int main() {
  while (~scanf("%d%d", &n, &m)) {
    memset(cot, 0, sizeof(cot));
    int ans = n / m, ansc = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      if (a[i] <= m) cot[a[i]]++;
    }
    for (int i = 1; i <= m; i++) {
      if (cot[i] < n / m) {
        for (int j = 1; j <= n; j++) {
          if (i == a[j]) continue;
          if (a[j] > m) {
            a[j] = i;
            cot[i]++;
            ansc++;
          } else if (cot[a[j]] > n / m) {
            cot[i]++;
            cot[a[j]]--;
            a[j] = i;
            ansc++;
          }
          if (cot[i] >= n / m) break;
        }
      }
    }
    printf("%d %d\n", ans, ansc);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
  }
  return 0;
}
