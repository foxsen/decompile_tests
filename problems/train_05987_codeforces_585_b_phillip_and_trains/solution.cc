#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int INF = 1000000007;
const int MOD = 1000000007;
const int MAXN = 100055;
int T;
vector<string> G(3);
int n, tr;
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> tr;
    for (int i = 0; i < 3; ++i) {
      cin >> G[i];
      G[i].resize(n + 3, '.');
    }
    vector<vector<bool> > dp(3, vector<bool>(n, false));
    for (int i = 0; i < 3; ++i)
      if (G[i][0] == 's') dp[i][0] = true;
    bool flag = true;
    for (int j = 0; flag && j + 1 < n; j += 3) {
      flag = false;
      for (int i = 0; i < 3; ++i) {
        if (!dp[i][j] || G[i][j + 1] != '.') continue;
        for (int k = -1; k <= 1; ++k)
          if (i + k >= 0 && i + k < 3 && G[i + k][j + 1] == '.' &&
              G[i + k][j + 2] == '.' && G[i + k][j + 3] == '.') {
            flag = true;
            dp[i + k][j + 3] = true;
          }
      }
    }
    cout << (flag ? "YES" : "NO") << endl;
  }
  return 0;
}
