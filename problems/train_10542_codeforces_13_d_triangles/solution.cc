#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m, dp[501][501];
struct Point {
  int x, y;
  Point() {}
  Point(int _x, int _y) { x = _x, y = _y; }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  long long operator*(const Point &a) const {
    return (long long)x * a.y - (long long)y * a.x;
  }
} a[501], b[501];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  a[0] = Point(-1e9 - 1, -1e9 - 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i].x >> b[i].y;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if ((a[i] - a[0]) * (a[j] - a[0]) <= 0) continue;
      for (int k = 1; k <= m; ++k) {
        if ((a[i] - a[0]) * (b[k] - a[0]) >= 0 &&
            (b[k] - a[0]) * (a[j] - a[0]) >= 0 &&
            (a[j] - a[i]) * (b[k] - a[i]) >= 0) {
          ++dp[i][j];
        }
      }
      dp[j][i] = -dp[i][j];
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      for (int k = j + 1; k <= n; ++k) {
        if (dp[i][j] + dp[j][k] + dp[k][i] == 0) {
          ++res;
        }
      }
    }
  }
  cout << res;
  cout << '\n';
  return 0;
}
