#include <bits/stdc++.h>
using namespace std;
void desperate_optimization(int precision) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(precision);
}
const int N = 1e3;
const int MAXN = N * N + 5;
int dist[N + 5][N + 5];
bool grup[N + 5][N + 5];
string f[N + 5];
int py[] = {1, 0, -1, 0};
int px[] = {0, 1, 0, -1};
queue<pair<int, int> > q;
void hora(int tc) {
  int r, c, k;
  cin >> r >> c >> k;
  for (int i = 0; i < r; i++) cin >> f[i];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      bool ada = false;
      for (int k = 0; k < 4; k++) {
        int dy = i + py[k];
        int dx = j + px[k];
        if (dy < 0 || dx < 0 || dy >= r || dx >= c) continue;
        if (f[dy][dx] == f[i][j]) ada = true;
      }
      if (ada == true) {
        grup[i][j] = 1;
        q.push({i, j});
      } else
        grup[i][j] = 0, dist[i][j] = MAXN;
    }
  }
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    int cur_dist = dist[y][x];
    for (int k = 0; k < 4; k++) {
      int dy = y + py[k];
      int dx = x + px[k];
      if (dy < 0 || dx < 0 || dy >= r || dx >= c) continue;
      if (grup[dy][dx] == 1) continue;
      if (dist[dy][dx] > cur_dist + 1) {
        dist[dy][dx] = cur_dist + 1;
        q.push({dy, dx});
      }
    }
  }
  while (k--) {
    int u, v;
    long long p;
    cin >> u >> v >> p;
    u--, v--;
    long long ct = dist[u][v];
    int val = (f[u][v] - '0');
    if (ct == MAXN)
      cout << val << '\n';
    else {
      if (p <= ct)
        cout << val << '\n';
      else {
        p -= ct;
        p %= 2;
        cout << (val + p) % 2 << '\n';
      }
    }
  }
}
int main() {
  desperate_optimization(10);
  int ntc = 1;
  for (int tc = 1; tc <= ntc; tc++) hora(tc);
  return 0;
}
