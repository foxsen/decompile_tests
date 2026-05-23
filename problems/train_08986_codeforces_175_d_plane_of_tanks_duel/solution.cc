#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
int hp1, hp2;
int dt1, dt2;
int L1, R1;
int L2, R2;
double p1, p2;
double frac1, frac2;
const int MAXH = 200;
const int D = 5000;
double dp1[MAXH + 1][D + 1];
double dp2[MAXH + 1][D + 1];
double sum1[D + 1];
double sum2[D + 1];
void calcDp(int i, double dp[][D + 1], double p, double frac, int L, int R,
            double sum[]) {
  for (int j = 0; j <= MAXH; ++j) dp[j][i + 1] = 0.0;
  sum[i + 1] = 0;
  for (int j = 1; j <= MAXH; ++j) {
    if (dp[j][i] < eps) continue;
    int h = j - L;
    if (h < 0) h = 0;
    double mul = p * frac * dp[j][i];
    for (int k = L; k <= R; ++k) {
      dp[h][i + 1] += mul;
      if (h > 0) {
        sum[i + 1] += mul;
        --h;
      }
    }
    dp[j][i + 1] += (1.0 - p) * dp[j][i];
    sum[i + 1] += (1.0 - p) * dp[j][i];
  }
}
int main() {
  cout.setf(ios::fixed);
  cout.precision(9);
  int tmp;
  cin >> hp1 >> dt1 >> L1 >> R1 >> tmp;
  p1 = 1.0 - double(tmp) / 100.0;
  if (tmp == 100) {
    cout << "0.0" << endl;
    return 0;
  }
  cin >> hp2 >> dt2 >> L2 >> R2 >> tmp;
  if (tmp == 100) {
    cout << "1.0" << endl;
    return 0;
  }
  p2 = 1.0 - double(tmp) / 100.0;
  frac1 = 1.0 / double(R1 - L1 + 1.0);
  frac2 = 1.0 / double(R2 - L2 + 1.0);
  for (int i = 0; i <= MAXH; ++i) {
    dp1[i][0] = 0.0;
    dp2[i][0] = 0.0;
  }
  sum1[0] = 1.0;
  sum2[0] = 1.0;
  dp1[hp1][0] = 1.0;
  dp2[hp2][0] = 1.0;
  for (int i = 0; i < D; ++i) {
    calcDp(i, dp2, p1, frac1, L1, R1, sum2);
    calcDp(i, dp1, p2, frac2, L2, R2, sum1);
  }
  int next1 = 0;
  int next2 = 0;
  int done1 = 0;
  int done2 = 0;
  double ret = 0.0;
  while (true) {
    if (next1 <= next2) {
      if (done1 >= D) break;
      double expr = sum1[done2] * dp2[0][done1 + 1];
      ret += expr;
      ++done1;
      next1 += dt1;
    } else {
      if (done2 >= D) break;
      ++done2;
      next2 += dt2;
    }
  }
  cout << ret << endl;
  return 0;
}
