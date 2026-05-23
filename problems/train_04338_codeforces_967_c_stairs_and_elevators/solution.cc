#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1.0);
template <class T>
T gcd(T a, T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
const int maxn = 1e5 + 10;
int n, m, v, cl, ce, ele[maxn], st[maxn];
inline int ABS(int x) { return x < 0 ? -x : x; }
int solve(int x1, int y1, int x2, int y2) {
  int res = INF, tmp;
  int p = lower_bound(st, st + cl, y1) - st;
  if (p < cl) {
    tmp = ABS(x1 - x2) + ABS(st[p] - y1) + ABS(st[p] - y2);
    res = min(res, tmp);
  }
  if (p > 0) {
    tmp = ABS(x1 - x2) + ABS(st[p - 1] - y1) + ABS(st[p - 1] - y2);
    res = min(res, tmp);
  }
  p = lower_bound(ele, ele + ce, y1) - ele;
  if (p < ce) {
    tmp = (ABS(x1 - x2) + v - 1) / v + ABS(ele[p] - y1) + ABS(ele[p] - y2);
    res = min(res, tmp);
  }
  if (p > 0) {
    tmp = (ABS(x1 - x2) + v - 1) / v + ABS(ele[p - 1] - y1) +
          ABS(ele[p - 1] - y2);
    res = min(res, tmp);
  }
  if (x1 == x2) res = min(res, ABS(y1 - y2));
  return res;
}
int main() {
  cin >> n >> m >> cl >> ce >> v;
  for (int i = 0; i < cl; i++) scanf("%d", &st[i]);
  for (int i = 0; i < ce; i++) scanf("%d", &ele[i]);
  sort(st, st + cl);
  sort(ele, ele + ce);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", solve(x1, y1, x2, y2));
  }
  return 0;
}
