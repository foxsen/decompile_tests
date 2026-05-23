#include <bits/stdc++.h>
using namespace std;
inline void update(long long &x, long long y) { x += y; }
struct Point {
  long long x, y;
  Point() {}
  Point(long long a, long long b) : x(a), y(b) {}
  Point operator-(Point b) { return Point(x - b.x, y - b.y); }
  bool operator<(const Point &b) const {
    return (x != b.x) ? x < b.x : y < b.y;
  }
};
inline long long cross(Point x, Point y) { return x.x * y.y - x.y * y.x; }
Point p[305];
int id1[305][305], id2[305][305], cur;
inline bool cmp(int x, int y) {
  return cross(p[x] - p[cur], p[y] - p[cur]) > 0;
}
void pre(int n) {
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) {
    cur = i;
    for (int j = 1; j < i; j++) id1[i][++id1[i][0]] = j;
    for (int j = i + 1; j <= n; j++) id2[i][++id2[i][0]] = j;
    sort(id1[i] + 1, id1[i] + id1[i][0] + 1, cmp);
    sort(id2[i] + 1, id2[i] + id2[i][0] + 1, cmp);
  }
}
long long f[305][305][5], g[305][305][5];
long long dp(int n, int s) {
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (int i = s + 1; i <= n; i++) f[i][s][1] = g[i][s][1] = 1;
  long long ans = 0;
  for (int i = s + 1; i <= n; i++) {
    long long s1[5], s2[5];
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));
    for (int j = s; j < i; j++)
      for (int k = 1; k < 5; k++) {
        update(s1[k], f[i][j][k]);
        update(s2[k], g[i][j][k]);
      }
    for (int j = 1; j < 5; j++) update(ans, s1[j] * s2[5 - j]);
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));
    int r = 1;
    for (int j = 1; j <= id2[i][0]; j++) {
      int x = id2[i][j];
      while (r <= id1[i][0] && cross(p[x] - p[i], p[id1[i][r]] - p[i]) > 0) {
        int u = id1[i][r++];
        for (int k = 1; k < 4; k++) update(s1[k], f[i][u][k]);
      }
      for (int k = 1; k < 4; k++) update(f[x][i][k + 1], s1[k]);
    }
    r = id1[i][0];
    for (int j = id2[i][0]; j > 0; j--) {
      int x = id2[i][j];
      while (r && cross(p[x] - p[i], p[id1[i][r]] - p[i]) < 0) {
        int u = id1[i][r--];
        for (int k = 1; k < 4; k++) update(s2[k], g[i][u][k]);
      }
      for (int k = 1; k < 4; k++) update(g[x][i][k + 1], s2[k]);
    }
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = Point(x, y);
  }
  pre(n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) update(ans, dp(n, i));
  printf("%lld\n", ans);
  return 0;
}
