#include <bits/stdc++.h>
using namespace std;
int n, m, ls[20], pref[20];
long long y, dp[100000];
long long count() {
  fill(dp, dp + (1 << n), 0);
  dp[0] = 1;
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (dp[mask] == 0) continue;
    int cnt = 0, tmp = mask;
    while (tmp > 0) {
      if (tmp & 1 == 1) cnt++;
      tmp /= 2;
    }
    for (int i = 0; i < n; i++)
      if ((pref[i] == -1 || pref[i] == n - cnt - 1) &&
          ((ls[i] & mask) == ls[i]) && ((mask & (1 << i)) == 0))
        dp[mask | (1 << i)] += dp[mask];
  }
  return dp[(1 << n) - 1];
}
int main() {
  cin >> n >> y >> m;
  y -= 2000;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    ls[u - 1] |= 1 << (v - 1);
  }
  fill(pref, pref + n, -1);
  for (int i = 0; i < n; i++) {
    for (;;) {
      pref[i]++;
      if (pref[i] == n) {
        cout << "The times have changed" << endl;
        return 0;
      }
      long long tmp = count();
      if (tmp < y)
        y -= tmp;
      else
        break;
    }
  }
  for (int i = 0; i < n; i++) cout << pref[i] + 1 << " ";
  cout << endl;
  return 0;
}
