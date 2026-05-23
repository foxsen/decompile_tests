#include <bits/stdc++.h>
using namespace std;
void addmod(long long int &a, long long int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  if (a < 0) a += 1000000007;
}
void multmod(long long int &a, long long int b) {
  a *= b;
  a %= 1000000007;
}
long long int solve(int x, int y, int k) {
  if (x < 0 || y < 0 || k < 0) {
    return 0;
  }
  long long int dp[31 + 1][2][2][2];
  long long int sum[31 + 1][2][2][2];
  memset(dp, 0, sizeof(dp));
  memset(sum, 0, sizeof(sum));
  int xb[31], yb[31], kb[31];
  for (int i = 0; i < 31; i++) {
    xb[i] = x & 1;
    yb[i] = y & 1;
    kb[i] = k & 1;
    x >>= 1;
    y >>= 1;
    k >>= 1;
  }
  reverse(xb, xb + 31);
  reverse(yb, yb + 31);
  reverse(kb, kb + 31);
  dp[0][1][1][1] = 1;
  sum[0][1][1][1] = 0;
  for (int i = 0; i < 31; i++) {
    for (int preI = 0; preI < 2; preI++) {
      for (int preJ = 0; preJ < 2; preJ++) {
        for (int preK = 0; preK < 2; preK++) {
          for (int xBit = 0; xBit < 2; xBit++) {
            for (int yBit = 0; yBit < 2; yBit++) {
              int val = xBit ^ yBit;
              if (preI == 1 && xb[i] == 0 && xBit == 1) continue;
              if (preJ == 1 && yb[i] == 0 && yBit == 1) continue;
              if (preK == 1 && kb[i] == 0 && val == 1) continue;
              int npreI = preI & (xb[i] == xBit);
              int npreJ = preJ & (yb[i] == yBit);
              int npreK = preK & (kb[i] == val);
              addmod(dp[i + 1][npreI][npreJ][npreK], dp[i][preI][preJ][preK]);
              addmod(sum[i + 1][npreI][npreJ][npreK], sum[i][preI][preJ][preK]);
              long long int bmult = val << (31 - i - 1);
              multmod(bmult, dp[i][preI][preJ][preK]);
              addmod(sum[i + 1][npreI][npreJ][npreK], bmult);
            }
          }
        }
      }
    }
  }
  long long int ans = 0;
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      for (int c = 0; c < 2; c++) {
        addmod(ans, sum[31][a][b][c]);
        addmod(ans, dp[31][a][b][c]);
      }
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    x1--;
    y1--;
    x2--;
    y2--;
    k--;
    long long int ans = solve(x2, y2, k);
    addmod(ans, -solve(x1 - 1, y2, k));
    addmod(ans, -solve(x2, y1 - 1, k));
    addmod(ans, solve(x1 - 1, y1 - 1, k));
    cout << ans << endl;
  }
  return 0;
}
