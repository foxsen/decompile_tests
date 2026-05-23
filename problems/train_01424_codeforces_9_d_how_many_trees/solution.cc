#include <bits/stdc++.h>
using namespace std;
long long f[505][505];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; i++) f[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k < j; k++) {
        (f[j][i] += f[k][i - 1] * f[j - k - 1][i - 1]);
      }
    }
  }
  printf("%lld", f[n][n] - f[n][k - 1]);
  return 0;
}
