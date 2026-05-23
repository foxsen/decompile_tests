#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const long long mod = 1000000007;
const int maxn = 200010;
const double PI = acos(-1.0);
int n, q, ans;
int dp[150][100];
char chan[50][10], x[50][10];
int dfs(char a, int len) {
  if (dp[a][n - len] != -1) {
    return dp[a][n - len];
  }
  if (len == n) {
    return 1;
  }
  int i, j, k;
  long long res = 0;
  for (i = 0; i < q; i++) {
    if (x[i][0] == a) {
      char xx = chan[i][0];
      res += dfs(chan[i][0], len + 1);
    }
  }
  dp[a][n - len] = res;
  return dp[a][n - len];
}
void solve() {
  int i, j, k;
  scanf("%d%d", &n, &q);
  memset(dp, -1, sizeof(dp));
  for (i = 0; i < q; i++) {
    cin >> chan[i] >> x[i];
  }
  ans = 0;
  cout << dfs('a', 1);
}
int main() {
  solve();
  return 0;
}
