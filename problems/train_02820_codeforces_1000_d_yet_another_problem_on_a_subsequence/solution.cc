#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 7;
const int mod = 998244353;
int a[maxn], c[maxn][maxn];
long long dp[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), dp[i] = 1;
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i + a[i] <= n && a[i] > 0) {
      ans = (ans + dp[i] * c[n - i][a[i]]) % mod;
      for (int j = i + a[i]; j <= n; j++)
        dp[j + 1] = (dp[j + 1] + dp[i] * c[j - i][a[i]]) % mod;
    }
  }
  cout << ans;
  return 0;
}
