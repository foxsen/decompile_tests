#include <bits/stdc++.h>
using namespace std;
int a[1100];
int main() {
  int n, m, h, sum, i, j;
  double ss;
  while (scanf("%d%d%d", &n, &m, &h) != EOF) {
    for (sum = 0, i = 1; i <= m; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    if (sum < n) {
      printf("-1.0\n");
      continue;
    }
    ss = 1.0;
    j = a[h];
    if (n - 1 <= sum - j) {
      for (i = 0; i < n - 1; i++)
        ss *= (double)(sum - j - i) / (double)(sum - 1 - i);
    } else
      ss = 0;
    printf("%.10lf\n", 1.0 - ss);
  }
  return 0;
}
