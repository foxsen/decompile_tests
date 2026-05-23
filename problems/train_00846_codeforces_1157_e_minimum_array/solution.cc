#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005], b[200005], c[200005], ans[200005];
int t[200005 << 3];
void pushup(int x) { t[x] = t[x << 1] + t[x << 1 | 1]; }
void build(int x, int l, int r) {
  if (l == r) {
    t[x] = c[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  pushup(x);
}
void update(int x, int l, int r, int pos, int v) {
  if (l == r) {
    t[x] -= v;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update(x << 1, l, mid, pos, v);
  else
    update(x << 1 | 1, mid + 1, r, pos, v);
  pushup(x);
}
int query(int x, int l, int r, int lp, int rp) {
  if (lp <= l && r <= rp) return t[x];
  int mid = (l + r) >> 1;
  int res = 0;
  if (lp <= mid) res += query(x << 1, l, mid, lp, rp);
  if (mid < rp) res += query(x << 1 | 1, mid + 1, r, lp, rp);
  return res;
}
int calc(int x) {
  int l = x, r = n;
  if (query(1, 1, n, l, r) == 0) {
    l = 1, r = x - 1;
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (query(1, 1, n, l, mid) > 0) {
        r = mid - 1;
        ans = mid;
      } else
        l = mid + 1;
    }
    return ans;
  } else {
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (query(1, 1, n, l, mid) > 0) {
        r = mid - 1;
        ans = mid;
      } else
        l = mid + 1;
    }
    return ans;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) {
    c[(b[i] % n) + 1]++;
  }
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int x = a[i] % n;
    int y = n - x;
    y++;
    int id = calc(y);
    update(1, 1, n, id, 1);
    ans[i] = (x + id - 1) % n;
  }
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
  return 0;
}
