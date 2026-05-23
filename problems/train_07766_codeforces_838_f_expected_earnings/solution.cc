#include <bits/stdc++.h>
using namespace std;
inline double max(double x, double y) { return x > y ? x : y; }
int n;
double p[2][10005], dp[2][10005], c;
int main() {
  scanf("%d%lf", &n, &c);
  c /= 1e6;
  for (int i = 0; i <= n; i++) scanf("%lf", &p[n % 2][i]), p[n % 2][i] /= 1e6;
  for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j <= i; j++) {
      double nw1 = (1.0 * (j + 1) / (i + 1)) * p[(i & 1) ^ 1][j + 1],
             nw2 = (1.0 - 1.0 * j / (i + 1)) * p[(i & 1) ^ 1][j], q;
      p[(i & 1)][j] = nw1 + nw2;
      if (p[(i & 1)][j] < 1e-18) continue;
      q = p[(i & 1) ^ 1][j + 1] * (j + 1) / p[(i & 1)][j] / (i + 1);
      dp[(i & 1)][j] = max(0.0, dp[(i & 1) ^ 1][j] * (1 - q) +
                                    (dp[(i & 1) ^ 1][j + 1] + 1) * q - c);
    }
  printf("%.10f", dp[0][0]);
}
