#include <bits/stdc++.h>
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
const int MOD = mod - 1;
const double eps = 1e-18;
const double PI = acos(-1.0);
using namespace std;
int p[N];
double f[N][N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) f[i][j] = (p[i] > p[j]);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= n; i++) {
      if (i != a && i != b) {
        f[i][a] = f[i][b] = (f[i][a] + f[i][b]) / 2;
        f[a][i] = f[b][i] = (f[a][i] + f[b][i]) / 2;
      }
    }
    f[a][b] = f[b][a] = 0.5;
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans += f[i][j];
    }
  }
  printf("%f\n", ans);
  return 0;
}
