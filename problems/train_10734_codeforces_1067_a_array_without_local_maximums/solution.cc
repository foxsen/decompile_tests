#include <bits/stdc++.h>
using namespace std;
const int M = 201, mod = 998244353;
int dp[M][2], ndp[M][2];
void modAdd(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  memset(dp, 0, sizeof(dp));
  dp[0][1] = 1;
  for (int a, i = 0; i < n; i++) {
    cin >> a;
    memset(ndp, 0, sizeof(ndp));
    if (a == -1) {
      int lessSum = (dp[0][0] + dp[0][1]) % mod;
      int greaterEqualSum = 0;
      for (int x = 1; x < M; x++) {
        modAdd(greaterEqualSum, dp[x][1]);
      }
      for (int x = 1; x < M; x++) {
        modAdd(greaterEqualSum, dp[x][0]);
        modAdd(ndp[x][0], lessSum);
        modAdd(ndp[x][1], greaterEqualSum);
        modAdd(lessSum, dp[x][0]);
        modAdd(lessSum, dp[x][1]);
        modAdd(greaterEqualSum, mod - dp[x][0]);
        modAdd(greaterEqualSum, mod - dp[x][1]);
      }
    } else {
      for (int y = 0; y < 2; y++) {
        for (int x = 0; x <= (y == 1 ? M - 1 : a); x++) {
          modAdd(ndp[a][x >= a], dp[x][y]);
        }
      }
    }
    memcpy(dp, ndp, sizeof(dp));
  }
  int res = 0;
  for (int x = 1; x < M; x++) {
    modAdd(res, dp[x][1]);
  }
  cout << res << '\n';
}
