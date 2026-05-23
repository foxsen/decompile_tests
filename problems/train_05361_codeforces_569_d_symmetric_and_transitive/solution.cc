#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
int c[4040][4040];
long long f[4040], g[4040], k[4040];
int i, j, n;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
  }
  g[0] = g[1] = 1;
  for (i = 2; i <= n; i++) {
    g[i] = g[i - 1];
    for (j = 1; j <= i - 1; j++) g[i] = (g[i] + c[i - 1][j] * g[i - 1 - j]) % P;
  }
  k[0] = 1;
  for (i = 1; i <= n; i++) {
    k[i] = 1;
    for (j = 1; j <= i; j++) k[i] = (k[i] + g[j] * c[i][j]) % P;
  }
  f[1] = 1;
  for (i = 2; i <= n; i++) {
    f[i] = f[i - 1] + k[i - 1];
    for (j = 1; j <= i - 2; j++) f[i] = (f[i] + f[i - j - 1] * c[i - 1][j]) % P;
  }
  printf("%d\n", f[n]);
}
