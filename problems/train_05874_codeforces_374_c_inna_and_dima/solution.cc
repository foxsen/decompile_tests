#include <bits/stdc++.h>
using namespace std;
const int MAX = 1002;
string str[MAX];
int n, m, dp[MAX][MAX], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1},
                        vis[MAX][MAX], cur[MAX][MAX];
char next(char a) {
  if (a == 'D') return 'I';
  if (a == 'I') return 'M';
  if (a == 'M') return 'A';
  return 'D';
}
bool valid(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }
void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int sx = x + dx[i], sy = y + dy[i];
    if (not valid(sx, sy) or str[sx][sy] != next(str[x][y])) continue;
    if (vis[sx][sy]) {
      if (cur[sx][sy]) {
        cout << "Poor Inna!" << endl;
        exit(0);
      }
    } else {
      vis[sx][sy] = cur[sx][sy] = 1;
      dfs(sx, sy);
    }
    dp[x][y] = max(dp[x][y], 1 + dp[sx][sy]);
    cur[sx][sy] = 0;
  }
  dp[x][y] = max(dp[x][y], 1);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> str[i];
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (str[i][j] == 'D' and not vis[i][j]) {
        vis[i][j] = cur[i][j] = 1, dfs(i, j);
        cur[i][j] = 0;
        ans = max(ans, dp[i][j]);
      }
    }
  if (ans / 4 == 0)
    cout << "Poor Dima!" << endl;
  else
    cout << ans / 4 << endl;
  return 0;
}
