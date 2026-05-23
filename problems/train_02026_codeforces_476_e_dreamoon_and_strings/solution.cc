#include <bits/stdc++.h>
using namespace std;
string s;
string p;
int a[2005];
int A[2005];
int ans[2005];
int dp[2005][2005];
int main() {
  cin >> s >> p;
  memset(a, -1, sizeof(a));
  a[0] = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = p.size() - 1; j >= 0; j--) {
      if (s[i] == p[j]) a[j + 1] = a[j];
    }
    a[0] = i + 1;
    A[i + 1] = a[p.size()];
  }
  for (int i = 1; i <= s.size(); i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = dp[i - 1][j];
      if (A[i] >= 0 && j - (i - A[i] - p.size()) >= 0 &&
          j - (i - A[i] - p.size()) <= A[i])
        dp[i][j] = max(dp[A[i]][j - (i - A[i] - p.size())] + 1, dp[i][j]);
    }
  }
  for (int i = 0; i <= s.size(); i++) ans[i] = dp[s.size()][i];
  for (int i = 0; i <= s.size(); i++) cout << ans[i] << " ";
  return 0;
}
