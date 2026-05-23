#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int x, k, P;
double p, pp;
double f[N][N];
int main() {
  scanf("%d %d %lf", &x, &k, &p);
  p = p * 1.0 / 100.0, pp = 1.0 - p;
  for (int i = 0; i <= k; i++)
    for (int j = x + i; j % 2 == 0; j >>= 1) f[0][i]++;
  for (int i = 0; i < k; i++)
    for (int j = 0; j <= k; j++) {
      if (j) f[i + 1][j - 1] = f[i + 1][j - 1] + pp * f[i][j];
      if (j * 2 <= k) f[i + 1][j * 2] = f[i + 1][j * 2] + p * (f[i][j] + 1);
    }
  printf("%.10lf", f[k][0]);
  return 0;
}
