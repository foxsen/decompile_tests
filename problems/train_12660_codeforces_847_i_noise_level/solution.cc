#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int m, n, q, p, visit[300][300], val[300][300], A[300][300];
long long B[300][300];
void BFS(int s, int t, int cnt) {
  queue<pair<int, int> > que;
  que.push(make_pair(s, t));
  B[s][t] += A[s][t];
  val[s][t] = A[s][t];
  visit[s][t] = cnt;
  while (!que.empty()) {
    int u = que.front().first, v = que.front().second;
    que.pop();
    for (int i = 0; i < 4; i++) {
      int x = u + dx[i];
      int y = v + dy[i];
      if (x <= 0 || x > m || y <= 0 || y > n) {
        continue;
      }
      if (A[x][y] == -1 || visit[x][y] == cnt) {
        continue;
      }
      visit[x][y] = cnt;
      val[x][y] = val[u][v] / 2;
      B[x][y] += val[x][y];
      if (val[x][y] > 0) {
        que.push(make_pair(x, y));
      }
    }
  }
}
int main() {
  cin >> m >> n >> q >> p;
  for (int i = 1; i <= m; i++) {
    string st;
    cin >> st;
    for (int j = 1; j <= n; j++) {
      if (st[j - 1] == '.') {
        A[i][j] = 0;
      } else if (st[j - 1] == '*') {
        A[i][j] = -1;
      } else {
        A[i][j] = (st[j - 1] - 'A' + 1) * q;
      }
    }
  }
  memset(B, 0, sizeof(B));
  memset(visit, 0, sizeof(visit));
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (A[i][j] > 0) {
        BFS(i, j, ++cnt);
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (B[i][j] > p) {
        res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
