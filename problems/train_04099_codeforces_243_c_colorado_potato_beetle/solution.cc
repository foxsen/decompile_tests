#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 5e3 + 10;
vector<pair<int, int>> vp1, vp2;
vector<int> vx, vy;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int pos[N];
char flag[N][N];
void dfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  flag[x][y] = 2;
  while (!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (tx < 0 || tx >= N) continue;
      if (ty < 0 || ty >= N) continue;
      if (flag[tx][ty]) continue;
      flag[tx][ty] = 2;
      q.push({tx, ty});
    }
  }
}
int main() {
  pos['L'] = 0;
  pos['R'] = 1;
  pos['U'] = 2;
  pos['D'] = 3;
  int x = 0, y = 0;
  for (int i = -1; i <= 1; i++) {
    vx.push_back(i);
    vy.push_back(i);
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    int d;
    cin >> c >> d;
    int o = pos[c];
    int nx = x + dx[o] * d;
    int ny = y + dy[o] * d;
    vx.push_back(nx);
    vx.push_back(nx - 1);
    vx.push_back(nx + 1);
    vy.push_back(ny);
    vy.push_back(ny - 1);
    vy.push_back(ny + 1);
    vp1.push_back({x, nx});
    vp2.push_back({y, ny});
    x = nx, y = ny;
  }
  sort(vx.begin(), vx.end());
  vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
  sort(vy.begin(), vy.end());
  vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
  for (int i = 0; i < n; i++) {
    int ax = lower_bound(vx.begin(), vx.end(), vp1[i].first) - vx.begin();
    int bx = lower_bound(vx.begin(), vx.end(), vp1[i].second) - vx.begin();
    int ay = lower_bound(vy.begin(), vy.end(), vp2[i].first) - vy.begin();
    int by = lower_bound(vy.begin(), vy.end(), vp2[i].second) - vy.begin();
    if (ax > bx) swap(ax, bx);
    if (ay > by) swap(ay, by);
    for (int j = ax; j <= bx; j++) {
      for (int k = ay; k <= by; k++) {
        flag[j][k] = 1;
      }
    }
  }
  dfs(0, 0);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (flag[i][j] == 2) continue;
      ans += 1LL * (vx[i + 1] - vx[i]) * (vy[j + 1] - vy[j]);
    }
  }
  cout << ans << endl;
  return 0;
}
