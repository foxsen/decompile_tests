#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && c != '-')
    ;
  if (c == '-') {
    c = getchar();
    nega = 1;
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
inline void update(int64_t &A, int64_t B) {
  if (A > B) A = B;
}
int64_t dp[2][500][500][2];
vector<pair<int, int>> robot[500][500];
bool good[500000][4];
int d[500000], e[500000];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> dx = {0, 1, 1, 0}, dy = {0, -1, 0, 1};
  int cap = max(m, n);
  for (int i = 0; i < k; i++) {
    int x, y, t;
    cin >> x >> y >> d[i] >> t >> e[i];
    for (int zi = 0; zi < 4; zi++) {
      int nx = x + dx[zi] * d[i], ny = y + dy[zi] * d[i];
      if (zi + t <= nx + ny && (zi + t) % 4 == (nx + ny) % 4) {
        robot[nx][ny].push_back({i, zi});
        good[i][zi] = 1;
      }
    }
  }
  for (int X = 0; X < 2; X++)
    for (int Y = 0; Y < m; Y++)
      for (int W = 0; W < cap; W++)
        for (int vert = 0; vert < 2; vert++) dp[X][Y][W][vert] = LLONG_MAX;
  dp[0][0][0][0] = dp[0][0][0][1] = 0;
  int64_t ans = LLONG_MAX;
  for (int X = 0; X < n; X++) {
    int cur = X & 1;
    int nxt = 1 - cur;
    for (int Y = 0; Y < m; Y++) {
      for (int W = 0; W < cap; W++) {
        for (int vert = 0; vert < 2; vert++) {
          if (W > (vert ? X : Y) || dp[cur][Y][W][vert] == LLONG_MAX) break;
          if (Y < m - 1) {
            int right = (vert ? 0 : W) + 1;
            int64_t smash = 0;
            for (auto &[id, zi] : robot[X][Y + 1]) {
              if (zi == 2 && right >= d[id] && good[id][1]) continue;
              if (zi == 3 && right >= d[id] && good[id][0]) continue;
              smash += e[id];
            }
            update(dp[cur][Y + 1][right][0], dp[cur][Y][W][vert] + smash);
            update(dp[cur][Y + 1][0][1], dp[cur][Y][W][vert] + smash);
          }
          if (X < n - 1) {
            int down = (vert ? W : 0) + 1;
            int64_t smash = 0;
            for (auto &[id, zi] : robot[X + 1][Y]) {
              if (zi == 2 && down >= d[id] && good[id][0]) continue;
              smash += e[id];
            }
            update(dp[nxt][Y][down][1], dp[cur][Y][W][vert] + smash);
            update(dp[nxt][Y][0][0], dp[cur][Y][W][vert] + smash);
          }
        }
      }
    }
    if (X == n - 1) {
      for (int W = 0; W < cap; W++)
        for (int vert = 0; vert < 2; vert++)
          update(ans, dp[cur][m - 1][W][vert]);
      break;
    }
    for (int Y = 0; Y < m; Y++)
      for (int W = 0; W < cap; W++)
        for (int vert = 0; vert < 2; vert++) dp[cur][Y][W][vert] = LLONG_MAX;
  }
  cout << ans;
  return 0;
}
