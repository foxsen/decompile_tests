#include <bits/stdc++.h>
using namespace std;
const int nMax = 1003;
int dp1[nMax][nMax];
int dp2[nMax][nMax];
int dp3[nMax][nMax];
int dp4[nMax][nMax];
int a[nMax][nMax];
int main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + a[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + a[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      dp3[i][j] = max(dp3[i + 1][j], dp3[i][j - 1]) + a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + a[i][j];
    }
  }
  long long ans = 0;
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < m; j++) {
      ans = max(ans, 1LL * dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] +
                         dp4[i][j + 1]);
      ans = max(ans, 1LL * dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] +
                         dp4[i - 1][j]);
    }
  }
  cout << ans << "\n";
  return 0;
}
