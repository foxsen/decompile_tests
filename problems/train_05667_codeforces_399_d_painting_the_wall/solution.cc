#include <bits/stdc++.h>
bool r[2222], c[2222];
int nr, nc;
int n, m;
double f[2222][2222];
void init(void) {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < (m); i = i + 1) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    r[x] = true;
    c[y] = true;
  }
  for (int i = (1); i <= (n); i = i + 1) {
    if (r[i]) nr++;
    if (c[i]) nc++;
  }
}
void optimize(void) {
  f[n][n] = 0.0;
  for (int i = (n); i >= (0); i = i - 1)
    for (int j = (n); j >= (0); j = j - 1)
      if (i < n || j < n)
        f[i][j] = 1.0 *
                  (i * (n - j) * f[i][j + 1] + (n - i) * j * f[i + 1][j] +
                   (n - i) * (n - j) * f[i + 1][j + 1] + n * n) /
                  (n * n - i * j);
  printf("%.9lf", f[nr][nc]);
}
int main(void) {
  init();
  optimize();
  return 0;
}
