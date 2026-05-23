#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
const long long inf = 1e18;
int n, m, len;
long long k;
int d[maxn * maxn];
vector<int> prt;
bool mark[2 * maxn];
char S[2 * maxn];
long long dp[2 * maxn][2 * maxn];
char ans[maxn][maxn];
long long cal() {
  dp[len][0] = 1;
  for (int i = len - 1; i >= 0; i--) {
    for (int j = 0; j <= len / 2; j++) {
      int o_cnt = (i + j) / 2;
      int c_cnt = i - o_cnt;
      bool fg_o = false, fg_c = false;
      if (S[i] == ')')
        fg_c = true;
      else if (S[i] == '(')
        fg_o = true;
      if (o_cnt == len / 2)
        fg_c = true;
      else if (c_cnt == len / 2)
        fg_o = true;
      if (!j) fg_o = true;
      if (fg_o and fg_c)
        dp[i][j] = 0;
      else if (fg_o)
        dp[i][j] = dp[i + 1][j + 1];
      else if (fg_c)
        dp[i][j] = dp[i + 1][j - 1];
      else if (dp[i + 1][j + 1] > inf - dp[i + 1][j - 1])
        dp[i][j] = inf;
      else
        dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j - 1];
    }
  }
  return dp[0][0];
}
int main() {
  cin >> n >> m >> k;
  len = n + m - 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      d[a] = i + j;
    }
  for (int i = 1; i <= n * m; i++) {
    if (!mark[d[i]]) {
      mark[d[i]] = true;
      prt.push_back(d[i]);
    }
  }
  long long last = 0;
  for (int i = 0; i < len; i++) {
    S[prt[i]] = '(';
    long long x = cal();
    if (last + x < k) {
      S[prt[i]] = ')';
      last += x;
    }
  }
  for (int i = 0; i < len; i++)
    for (int j = 0; j <= min(i, n - 1); j++)
      if (i - j < m) ans[j][i - j] = S[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << ans[i][j];
    cout << '\n';
  }
}
