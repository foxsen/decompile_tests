#include <bits/stdc++.h>
using namespace std;
int n;
string s;
long long w[20], dp[20][20];
int main() {
  cin >> n >> s;
  w[0] = 1;
  for (int i = 1; i <= n; i++) w[i] = w[i - 1] * 10;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) {
      int x = s[2 * n - (i + j)] - '0';
      if (i > 0) dp[i][j] = dp[i - 1][j] + x * w[i - 1];
      if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + x * w[j - 1]);
    }
  int i = n, j = n;
  while (i > 0 || j > 0) {
    int x = s[2 * n - (i + j)] - '0';
    if (i > 0 && dp[i][j] == dp[i - 1][j] + x * w[i - 1]) {
      cout << 'H';
      i--;
    } else {
      cout << 'M';
      j--;
    }
  }
  cout << '\n';
  return 0;
}
