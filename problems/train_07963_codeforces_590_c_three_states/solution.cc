#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 7;
char a[maxn][maxn];
int dist[3][maxn][maxn];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, n, m;
void bfs(int x) {
  deque<pair<int, int> > q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == char('0' + x)) dist[x][i][j] = 0, q.push_back({i, j});
  while (q.size()) {
    pair<int, int> v = q.front();
    q.pop_front();
    for (int i = 0; i < 4; i++) {
      int nx = v.first + dx[i], ny = v.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (dist[x][nx][ny] != -1 || a[nx][ny] == '#') continue;
      int val = 0;
      if (a[nx][ny] == '.') val = 1;
      dist[x][nx][ny] = dist[x][v.first][v.second] + val;
      if (!val)
        q.push_front({nx, ny});
      else
        q.push_back({nx, ny});
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < maxn; j++)
      for (int k = 0; k < maxn; k++) dist[i][j][k] = -1;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j];
      if (a[i][j] > '0' && a[i][j] < '5') a[i][j]--;
    }
  }
  bfs(0), bfs(1), bfs(2);
  int ans = 1e9;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') continue;
      if (a[i][j] == '.') {
        if (dist[0][i][j] == -1 || dist[1][i][j] == -1 || dist[2][i][j] == -1)
          continue;
        ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2);
      } else {
        if (dist[1][i][j] == -1 || dist[2][i][j] == -1 || dist[0][i][j] == -1)
          continue;
        ans = min(ans, dist[1][i][j] + dist[2][i][j] + dist[0][i][j]);
      }
    }
  if (ans == int(1e9)) ans = -1;
  cout << ans << endl;
}
