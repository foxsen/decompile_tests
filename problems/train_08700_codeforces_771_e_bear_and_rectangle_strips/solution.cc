#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
long long sum[4][maxn];
int f[4][maxn];
map<long long, int> lst;
int n;
void init(long long *sum, int *f) {
  lst.clear();
  for (int i = 1; i <= n; ++i) sum[i] += sum[i - 1];
  lst[0] = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1];
    if (lst.count(sum[i])) f[i] = max(f[i], lst[sum[i]] + 1);
    lst[sum[i]] = i;
  }
}
int dp[maxn];
map<pair<int, int>, int> m;
int solve(int x, int y) {
  if (x < 0 || y < 0) return -inf;
  if (x == y) return dp[x];
  if (m.count(make_pair(x, y))) return m[make_pair(x, y)];
  int ret = dp[min(x, y)];
  if (x > y)
    ret = max(ret, solve(f[1][x] - 1, y) + 1);
  else
    ret = max(ret, solve(x, f[2][y] - 1) + 1);
  m[make_pair(x, y)] = ret;
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2; ++i)
    for (int j = 1; j <= n; ++j) scanf("%lld", &sum[i][j]);
  for (int j = 1; j <= n; ++j) sum[3][j] = sum[1][j] + sum[2][j];
  for (int i = 1; i <= 3; ++i) init(sum[i], f[i]);
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    if (f[3][i]) dp[i] = max(dp[i], dp[f[3][i] - 1] + 1);
    dp[i] = max(dp[i], solve(f[1][i] - 1, i) + 1);
    dp[i] = max(dp[i], solve(i, f[2][i] - 1) + 1);
  }
  printf("%d\n", dp[n]);
}
