#include <bits/stdc++.h>
using namespace std;
const long long int N = 100005;
int n, q;
long long int a[N];
struct node {
  long double val, lz0, lz1;
  node() {
    val = lz0 = 0;
    lz1 = 1;
  }
} st[4 * N];
void build(int id, int l, int r) {
  if (l == r) {
    st[id].val = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  st[id].val = st[id * 2].val + st[id * 2 + 1].val;
}
void down(int id, int l, int r) {
  if (l == r) return;
  long double t = st[id * 2].val;
  int mid = (l + r) / 2;
  st[id * 2].val = st[id * 2].val * st[id].lz1 + st[id].lz0 * (mid - l + 1);
  st[id * 2 + 1].val = st[id * 2 + 1].val * st[id].lz1 + st[id].lz0 * (r - mid);
  st[id * 2].lz1 = st[id].lz1 * st[id * 2].lz1;
  st[id * 2 + 1].lz1 = st[id].lz1 * st[id * 2 + 1].lz1;
  st[id * 2].lz0 = st[id].lz1 * st[id * 2].lz0 + st[id].lz0;
  st[id * 2 + 1].lz0 = st[id].lz1 * st[id * 2 + 1].lz0 + st[id].lz0;
  st[id].lz1 = 1;
  st[id].lz0 = 0;
}
void update(int id, int l, int r, int u, int v, long double a, long double b) {
  if (v < l || r < u) return;
  down(id, l, r);
  if (u <= l && r <= v) {
    st[id].val = st[id].val * a + b * (r - l + 1);
    st[id].lz1 *= a;
    st[id].lz0 = st[id].lz0 * a + b;
    return;
  }
  int mid = (l + r) / 2;
  update(id * 2, l, mid, u, v, a, b);
  update(id * 2 + 1, mid + 1, r, u, v, a, b);
  st[id].val = st[id * 2].val + st[id * 2 + 1].val;
}
long double get(int id, int l, int r, int u, int v) {
  if (v < l || r < u) return 0;
  down(id, l, r);
  if (u <= l && r <= v) {
    return st[id].val;
  }
  int mid = (l + r) / 2;
  return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    int c;
    cin >> c;
    if (c == 1) {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      long double v1 = (long double)(r1 - l1 + 1),
                  v2 = (long double)(r2 - l2 + 1);
      long double s1 = get(1, 1, n, l1, r1);
      long double s2 = get(1, 1, n, l2, r2);
      update(1, 1, n, l1, r1, (long double)(v1 - 1.0) / v1, s2 / 1.0 / v1 / v2);
      update(1, 1, n, l2, r2, (long double)(v2 - 1.0) / v2, s1 / 1.0 / v1 / v2);
    } else {
      int l1, r1;
      cin >> l1 >> r1;
      cout << fixed << setprecision(8) << get(1, 1, n, l1, r1) << endl;
    }
  }
  return 0;
}
