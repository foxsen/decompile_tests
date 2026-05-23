#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-8;
int tot = 0;
int cnt[8];
int lvl[8];
int loy[8];
int n, k, A;
double ans = 0;
void gao() {
  double curWin = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int winnum = 0;
    double B = 0;
    double pers = 1;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        ++winnum;
        pers *= 1.0 * loy[i] / 100;
      } else {
        B += lvl[i];
        pers *= 1 - 1.0 * loy[i] / 100;
      }
    }
    if (winnum <= n - winnum) {
      curWin += 1.0 * pers * A / (A + B);
    } else
      curWin += pers;
  }
  if (curWin > ans) ans = curWin;
}
void dfs(int p, int left) {
  if (p == n - 1) {
    left = min(left, (100 - loy[p]) / 10);
    loy[p] += left * 10;
    gao();
    loy[p] -= left * 10;
  } else {
    for (int i = 0; i <= left && loy[p] + i * 10 <= 100; ++i) {
      loy[p] += i * 10;
      dfs(p + 1, left - i);
      loy[p] -= i * 10;
    }
  }
}
int main(int argc, char *argv[]) {
  scanf("%d%d%d", &n, &k, &A);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &lvl[i], &loy[i]);
  }
  dfs(0, k);
  printf("%.6lf\n", ans);
  return 0;
}
