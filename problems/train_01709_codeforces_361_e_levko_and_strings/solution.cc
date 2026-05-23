#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
const int N = 2005, mod = 1e9 + 7;
int dp[N][N], sum[N];
char s[N];
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  int n = read(), k = read();
  scanf("%s", s + 1);
  sum[0] = dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int l = i - 1; l >= 0 && (i - l) * (n - i + 1) <= j; --l)
        add(dp[i][j], dp[l][j - (i - l) * (n - i + 1)]);
      dp[i][j] = 1ll * ('z' - s[i]) * dp[i][j] % mod;
      add(dp[i][j], 1ll * sum[j] * (s[i] - 'a') % mod);
      add(sum[j], dp[i][j]);
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) add(ans, dp[i][k]);
  cout << ans;
  return 0;
}
