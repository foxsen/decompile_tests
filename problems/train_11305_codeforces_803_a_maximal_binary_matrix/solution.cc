#include <bits/stdc++.h>
const int MAXN = 110;
int a[MAXN][MAXN];
void solve(int n, int pos, int k) {
  if (k == 1) {
    a[pos][pos] = 1;
    return;
  }
  if (k == 0) return;
  if (k <= (n << 1) - 1) {
    for (int i = pos; i <= pos + (k - 1 >> 1); i++) a[pos][i] = a[i][pos] = 1;
    solve(n - 1, pos + 1, (k & 1) ^ 1);
  } else {
    for (int i = pos; i <= pos + n - 1; i++) a[pos][i] = a[i][pos] = 1;
    solve(n - 1, pos + 1, k - (n << 1) + 1);
  }
  return;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k > n * n) {
    puts("-1");
    return 0;
  }
  solve(n, 1, k);
  for (int i = 1; i <= n; i++, puts(""))
    for (int j = 1; j <= n; j++) printf("%d ", a[i][j]);
  return 0;
}
