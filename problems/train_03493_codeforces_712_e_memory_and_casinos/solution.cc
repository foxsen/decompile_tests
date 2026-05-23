#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
pair<long double, long double> st[4 * N];
int n, q;
template <typename T>
pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) {
  pair<T, T> res;
  res.first = a.first + b.first * a.second;
  res.second = a.second * b.second;
  return res;
}
void update(int id, int l, int r, int pos, long double val) {
  if (l > pos || r < pos) return;
  if (l == r) {
    st[id] = make_pair(val, val);
    return;
  }
  int mid = (l + r) >> 1;
  update(id << 1, l, mid, pos, val);
  update(id << 1 | 1, mid + 1, r, pos, val);
  st[id] = st[id << 1] + st[id << 1 | 1];
}
pair<long double, long double> getsum(int id, int l, int r, int u, int v) {
  if (l > v || r < u) return make_pair(0, 1);
  if (l >= u && r <= v) return st[id];
  int mid = (l + r) >> 1;
  pair<long double, long double> lnode = getsum(id << 1, l, mid, u, v);
  pair<long double, long double> rnode = getsum(id << 1 | 1, mid + 1, r, u, v);
  return lnode + rnode;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    long double p = (long double)a / b;
    update(1, 1, n, i, (1.0L - p) / p);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int pos, a, b;
      cin >> pos >> a >> b;
      long double p = (long double)a / b;
      update(1, 1, n, pos, (1.0L - p) / p);
    } else {
      int l, r;
      cin >> l >> r;
      long double res = 1 + getsum(1, 1, n, l, r).first;
      long double ans = (1.0L / res);
      if (ans != ans) ans = 0;
      cout << fixed << setprecision(9) << ans << "\n";
    }
  }
  return 0;
}
