#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 9;
char s[N];
bool vis[N];
struct Point {
  long long x, y, id;
  Point(long long _x = 0, long long _y = 0, long long _id = 0) {
    x = _x;
    y = _y;
    id = _id;
  }
  Point operator-(const Point& b) const { return Point(x - b.x, y - b.y); }
} p[N], p0, tem[N];
long long cross(Point a, Point b) { return a.x * b.y - b.x * a.y; }
bool cmp(Point a, Point b) { return cross(a - p0, b - p0) >= 0; }
int main() {
  int n;
  scanf("%d", &n);
  p0 = Point(10000000000, 10000000000);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &p[i].x, &p[i].y);
    p[i].id = i;
    if (p[i].y < p0.y || (p0.y == p[i].y && p[i].x < p0.x)) p0 = p[i];
  }
  scanf("%s", s);
  vector<int> ans;
  ans.push_back(p0.id);
  vis[p0.id] = 1;
  int sp = 0;
  for (int i = 2; i <= n; ++i, ++sp) {
    int cnt = 0;
    for (int j = 1; j <= n; ++j) {
      if (vis[j]) continue;
      tem[++cnt] = p[j];
    }
    sort(tem + 1, tem + 1 + cnt, cmp);
    int nex;
    if (s[sp] == 'L')
      nex = tem[1].id;
    else
      nex = tem[cnt].id;
    ans.push_back(nex);
    vis[nex] = 1;
    p0 = p[nex];
  }
  for (int i = 0; i < (int)ans.size(); ++i) printf("%d ", ans[i]);
  return 0;
}
