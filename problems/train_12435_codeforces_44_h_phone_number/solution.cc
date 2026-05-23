#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e8;
long long int power(long long int a, long long int n) {
  unsigned long long int result = 1, x = a;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % MOD;
    x = (x * x) % MOD;
    n = n / 2;
  }
  return result;
}
long long int GCD(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    long long int ans = 0;
    for (int i = 0; i <= 9; i++) {
      int dp[n][10];
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 10; k++) dp[j][k] = 0;
      }
      dp[0][i] = 1;
      for (int j = 1; j < n; j++) {
        int num2 = s[j] - '0';
        for (int k = 0; k < 10; k++) {
          if ((num2 + k) % 2) {
            int num30 = (num2 + k) / 2;
            int num31 = num30 + 1;
            dp[j][num30] += (dp[j - 1][k]);
            dp[j][num31] += (dp[j - 1][k]);
          } else {
            int num3 = (num2 + k) / 2;
            dp[j][num3] += (dp[j - 1][k]);
          }
        }
      }
      for (int j = 0; j < 10; j++) ans += dp[n - 1][j];
    }
    int num1 = s[0] - '0';
    for (int i = 1; i < n; i++) {
      int num2 = s[i] - '0';
      if (num1 == num2 || num1 + 1 == num2 || num1 - 1 == num2) {
        num1 = num2;
        continue;
      }
      cout << ans << endl;
      return 0;
    }
    cout << ans - 1 << endl;
  }
  return 0;
}
