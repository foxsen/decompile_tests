#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int inf = 1e9;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, m, a[N];
pair<int, int> f[N][20];
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return make_pair(min(a.first, b.first), max(a.second, b.second));
}
struct segtree {
  pair<int, int> tr[N << 2];
  void build(int o, int l, int r, int k) {
    if (l == r) {
      tr[o] = f[l][k];
      return;
    }
    int mid = (l + r) >> 1;
    build((o << 1), l, mid, k);
    build((o << 1 | 1), mid + 1, r, k);
    tr[o] = tr[(o << 1)] + tr[(o << 1 | 1)];
  }
  pair<int, int> query(int o, int l, int r, int L, int R) {
    if (L <= l && r <= R) return tr[o];
    int mid = (l + r) >> 1;
    pair<int, int> ret = make_pair(inf, -inf);
    if (L <= mid) ret = ret + query((o << 1), l, mid, L, R);
    if (R > mid) ret = ret + query((o << 1 | 1), mid + 1, r, L, R);
    return ret;
  }
} tr[20];
int main() {
  n = gi();
  if (n == 1) return puts("0"), 0;
  for (int i = 1; i <= n; i++) a[i] = a[i + n] = a[i + n + n] = gi();
  m = 3 * n;
  for (int i = 1; i <= m; i++)
    f[i][0] = make_pair(max(1, i - a[i]), min(m, i + a[i]));
  for (int j = 1; j <= 19; j++) {
    tr[j - 1].build(1, 1, m, j - 1);
    for (int i = 1; i <= m; i++)
      f[i][j] = tr[j - 1].query(1, 1, m, f[i][j - 1].first, f[i][j - 1].second);
  }
  tr[19].build(1, 1, m, 19);
  for (int i = n + 1; i <= n + n; i++) {
    int ans = 0, l = i, r = i;
    for (int j = 19; j >= 0; j--) {
      pair<int, int> x = tr[j].query(1, 1, m, l, r);
      if (x.second - x.first + 1 < n)
        l = x.first, r = x.second, ans += (1 << j);
    }
    printf("%d ", ans + 1);
  }
  return 0;
}
