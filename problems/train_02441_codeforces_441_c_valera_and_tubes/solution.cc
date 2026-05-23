#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int x[N * N], y[N * N], tot;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    if (i & 1)
      for (int j = 1; j <= m; j++) x[++tot] = i, y[tot] = j;
    else
      for (int j = m; j >= 1; j--) x[++tot] = i, y[tot] = j;
  }
  for (int i = 1; i < k; i++)
    printf("2 %d %d %d %d\n", x[2 * i - 1], y[2 * i - 1], x[2 * i], y[2 * i]);
  printf("%d ", n * m - 2 * k + 2);
  for (int i = 2 * k - 1; i <= n * m; i++) printf("%d %d ", x[i], y[i]);
}
