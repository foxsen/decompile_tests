#include <bits/stdc++.h>
using namespace std;
long long dp[5050][5005];
int q[2102100];
long long a[2100210];
int main() {
  int n, k, s;
  cin >> n >> k >> s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= s; j++) dp[i][j] = -1111111111111111;
  }
  dp[0][0] = 0;
  for (int j = 1; j <= s; j++) {
    int l = 0, r = 1;
    q[0] = 0;
    for (int i = 1; i <= n; i++) {
      while (l < r && q[l] < i - k) l++;
      dp[i][j] = dp[q[l]][j - 1] + a[i];
      while (l < r && dp[q[r - 1]][j - 1] <= dp[i][j - 1]) r--;
      q[r++] = i;
    }
  }
  long long maxx = -1111111111111111;
  for (int i = n - k + 1; i <= n; i++) {
    maxx = max(maxx, dp[i][s]);
  }
  if (maxx < 0) {
    cout << "-1" << endl;
    return 0;
  }
  cout << maxx << endl;
}
