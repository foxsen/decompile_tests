#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int INF = 1e9 + 7;
int cnt[maxn][maxn];
char board[maxn][maxn];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, k;
pair<int, int> st, ed;
int bfs() {
  queue<pair<int, int> > que;
  que.push(st);
  cnt[st.first][st.second] = 0;
  auto check = [](int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m || board[x][y] == '#') return false;
    return true;
  };
  while (!que.empty()) {
    auto top = que.front();
    que.pop();
    for (int j = 0; j < 4; j++) {
      for (int i = 1; i <= k; i++) {
        int xx = top.first + i * dx[j], yy = top.second + i * dy[j];
        if (!check(xx, yy)) break;
        if (cnt[xx][yy] <= cnt[top.first][top.second] + 1) continue;
        cnt[xx][yy] = cnt[top.first][top.second] + 1;
        que.push(make_pair(xx, yy));
        if (make_pair(xx, yy) == ed) {
          return cnt[xx][yy];
        }
      }
    }
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(15);
  cout << fixed;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> board[i];
    for (int j = 0; j < m; j++) {
      cnt[i][j] = INF;
    }
  }
  cin >> st.first >> st.second;
  cin >> ed.first >> ed.second;
  st.first--;
  st.second--;
  ed.first--;
  ed.second--;
  if (st == ed) {
    cout << 0 << '\n';
    return 0;
  }
  cout << bfs() << '\n';
  return 0;
}
