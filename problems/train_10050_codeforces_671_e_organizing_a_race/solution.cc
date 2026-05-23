#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, top;
int a[100010], b[100010], s[100010];
long long f[100010], g[100010];
struct Segment_Tree {
  long long tg[100010 * 4], th[100010 * 4], tag[100010 * 4];
  void update(int k) {
    tg[k] = min(tg[k * 2], tg[k * 2 + 1]);
    th[k] = min(th[k * 2], th[k * 2 + 1]);
  }
  void pushdown(int k) {
    if (!tag[k]) return;
    th[k * 2] += tag[k];
    th[k * 2 + 1] += tag[k];
    tag[k * 2] += tag[k];
    tag[k * 2 + 1] += tag[k];
    tag[k] = 0;
  }
  void build(int k, int l, int r) {
    if (l == r) {
      tg[k] = th[k] = 9999999999999999;
      tag[k] = 0;
      return;
    }
    int mid = (l + r) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    update(k);
  }
  void upgrade(int k, int l, int r, int x) {
    if (l == r) {
      tg[k] = th[k] = g[l];
      return;
    }
    pushdown(k);
    int mid = (l + r) / 2;
    if (mid >= x)
      upgrade(k * 2, l, mid, x);
    else
      upgrade(k * 2 + 1, mid + 1, r, x);
    update(k);
  }
  void modi(int k, int l, int r, int x, int y, long long z) {
    if (l >= x && r <= y) {
      th[k] += z;
      tag[k] += z;
      return;
    }
    pushdown(k);
    int mid = (l + r) / 2;
    if (mid >= x) modi(k * 2, l, mid, x, y, z);
    if (mid < y) modi(k * 2 + 1, mid + 1, r, x, y, z);
    update(k);
  }
  int query(int k, int l, int r, int R, long long y) {
    if (l > R) return -1;
    if (l == r) return l;
    pushdown(k);
    int mid = (l + r) / 2;
    long long tmp = min(y, th[k * 2]);
    if (R > mid && tmp >= tg[k * 2 + 1] - m) {
      int res = query(k * 2 + 1, mid + 1, r, R, tmp);
      if (res != -1) return res;
    }
    if (tg[k * 2] - m <= y) return query(k * 2, l, mid, R, y);
    return -1;
  }
} T;
int ans;
int main() {
  n = read();
  m = read();
  for (int i = 1; i < n; i++) b[i] = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++)
    f[i] = f[i - 1] + a[i - 1] - b[i - 1], g[i] = g[i - 1] + b[i - 1] - a[i];
  f[n + 1] = -9999999999999999;
  s[0] = n + 1;
  T.build(1, 1, n);
  for (int i = n; i >= 1; i--) {
    T.upgrade(1, 1, n, i);
    while (top && f[s[top]] >= f[i]) {
      if (top > 1)
        T.modi(1, 1, n, s[top - 1] - 1, n, f[s[top]] - f[s[top - 1]]);
      top--;
    }
    s[++top] = i;
    if (top > 1) T.modi(1, 1, n, s[top - 1] - 1, n, f[s[top - 1]] - f[s[top]]);
    int l = 0, r = top, pos = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (f[i] - f[s[mid]] > m) {
        pos = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    int R = s[pos] - 1;
    ans = max(ans, T.query(1, 1, n, R, 9999999999999999) - i + 1);
  }
  cout << ans << endl;
  return 0;
}
