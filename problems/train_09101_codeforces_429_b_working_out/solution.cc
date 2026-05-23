#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long mp[n + 1][m + 1], dp1[n + 2][m + 2], dp2[n + 2][m + 2],
      dp3[n + 2][m + 2], dp4[n + 2][m + 2];
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      cin >> mp[i][j];
    }
  }
  memset(dp1, 0, sizeof(dp1));
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + mp[i][j];
    }
  }
  memset(dp2, 0, sizeof(dp2));
  for (long long i = n; i > 0; i--) {
    for (long long j = m; j > 0; j--) {
      dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + mp[i][j];
    }
  }
  memset(dp3, 0, sizeof(dp3));
  for (long long i = n; i > 0; i--) {
    for (long long j = 1; j < m + 1; j++) {
      dp3[i][j] = max(dp3[i + 1][j], dp3[i][j - 1]) + mp[i][j];
    }
  }
  memset(dp4, 0, sizeof(dp4));
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = m; j > 0; j--) {
      dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + mp[i][j];
    }
  }
  long long res = 0;
  for (long long i = 2; i < n; i++) {
    for (long long j = 2; j < m; j++) {
      res = max(
          res,
          max(dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1],
              dp3[i + 1][j] + dp4[i - 1][j] + dp1[i][j - 1] + dp2[i][j + 1]));
    }
  }
  cout << res << endl;
  return 0;
}
