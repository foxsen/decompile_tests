#include <bits/stdc++.h>
using namespace std;
const int N = 10 + 22;
int n;
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int dis[N][N], a[N][N];
pair<int, int> pos[N * N];
pair<int, int> dp[N][N][3];
pair<int, int> operator+(pair<int, int> p1, pair<int, int> p2) {
  return {p1.first + p2.first, p1.second + p2.second};
}
bool valid(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < n); }
void bfs(int x, int y, int xx, int yy) {
  memset((dis), 63, sizeof(dis));
  queue<pair<int, pair<int, int> > > q;
  q.push({0, {xx, yy}});
  dis[xx][yy] = 0;
  int px = xx, py = yy;
  while (!q.empty()) {
    pair<int, int> p = (q.front()).second;
    q.pop();
    xx = p.first, yy = p.second;
    if (dis[xx][yy] == 8) continue;
    for (int i = 0; i < (8); i++) {
      int x1 = dx[i] + xx, ajab = dy[i] + yy;
      if (!valid(x1, ajab)) continue;
      if (dis[x1][ajab] > dis[xx][yy] + 1) {
        dis[x1][ajab] = dis[xx][yy] + 1;
        q.push({dis[x1][ajab], {x1, ajab}});
      }
    }
  }
  if (dis[x][y] != dis[N - 1][N - 1])
    dp[x][y][2] = min(dp[x][y][2], dp[px][py][2] + make_pair(dis[x][y], 0));
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int x, y;
  pair<int, int> ans = {-1, -1};
  memset((dp), 63, sizeof(dp));
  pair<int, int> z = {0, 0};
  cin >> n;
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (n); j++)
      cin >> a[i][j], a[i][j]--, pos[a[i][j]] = {i, j};
  for (int i = 0; i < (n * n); i++) {
    pair<int, int> p = pos[i];
    x = p.first, y = p.second;
    int xx = z.first, yy = z.second;
    if (!i) {
      dp[x][y][0] = dp[x][y][1] = dp[x][y][2] = {0, 0};
    } else {
      if (p.first == z.first || p.second == z.second)
        dp[x][y][0] = dp[xx][yy][0] + make_pair(1, 0);
      else
        dp[x][y][0] = dp[xx][yy][0] + make_pair(2, 0);
      if ((x + y) % 2 == (xx + yy) % 2) {
        if (abs(x - xx) == abs(y - yy))
          dp[x][y][1] = dp[xx][yy][1] + make_pair(1, 0);
        else
          dp[x][y][1] = dp[xx][yy][1] + make_pair(2, 0);
      } else {
        int x3, y3;
        for (int j = 0; j < (8); j++) {
          x3 = xx + dx[j];
          y3 = yy + dy[j];
          if (!valid(x3, y3)) continue;
          if ((x + y) % 2 == (x3 + y3) % 2) {
            if (abs(x - x3) == abs(y - y3))
              dp[x][y][1] = dp[xx][yy][2] + make_pair(3, 1);
          }
        }
        for (int j = 0; j < (8); j++) {
          x3 = x + dx[j];
          y3 = y + dy[j];
          if (!valid(x3, y3)) continue;
          if ((xx + yy) % 2 == (x3 + y3) % 2) {
            if (abs(xx - x3) == abs(yy - y3))
              dp[x][y][2] = dp[xx][yy][1] + make_pair(3, 1);
          }
        }
      }
      bfs(x, y, xx, yy);
      pair<int, int> mn = {10000000, 10000000};
      for (int j = 0; j < (3); j++) mn = min(mn, dp[x][y][j]);
      mn.first++, mn.second++;
      for (int j = 0; j < (3); j++) dp[x][y][j] = min(dp[x][y][j], mn);
      ans = mn;
    }
    z = p;
  }
  cout << ans.first - 1 << " " << ans.second - 1 << endl;
  return 0;
}
