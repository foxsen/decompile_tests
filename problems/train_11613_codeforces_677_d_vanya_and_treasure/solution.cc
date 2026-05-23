#include <bits/stdc++.h>
using namespace std;
int treas[310][310];
long long dp[310][310];
long long d[310][310];
vector<pair<int, int> > G[110000];
vector<pair<long long, pair<int, int> > > lst;
queue<pair<long long, pair<int, int> > > bfs;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
long long n, m;
long long Dist(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}
int main() {
  ios_base::sync_with_stdio(0);
  int p, fx, fy;
  cin >> n >> m >> p;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> treas[i][j];
      G[treas[i][j]].push_back({i, j});
      if (treas[i][j] == p) fx = i, fy = j;
      if (treas[i][j] == 1) dp[i][j] = i + j;
    }
  for (int i = 2; i <= p; i++) {
    long long cur_size = G[i].size();
    long long prev_size = G[i - 1].size();
    if (cur_size * prev_size <= n * m) {
      for (int j = 0; j < cur_size; j++) {
        int cur_x = G[i][j].first;
        int cur_y = G[i][j].second;
        dp[cur_x][cur_y] = 1e9;
        for (int k = 0; k < prev_size; k++) {
          int prev_x = G[i - 1][k].first;
          int prev_y = G[i - 1][k].second;
          dp[cur_x][cur_y] =
              min(dp[cur_x][cur_y],
                  dp[prev_x][prev_y] + Dist(cur_x, cur_y, prev_x, prev_y));
        }
      }
    } else {
      lst.clear();
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++) d[j][k] = -1;
      for (int j = 0; j < prev_size; j++) {
        int prev_x = G[i - 1][j].first;
        int prev_y = G[i - 1][j].second;
        lst.push_back({dp[prev_x][prev_y], {prev_x, prev_y}});
      }
      sort(lst.begin(), lst.end());
      int ptr = 1;
      bfs.push(lst[0]);
      d[lst[0].second.first][lst[0].second.second] = lst[0].first;
      while (!bfs.empty()) {
        int x = bfs.front().second.first;
        int y = bfs.front().second.second;
        long long val = bfs.front().first;
        bfs.pop();
        while (ptr < lst.size() && lst[ptr].first <= val) bfs.push(lst[ptr++]);
        int X, Y;
        for (int k = 0; k < 4; k++) {
          X = x + dir[k][0];
          Y = y + dir[k][1];
          if (X >= 0 && X <= n && Y >= 0 && Y < m && d[X][Y] == -1) {
            d[X][Y] = val + 1;
            bfs.push({val + 1, {X, Y}});
          }
        }
      }
      for (int j = 0; j < cur_size; j++) {
        int x = G[i][j].first;
        int y = G[i][j].second;
        dp[x][y] = d[x][y];
      }
    }
  }
  cout << dp[fx][fy] << "\n";
  return 0;
}
