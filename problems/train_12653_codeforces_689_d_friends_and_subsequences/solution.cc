#include <bits/stdc++.h>
using namespace std;
struct Segment_Tree {
  int mx[200003 << 2], mn[200003 << 2], a[200003];
  int qmax(int nl, int nr, int l, int r, int u) {
    if (nl <= l && r <= nr) return mx[u];
    int res = -0x3f3f3f3f, mid = (l + r) >> 1;
    if (nl <= mid) res = max(res, qmax(nl, nr, l, mid, (u << 1)));
    if (nr > mid) res = max(res, qmax(nl, nr, mid + 1, r, (u << 1 | 1)));
    return res;
  }
  int qmin(int nl, int nr, int l, int r, int u) {
    if (nl <= l && r <= nr) return mn[u];
    int res = 0x3f3f3f3f, mid = (l + r) >> 1;
    if (nl <= mid) res = min(res, qmin(nl, nr, l, mid, (u << 1)));
    if (nr > mid) res = min(res, qmin(nl, nr, mid + 1, r, (u << 1 | 1)));
    return res;
  }
  void build(int l, int r, int u) {
    if (l == r) {
      mx[u] = mn[u] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, (u << 1)), build(mid + 1, r, (u << 1 | 1));
    mx[u] = max(mx[(u << 1)], mx[(u << 1 | 1)]);
    mn[u] = min(mn[(u << 1)], mn[(u << 1 | 1)]);
  }
};
Segment_Tree A, B;
int n;
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) scanf("%d", &A.a[i]);
  for (register int i = 1; i <= n; ++i) scanf("%d", &B.a[i]);
  A.build(1, n, 1), B.build(1, n, 1);
  long long x0, x1, ans = 0;
  for (register int i = 1; i <= n; ++i) {
    long long l = i, r = n, mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if (A.qmax(i, mid, 1, n, 1) >= B.qmin(i, mid, 1, n, 1))
        r = mid;
      else
        l = mid + 1;
    }
    if (A.qmax(i, r, 1, n, 1) != B.qmin(i, r, 1, n, 1)) continue;
    x0 = r;
    r = n, l = x0;
    while (l < r) {
      mid = (l + r) >> 1;
      if (A.qmax(i, mid, 1, n, 1) > B.qmin(i, mid, 1, n, 1))
        r = mid;
      else
        l = mid + 1;
    }
    if (A.qmax(i, r, 1, n, 1) == B.qmin(i, r, 1, n, 1))
      x1 = r;
    else
      x1 = r - 1;
    ans += x1 - x0 + 1;
  }
  printf("%lld\n", ans);
}
