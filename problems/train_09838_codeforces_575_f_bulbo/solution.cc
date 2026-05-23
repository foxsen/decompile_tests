#include <bits/stdc++.h>
using namespace std;
const int maxn = 5011;
int n, xt, nn;
int a[maxn], b[maxn], c[maxn * 2];
const long long inf = 10000000000000;
long long dp[maxn * 2][2];
long long t1[maxn * 2], t2[maxn * 2];
long long ans;
int myabs(int x) {
  if (x > 0)
    return x;
  else
    return (-x);
}
int get(int xx, int t) {
  if (a[t] <= xx && xx <= b[t]) return 0;
  return min(myabs(xx - a[t]), myabs(xx - b[t]));
}
int main() {
  scanf("%d%d", &n, &xt);
  nn = 0;
  for (int i = (1); i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    c[++nn] = a[i];
    c[++nn] = b[i];
  }
  c[++nn] = xt;
  sort(c + 1, c + nn + 1);
  for (int i = (1); i <= nn; i++) {
    dp[i][1] = (long long)(fabs(c[i] - xt) + get(c[i], 1));
  }
  for (int j = (0); j <= nn + 1; j++) {
    t1[j] = inf;
    t2[j] = inf;
  }
  for (int j = (1); j <= nn; j++) {
    t1[j] = min(t1[j - 1], dp[j][1] - c[j]);
  }
  for (int j = (nn); j >= 1; j--) {
    t2[j] = min(t2[j + 1], dp[j][1] + c[j]);
  }
  for (int i = (2); i <= n; i++) {
    for (int j = (1); j <= nn; j++) dp[j][i % 2] = inf;
    for (int j = (1); j <= nn; j++) {
      dp[j][i % 2] = min(t2[j] - c[j], t1[j] + c[j]) + get(c[j], i);
    }
    for (int j = (0); j <= nn + 1; j++) {
      t1[j] = inf;
      t2[j] = inf;
    }
    for (int j = (1); j <= nn; j++) {
      t1[j] = min(t1[j - 1], dp[j][i % 2] - c[j]);
    }
    for (int j = (nn); j >= 1; j--) {
      t2[j] = min(t2[j + 1], dp[j][i % 2] + c[j]);
    }
  }
  ans = inf;
  for (int i = (1); i <= nn; i++) {
    if (dp[i][n % 2] < ans) ans = dp[i][n % 2];
  }
  printf("%I64d\n", ans);
  return 0;
}
