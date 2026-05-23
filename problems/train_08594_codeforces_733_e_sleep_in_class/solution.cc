#include <bits/stdc++.h>
using namespace std;
int A[1000010], B[1000010];
long long f[1000010], g[1000010];
char c[1000010];
int main() {
  int n, i, j, l1 = 0, l2 = 0;
  scanf("%d", &n);
  scanf("%s", c + 1);
  for (i = 1; i <= n; i++) {
    f[i] = f[i - 1];
    if (c[i] == 'U') f[i] += 2 * i - 1;
  }
  for (i = n; i >= 1; i--) {
    g[i] = g[i + 1];
    if (c[i] == 'D') g[i] += 2 * (n - i + 1) - 1;
  }
  for (i = n; i >= 1; i--)
    if (c[i] == 'D') B[++l2] = i;
  for (i = 1; i <= n; i++) {
    if (c[i - 1] == 'U') A[++l1] = i - 1;
    if (l2 && B[l2] == i) l2--;
    if (c[i] == 'U') {
      if (l1 + 1 > l2)
        printf("%I64d ", (long long)n * (1 + 2 * l2) - (i - 1) -
                             (f[A[l1]] - f[A[l1 - l2]]) - g[B[l2]]);
      else
        printf("%I64d ", (long long)n * (2 + 2 * l1) - (i - 1) - f[A[l1]] -
                             (g[B[l2]] - g[B[l2 - l1 - 1]]));
    } else {
      if (l2 + 1 > l1)
        printf("%I64d ", (long long)n * (1 + 2 * l1) - (n - i) - f[A[l1]] -
                             (g[B[l2]] - g[B[l2 - l1]]));
      else
        printf("%I64d ", (long long)n * (2 + 2 * l2) - (n - i) -
                             (f[A[l1]] - f[A[l1 - l2 - 1]]) - g[B[l2]]);
    }
  }
  printf("\n");
  return 0;
}
