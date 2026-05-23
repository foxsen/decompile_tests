#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
double t[maxn], v[maxn];
double ans[maxn];
int n, m;
double a, d;
const double INF = 1e9 + 7;
int main() {
  scanf("%d%lf%lf", &n, &a, &d);
  t[0] = 0, v[0] = INF;
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &t[i], &v[i]);
    if (v[i] * v[i] >= 2 * a * d) {
      ans[i] = sqrt(2 * d / a) + t[i];
    } else {
      double tt = v[i] * v[i] / (2 * a);
      double tx = tt;
      tt = d - tt;
      ans[i] = tt / v[i] + sqrt(2 * tx / a) + t[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    ans[i] = max(ans[i], ans[i - 1]);
    printf("%.10f\n", ans[i]);
  }
}
