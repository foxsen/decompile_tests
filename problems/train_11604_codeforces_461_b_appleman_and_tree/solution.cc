#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, N_MAX = 1e5;
int n;
vector<int> gr[N_MAX + 2];
bool col[N_MAX + 2];
int dp[N_MAX + 2][2];
void dfs(int arg) {
  dp[arg][0] = !col[arg];
  dp[arg][1] = col[arg];
  for (auto it : gr[arg]) {
    dfs(it);
    int aux0 = dp[arg][0], aux1 = dp[arg][1];
    dp[arg][0] = (1LL * aux0 * dp[it][0] + 1LL * aux0 * dp[it][1]) % MOD;
    dp[arg][1] = (1LL * aux0 * dp[it][1] + 1LL * aux1 * dp[it][0] +
                  1LL * aux1 * dp[it][1]) %
                 MOD;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    gr[x].push_back(i);
  }
  for (int i = 0; i < n; i++) cin >> col[i];
  dfs(0);
  cout << dp[0][1];
  return 0;
}
