#include <bits/stdc++.h>
using namespace std;
int n, m, K, Q;
int color[1010][1010];
int dis[45][1010][1010];
bool st[45];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > q[45];
vector<pair<int, int> > vec[45];
void bfs(int target) {
  memset(st, false, sizeof st);
  int x, y;
  while (q[target].size()) {
    pair<int, int> t = q[target].front();
    q[target].pop();
    x = t.first, y = t.second;
    for (int i = 0; i < 4; i++) {
      int tx = x + dx[i], ty = y + dy[i];
      if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
      if (!dis[target][tx][ty]) {
        dis[target][tx][ty] = dis[target][x][y] + 1;
        q[target].push({tx, ty});
      }
    }
    if (!st[color[x][y]]) {
      st[color[x][y]] = true;
      for (int i = 0; i < vec[color[x][y]].size(); i++) {
        t = vec[color[x][y]][i];
        int tx = t.first, ty = t.second;
        if (dis[target][tx][ty]) continue;
        dis[target][tx][ty] = dis[target][x][y] + 1;
        q[target].push({tx, ty});
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &color[i][j]);
      vec[color[i][j]].push_back({i, j});
      q[color[i][j]].push({i, j});
      dis[color[i][j]][i][j] = 1;
    }
  }
  for (int i = 1; i <= K; i++) {
    bfs(i);
  }
  scanf("%d", &Q);
  for (int j = 1; j <= Q; j++) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int res = abs(r1 - r2) + abs(c1 - c2);
    for (int i = 1; i <= K; i++) {
      res = min(res, dis[i][r1][c1] + dis[i][r2][c2] - 1);
    }
    printf("%d\n", res);
  }
  return 0;
}
