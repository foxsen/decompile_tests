#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> DP(n + 1, vector<int>(k + 1, 0));
  for (int i = 1; i <= n; i++) DP[i][1] = 1;
  for (int j = 1; j < k; j++)
    for (int i = 1; i <= n; i++)
      for (int t = 1; t * i <= n; t++)
        DP[i * t][j + 1] = (DP[i * t][j + 1] + DP[i][j]) % MOD;
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + DP[i][k]) % MOD;
  cout << ans << endl;
}
