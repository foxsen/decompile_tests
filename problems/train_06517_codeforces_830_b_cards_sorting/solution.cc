#include <bits/stdc++.h>
int n;
struct pos {
  int x, y;
} ps[100007];
bool operator<(pos a, pos b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }
int bit[100007];
void inc(int w, int a) {
  for (; w <= n; w += w & -w) bit[w] += a;
}
int sum(int w) {
  int s = 0;
  for (; w; w -= w & -w) s += bit[w];
  return s;
}
int dis(int a, int b) {
  if (a > b) return dis(a, n) + dis(0, b);
  return b - sum(b) - a + sum(a);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &ps[i].y), ps[i].x = i;
  std::sort(ps + 1, ps + n + 1);
  int pw = 0;
  long long ans = 0;
  for (int i = 1, j = 1; j <= n; i = j) {
    for (; j <= n && ps[i].y == ps[j].y; ++j)
      ;
    int k = std::upper_bound(ps + i, ps + j, (pos){pw, ps[i].y}) - ps;
    int l = ps[k == i ? j - 1 : k - 1].x;
    int r = ps[k == j ? i : k].x;
    ans += dis(pw, r);
    ans += dis(r, l);
    pw = l;
    for (int a = i; a < j; ++a) inc(ps[a].x, 1);
  }
  printf("%I64d\n", ans);
  return 0;
}
