#include <bits/stdc++.h>
using namespace std;
int ara[300000], kk[300000], last[4], nexto[300000], c, d, n;
long long dp[300000][2][2];
long long dp_func(int pos, int f, int s) {
  if (pos == n + 1) {
    return 0;
  }
  if (dp[pos][f][s] != -1) return dp[pos][f][s];
  long long ret = 1LL << 55;
  if (kk[pos] == 0) {
    ret = min(ret, dp_func(pos + 1, 1, 0) + 1LL * (nexto[pos] - ara[pos]) * c);
    if (s == 0) ret = min(ret, dp_func(pos + 1, f, 0) + d);
  }
  if (kk[pos] == 1) {
    ret = min(ret, dp_func(pos + 1, 0, 1) + 1LL * (nexto[pos] - ara[pos]) * c);
    if (f == 0) ret = min(ret, dp_func(pos + 1, 0, s) + d);
  }
  return dp[pos][f][s] = ret;
}
int main() {
  int i, j, k, l, m;
  scanf("%d%d%d", &n, &c, &d);
  char str[4];
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    scanf("%d%s", &ara[i], str);
    kk[i] = 0;
    if (str[0] == 'P') kk[i] = 1;
  }
  scanf("%d", &ara[n + 1]);
  last[0] = last[1] = ara[n + 1];
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    nexto[i] = last[kk[i] ^ 1];
    last[kk[i]] = ara[i];
  }
  ans = dp_func(1, 0, 0);
  cout << ans << endl;
}
