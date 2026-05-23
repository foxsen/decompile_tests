#include <bits/stdc++.h>
using namespace std;
const int N = 500, K = 16;
const int b[4] = {8, 4, 2, 1};
const int kx[4] = {0, 0, 1, 1};
const int ky[4] = {0, 1, 0, 1};
int n, m;
bool dp[10][K][N][N];
int sum[N][N];
char c;
bool a[N][N];
int getsum(int x, int y) { return ((x >= 0 && y >= 0) ? sum[x][y] : 0); }
bool is_black(int lx, int ly, int rx, int ry) {
  int a = getsum(rx, ry);
  int b = getsum(lx - 1, ry);
  int c = getsum(rx, ly - 1);
  int d = getsum(lx - 1, ly - 1);
  int sum2 = (rx - lx + 1) * (ry - ly + 1);
  return (a - b - c + d) == sum2;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> c;
      a[i][j] = (c == '*');
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      sum[i][j] = (i > 0 ? sum[i - 1][j] : 0) + (j > 0 ? sum[i][j - 1] : 0) -
                  ((i > 0 && j > 0) ? sum[i - 1][j - 1] : 0) + a[i][j];
  for (int mask = 0; mask < K; mask++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) dp[0][mask][i][j] = (a[i][j] == 0);
  for (int st = 1; st < 10; st++) {
    int w = (1 << (st - 1));
    if (2 * w > min(n, m)) continue;
    for (int mask = 0; mask < K; mask++)
      for (int i = 0; i + 2 * w <= n; i++)
        for (int j = 0; j + 2 * w <= m; j++) {
          bool f = true;
          for (int q = 0; q < 4; q++) {
            int tx = i + kx[q] * w, ty = j + ky[q] * w;
            if (mask & b[q])
              f &= is_black(tx, ty, tx + w - 1, ty + w - 1);
            else
              f &= dp[st - 1][mask][tx][ty];
          }
          dp[st][mask][i][j] = f;
        }
  }
  int ans = 0;
  for (int st = 2; st < 10; st++)
    for (int mask = 0; mask < K; mask++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (dp[st][mask][i][j]) {
            ans += dp[st][mask][i][j];
          }
  cout << ans;
  return 0;
}
