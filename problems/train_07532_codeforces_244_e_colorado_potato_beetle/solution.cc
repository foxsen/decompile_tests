#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int n, l[N], c[N << 1][N << 1];
char d[N];
vector<int> vx, vy;
void gao(int lx, int ly, int rx, int ry) {
  if (lx > rx) swap(lx, rx);
  if (ly > ry) swap(ly, ry);
  lx = lower_bound(vx.begin(), vx.end(), lx) - vx.begin();
  rx = lower_bound(vx.begin(), vx.end(), rx) - vx.begin();
  ly = lower_bound(vy.begin(), vy.end(), ly) - vy.begin();
  ry = lower_bound(vy.begin(), vy.end(), ry) - vy.begin();
  for (int i = (lx), I = (rx + 1); i < I; ++i)
    for (int j = (ly), I = (ry + 1); j < I; ++j) c[i][j] = 1;
}
void inv() {
  queue<pair<int, int> > que;
  c[0][0] = 2, que.push(make_pair(0, 0));
  while (!que.empty()) {
    int sx = que.front().first, sy = que.front().second;
    que.pop();
    for (int i = (0), I = (4); i < I; ++i) {
      int x = sx + dx[i], y = sy + dy[i];
      if (x < 0 || x >= ((int)(vx).size()) || y < 0 ||
          y >= ((int)(vy).size()) || c[x][y])
        continue;
      c[x][y] = 2, que.push(make_pair(x, y));
    }
  }
}
int main() {
  scanf("%d", &n);
  vx.push_back(0), vx.push_back(1), vx.push_back(-INF), vx.push_back(INF);
  vy.push_back(0), vy.push_back(1), vy.push_back(-INF), vy.push_back(INF);
  int x = 0, y = 0;
  for (int i = (0), I = (n); i < I; ++i) {
    scanf(" %c %d", &d[i], &l[i]);
    if (d[i] == 'L') {
      x -= l[i];
    } else if (d[i] == 'R') {
      x += l[i];
    } else if (d[i] == 'D') {
      y -= l[i];
    } else {
      y += l[i];
    }
    vx.push_back(x), vx.push_back(x + 1);
    vy.push_back(y), vy.push_back(y + 1);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  sort(vy.begin(), vy.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  x = 0, y = 0;
  for (int i = (0), I = (n); i < I; ++i) {
    if (d[i] == 'L') {
      gao(x, y, x - l[i], y);
      x -= l[i];
    } else if (d[i] == 'R') {
      gao(x, y, x + l[i], y);
      x += l[i];
    } else if (d[i] == 'D') {
      gao(x, y, x, y - l[i]);
      y -= l[i];
    } else {
      gao(x, y, x, y + l[i]);
      y += l[i];
    }
  }
  inv();
  long long ans = 0;
  for (int i = (0), I = (((int)(vx).size()) - 1); i < I; ++i)
    for (int j = (0), I = (((int)(vy).size()) - 1); j < I; ++j)
      if (c[i][j] != 2) ans += 1ll * (vx[i + 1] - vx[i]) * (vy[j + 1] - vy[j]);
  printf("%lld", ans);
  return 0;
}
