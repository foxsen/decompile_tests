#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
char adj[N][N];
int vis[N][N], dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
bool dfs(int x, int y, int markx, int marky) {
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0], yy = y + dir[i][1];
    int imarkx = markx, imarky = marky;
    if (xx < 0) imarkx++;
    if (xx >= n) imarkx--;
    if (yy < 0) imarky++;
    if (yy >= m) imarky--;
    xx = (xx + n) % n;
    yy = (yy + m) % m;
    if (adj[xx][yy] == '#') continue;
    if (vis[xx][yy] == 0) {
      vis[xx][yy] = imarkx * N + imarky;
      if (dfs(xx, yy, imarkx, imarky)) return true;
    } else {
      if (vis[xx][yy] != (imarkx * N + imarky)) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  int aimx, aimy;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      scanf("%s", adj[i]);
      for (int j = 0; j < m; j++) {
        if (adj[i][j] == 'S') {
          aimx = i;
          aimy = j;
        }
      }
    }
    vis[aimx][aimy] = N * N + N;
    if (dfs(aimx, aimy, N, N))
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
