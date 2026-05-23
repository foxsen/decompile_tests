#include <bits/stdc++.h>
using namespace std;
const int N = 1005, INF = 1e9;
int D[N][N], n, m, er, ec, sr, sc, k;
bool mark[N][N];
char t[N][N];
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
queue<pair<int, int> > q;
void bfs(int r, int c) {
  mark[r][c] = true;
  D[r][c] = 0;
  q.push({r, c});
  while (q.size()) {
    pair<int, int> v = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      pair<int, int> u = {v.first + dx[i], v.second + dy[i]};
      if (!mark[u.first][u.second] && t[u.first][u.second] != 'T' &&
          u.first <= n && u.first > 0 && u.second <= m && u.second > 0) {
        mark[u.first][u.second] = true;
        D[u.first][u.second] = D[v.first][v.second] + 1;
        q.push(u);
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> t[i][j];
      if (t[i][j] == 'E') er = i, ec = j;
      if (t[i][j] == 'S') sr = i, sc = j;
      D[i][j] = INF;
    }
  bfs(er, ec);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (D[i][j] <= D[sr][sc] && isdigit(t[i][j])) k += t[i][j] - '0';
  cout << k;
}
