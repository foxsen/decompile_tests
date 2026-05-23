#include <bits/stdc++.h>
using namespace std;
const int MAX = 5010;
int main() {
  int n, T;
  scanf("%d%d", &n, &T);
  double ds1[MAX] = {};
  double ds2[MAX] = {};
  double *rs = ds1, *rs2 = ds2;
  double res[MAX] = {};
  for (int i = 0; i < n; ++i) {
    rs2[0] = i == 0;
    int P, t;
    scanf("%d%d", &P, &t);
    double sm = 0, p = P / 100., q = 1 - p;
    double qt1 = pow(q, t - 1);
    for (int j = max(i - 1, 1); j < t; ++j) {
      if (sm != 0) sm *= q;
      sm += rs2[j - 1] * p;
      rs[j] = sm;
    }
    for (int j = max(i - 1, t); j <= T; ++j) {
      if (sm != 0) sm *= q;
      sm += rs2[j - 1] * p;
      if (rs2[j - t] != 0) {
        double v = rs2[j - t] * qt1;
        sm -= rs2[j - t] * qt1 * p;
        rs[j] = sm + v;
      } else
        rs[j] = sm;
    }
    double Q = 1;
    for (int j = T; j >= T - t + 1 && j >= i; --j) {
      res[i] += rs2[j] * Q;
      Q *= q;
    }
    swap(rs, rs2);
  }
  for (int j = 1; j <= T; ++j) res[n] += rs2[j];
  double r = 0;
  for (int j = 1; j <= T; ++j) r += res[j] * j;
  printf("%.10lf\n", r);
  return 0;
}
