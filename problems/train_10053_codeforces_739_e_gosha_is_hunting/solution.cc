#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int data = 0, m = 1;
  char ch = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') {
    m = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    data = (data << 1) + (data << 3) + (ch ^ 48);
    ch = getchar();
  }
  return (m) ? data : -data;
}
const double eps = 1e-10;
const double inf = 1000000000.0;
int n, A, B;
double p[2][2005];
struct dp {
  double v;
  int c;
  bool operator<(const dp &B) const { return (v != B.v) ? v < B.v : c > B.c; }
  inline void reset() {
    v = -inf;
    c = 0;
  }
} f[2005][2005], Ans;
void Solve(double md) {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) f[i][j].reset();
  f[0][0] = (dp){0, 0};
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= A; j++)
      if (f[i][j].v != -inf) {
        if (j ^ A) {
          f[i + 1][j + 1] =
              max(f[i + 1][j + 1], (dp){f[i][j].v + p[0][i + 1], f[i][j].c});
          double c2 = 1.0 - ((1.0 - p[0][i + 1]) * (1.0 - p[1][i + 1]));
          f[i + 1][j + 1] =
              max(f[i + 1][j + 1], (dp){f[i][j].v + c2 - md, f[i][j].c + 1});
        }
        f[i + 1][j] =
            max(f[i + 1][j], (dp){f[i][j].v + p[1][i + 1] - md, f[i][j].c + 1});
        f[i + 1][j] = max(f[i + 1][j], (dp){f[i][j].v, f[i][j].c});
      }
  Ans = f[n][A];
  return;
}
int main() {
  n = gi();
  A = gi();
  B = gi();
  double l = -2.0, r = 2.0, ret = 0;
  for (int i = 0; i <= 1; i++)
    for (int j = 1; j <= n; j++) scanf("%lf", &p[i][j]);
  while (r - l > eps) {
    double mid = (l + r) * 0.5;
    Solve(mid);
    if (Ans.c <= B)
      ret = mid, r = mid - eps;
    else
      l = mid + eps;
  }
  Solve(ret);
  printf("%.10lf\n", Ans.v + 1.0 * ret * (double)B);
  return 0;
}
