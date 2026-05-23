#include <bits/stdc++.h>
using namespace std;
int n;
double f[2][2600], g[2][2600], ans;
struct q {
  double x, y;
} a[2600];
double dis(q a, q b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &a[i].x, &a[i].y);
  }
  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n; i++) {
      f[j % 2][i] =
          max(f[(j - 1) % 2][(i + 1) % n] + dis(a[i], a[(i + 1) % n]),
              g[(j - 1) % 2][(i + j) % n] + dis(a[i], a[(i + j) % n]));
      g[j % 2][i] =
          max(g[(j - 1) % 2][(i - 1 + n) % n] + dis(a[i], a[(i - 1 + n) % n]),
              f[(j - 1) % 2][(i - j + n) % n] + dis(a[i], a[(i - j + n) % n]));
    }
  }
  for (int i = 0; i < n; i++)
    ans = max(ans, max(f[(n - 1) % 2][i], g[(n - 1) % 2][i]));
  printf("%.10lf\n", ans);
}
