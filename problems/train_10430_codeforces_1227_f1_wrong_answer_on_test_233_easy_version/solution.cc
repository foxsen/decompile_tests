#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const long long Mod = 998244353;
long long n, m;
long long dp[N][N * 2];
int h[N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> h[i];
  dp[0][n + 1] = 1;
  for (int i = 1; i <= n; i++) {
    if (h[i] == h[i % n + 1])
      for (int j = 1; j <= 2 * n + 1; j++) dp[i][j] = dp[i - 1][j] * m % Mod;
    else
      for (int j = 1; j <= 2 * n + 1; j++)
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1] +
                    dp[i - 1][j] * (m - 2) % Mod) %
                   Mod;
  }
  long long res = 0;
  for (int i = n + 2; i <= 2 * n + 1; i++) res = (res + dp[n][i]) % Mod;
  cout << res << endl;
}
