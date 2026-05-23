#include <bits/stdc++.h>
using namespace std;
int n, m, r, c, xx, yy;
char a[2005][2005];
deque<pair<pair<int, int>, pair<int, int>>> q;
int vis[2005][2005];
bool in(int x, int y) { return x <= n && x >= 1 && y <= m && y >= 1; }
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> r >> c >> xx >> yy;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int x = r, y = c, n1 = 0, n2 = 0;
  vis[x][y] = 1;
  q.push_front(make_pair(make_pair(x, y), make_pair(n1, n2)));
  while (!q.empty()) {
    x = q.front().first.first;
    y = q.front().first.second;
    n1 = q.front().second.first;
    n2 = q.front().second.second;
    q.pop_front();
    if (in(x + 1, y) && a[x + 1][y] == '.' && !vis[x + 1][y]) {
      q.push_front(make_pair(make_pair(x + 1, y), make_pair(n1, n2)));
      vis[x + 1][y] = 1;
    }
    if (in(x - 1, y) && a[x - 1][y] == '.' && !vis[x - 1][y]) {
      q.push_front(make_pair(make_pair(x - 1, y), make_pair(n1, n2)));
      vis[x - 1][y] = 1;
    }
    if (in(x, y + 1) && n2 < yy && !vis[x][y + 1] && a[x][y + 1] == '.') {
      q.push_back(make_pair(make_pair(x, y + 1), make_pair(n1, n2 + 1)));
      vis[x][y + 1] = 1;
    }
    if (in(x, y - 1) && n1 < xx && !vis[x][y - 1] && a[x][y - 1] == '.') {
      q.push_back(make_pair(make_pair(x, y - 1), make_pair(n1 + 1, n2)));
      vis[x][y - 1] = 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis[i][j]) ans++;
    }
  }
  cout << ans << endl;
}
