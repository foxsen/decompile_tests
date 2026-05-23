#include <bits/stdc++.h>
using namespace std;
int n, m, ans, cnt, flag, tot;
int sx, sy;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dp[25][25][1 << 8];
int val[8], w[1 << 8];
int gx[8], gy[8];
char mp[25][25];
char s[25];
struct Node {
  int x, y, k;
} cur, now;
bool issur(int nx, int ny, int tx, int ty, int j) {
  if (nx == gx[j] && ny < gy[j]) {
    if (tx < gx[j]) return true;
  } else if (tx == gx[j] && ty < gy[j]) {
    if (nx < gx[j]) return true;
  }
  return false;
}
void bfs() {
  int i, j, t, k, nx, ny, tx, ty, nk;
  queue<Node> q;
  memset(dp, -1, sizeof(dp));
  ans = -0x3f3f3f3f;
  cur.x = sx;
  cur.y = sy;
  cur.k = 0;
  dp[sx][sy][0] = 0;
  q.push(cur);
  while (!q.empty()) {
    now = q.front();
    q.pop();
    nx = now.x;
    ny = now.y;
    nk = now.k;
    if (nx == sx && ny == sy) ans = max(ans, w[nk] - dp[nx][ny][nk]);
    for (i = 0; i < 4; i++) {
      tx = nx + dx[i];
      ty = ny + dy[i];
      k = nk;
      if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
      if (!(mp[tx][ty] == 'S' || mp[tx][ty] == '.')) continue;
      for (j = 0; j <= cnt; j++) {
        if (issur(nx, ny, tx, ty, j)) k ^= (1 << j);
      }
      if (dp[tx][ty][k] != -1 && dp[tx][ty][k] <= dp[nx][ny][nk] + 1) continue;
      cur.x = tx;
      cur.y = ty;
      cur.k = k;
      dp[tx][ty][k] = dp[nx][ny][nk] + 1;
      q.push(cur);
    }
  }
}
int main() {
  int i, j, t;
  while (~scanf("%d%d", &n, &m)) {
    cnt = -1;
    for (i = 1; i <= n; i++) {
      scanf("%s", s);
      for (j = 1; j <= m; j++) {
        mp[i][j] = s[j - 1];
        if (mp[i][j] == 'S') sx = i, sy = j;
        if (mp[i][j] >= '1' && mp[i][j] <= '8') {
          t = mp[i][j] - '1';
          cnt++;
          gx[t] = i, gy[t] = j;
        }
      }
    }
    for (i = 0; i <= cnt; i++) {
      scanf("%d", &val[i]);
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (mp[i][j] == 'B') gx[++cnt] = i, gy[cnt] = j, val[cnt] = -10000;
      }
    }
    memset(w, 0, sizeof(w));
    tot = 1 << (cnt + 1);
    for (i = 0; i < tot; i++) {
      for (j = 0; j <= cnt; j++) {
        if (i & (1 << j)) w[i] += val[j];
      }
    }
    bfs();
    printf("%d\n", ans);
  }
  return 0;
}
