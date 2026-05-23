#include <bits/stdc++.h>
using namespace std;
int n, m, q, to[100005 * 2][50], tag[100005 * 4];
long long tim[100005], dist[100005 * 2][50];
struct point {
  int id, type, x1, y1, x2, y2;
  point() {}
  point(int _id, int _x1, int _y1, int _x2, int _y2)
      : id(_id), x1(_x1), y1(_y1), x2(_x2), y2(_y2) {
    type = x1 == x2 ? (y1 > y2 ? 1 : 2) : (x1 > x2 ? 3 : 4);
  }
  point(int _id, int _x1, int _y1, char c)
      : id(_id), x1(_x1), y1(_y1), x2(_x1), y2(_y1) {
    type = c == 'D' ? 1 : c == 'U' ? 2 : c == 'L' ? 3 : 4;
  }
  int dx() { return type <= 2 ? 0 : type == 3 ? -1 : 1; }
  int dy() { return type > 2 ? 0 : type == 1 ? -1 : 1; }
} d[100005 * 2];
bool cmp0(const point &a, const point &b) { return a.id < b.id; }
bool cmp1(const point &a, const point &b) {
  return min(a.y1, a.y2) < min(b.y1, b.y2);
}
bool cmp2(const point &a, const point &b) {
  return max(a.y1, a.y2) > max(b.y1, b.y2);
}
bool cmp3(const point &a, const point &b) {
  return min(a.x1, a.x2) < min(b.x1, b.x2);
}
bool cmp4(const point &a, const point &b) {
  return max(a.x1, a.x2) > max(b.x1, b.x2);
}
void modify(int pos, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    tag[pos] = z;
    return;
  }
  if (tag[pos] != -1)
    tag[(pos << 1)] = tag[(pos << 1 | 1)] = tag[pos], tag[pos] = -1;
  int mid = (l + r) >> 1;
  if (x <= mid) modify((pos << 1), l, mid, x, y, z);
  if (y > mid) modify((pos << 1 | 1), mid + 1, r, x, y, z);
}
int query(int pos, int l, int r, int x) {
  if (tag[pos] != -1) return tag[pos];
  int mid = (l + r) >> 1;
  if (x <= mid)
    return query((pos << 1), l, mid, x);
  else
    return query((pos << 1 | 1), mid + 1, r, x);
}
void solve(int type) {
  modify(1, 0, m, 0, m, 0);
  for (int i = 1; i <= n + q; ++i) {
    if (d[i].type == type)
      to[d[i].id][0] = query(1, 0, m, type <= 2 ? d[i].x1 : d[i].y1);
    if (d[i].id <= n)
      modify(1, 0, m, type <= 2 ? min(d[i].x1, d[i].x2) : min(d[i].y1, d[i].y2),
             type <= 2 ? max(d[i].x1, d[i].x2) : max(d[i].y1, d[i].y2),
             d[i].id);
  }
  sort(d + 1, d + n + q + 1, cmp0);
}
int getd(int x, int y) {
  return d[x].dx() * (d[y].x2 - d[x].x2) + d[x].dy() * (d[y].y2 - d[x].y2);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    d[i] = point(i, x1, y1, x2, y2);
  }
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int x, y;
    char opt[3];
    scanf("%d%d%s%I64d", &x, &y, opt, &tim[i]);
    d[n + i] = point(n + i, x, y, opt[0]);
  }
  stable_sort(d + 1, d + n + q + 1, cmp1);
  solve(1);
  stable_sort(d + 1, d + n + q + 1, cmp2);
  solve(2);
  stable_sort(d + 1, d + n + q + 1, cmp3);
  solve(3);
  stable_sort(d + 1, d + n + q + 1, cmp4);
  solve(4);
  for (int i = 1; i <= n + q; ++i)
    dist[i][0] = to[i][0] == 0 ? 0x3f3f3f3f3f3f3f3fll
                               : abs(d[i].x2 - d[to[i][0]].x2) +
                                     abs(d[i].y2 - d[to[i][0]].y2);
  for (int j = 1; j < 50; ++j)
    for (int i = 1; i <= n + q; ++i)
      to[i][j] = to[to[i][j - 1]][j - 1],
      dist[i][j] =
          min(0x3f3f3f3f3f3f3f3fll, dist[i][j - 1] + dist[to[i][j - 1]][j - 1]);
  for (int i = 1; i <= q; ++i) {
    int now = n + i;
    for (int j = 49; j >= 0; --j)
      if (dist[now][j] <= tim[i]) tim[i] -= dist[now][j], now = to[now][j];
    if (to[now][0] && tim[i] > getd(now, to[now][0]))
      tim[i] -= dist[now][0], now = to[now][0];
    long long x = d[now].x2 + tim[i] * d[now].dx();
    long long y = d[now].y2 + tim[i] * d[now].dy();
    cout << min(max(x, 0ll), 1ll * m) << ' ' << min(max(y, 0ll), 1ll * m)
         << '\n';
  }
  return 0;
}
