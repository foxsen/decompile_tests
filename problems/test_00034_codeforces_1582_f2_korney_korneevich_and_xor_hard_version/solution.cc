#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10, mod = 998244353;
vector<int> v[N];
int dp[N][8192];
int main() {
  int n;
  scanf("%d", &n);
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1, x; i <= n; i++) scanf("%d", &x), v[x].push_back(i);
  for (int i = 1; i <= 5e3; i++)
    for (int j = 0; j <= 8191; j++) {
      dp[i][j] = dp[i - 1][j];
      if ((j ^ i) > 8191 || !v[i].size() || v[i].back() < dp[i - 1][j ^ i])
        continue;
      dp[i][j] = min(dp[i][j],
                     *lower_bound(v[i].begin(), v[i].end(), dp[i - 1][j ^ i]));
    }
  for (int i = 0; i <= 8191; i++)
    if (dp[5000][i] != 0x3f3f3f3f) v[5001].push_back(i);
  cout << v[5001].size() << endl;
  for (auto x : v[5001]) cout << x << ' ';
  return 0;
}
