#include <bits/stdc++.h>
using namespace std;
const long long LINF = 4e18;
const int mxN = 2e5 + 10, INF = 2e9, mod = (1 ? 1e9 + 7 : 998244353);
long long p[mxN];
const long long is_query = -(1LL << 62);
struct line {
  long long m, b;
  mutable function<const line*()> succ;
  bool operator<(const line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const line* s = succ();
    if (!s) return 0;
    long long x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};
struct dynamic_hull : public multiset<line> {
  const long long inf = LLONG_MAX;
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    long long v1 = (x->b - y->b);
    if (y->m == x->m)
      v1 = x->b > y->b ? inf : -inf;
    else
      v1 /= (y->m - x->m);
    long long v2 = (y->b - z->b);
    if (z->m == y->m)
      v2 = y->b > z->b ? inf : -inf;
    else
      v2 /= (z->m - y->m);
    return v1 >= v2;
  }
  void insert_line(long long m, long long b) {
    auto y = insert({m, b});
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) {
      erase(y);
      return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  long long eval(long long x) {
    auto l = *lower_bound((line){x, is_query});
    return l.m * x + l.b;
  }
};
struct segtree {
  long long n;
  vector<dynamic_hull> tree;
  void init(long long s, long long* arr) {
    n = s;
    tree = vector<dynamic_hull>(4 * s);
    init(1, 0, n - 1, arr);
  }
  void init(int s, int l, int r, long long* arr) {
    for (int i = l; i <= r; i++)
      tree[s].insert_line(-arr[i], -(i * arr[i] - p[i]));
    if (l == r) return;
    int m = (l + r) / 2;
    init(2 * s, l, m, arr);
    init(2 * s + 1, m + 1, r, arr);
  }
  long long query(int l, int r, int x) { return query(1, 0, n - 1, l, r, x); }
  long long query(int s, int l, int r, int a, int b, int x) {
    if (l > r || l > b || r < a) return LINF;
    if (l >= a && r <= b) return -tree[s].eval(x);
    int m = (l + r) / 2;
    long long q1 = query(2 * s, l, m, a, b, x);
    long long q2 = query(2 * s + 1, m + 1, r, a, b, x);
    return min(q1, q2);
  }
};
long long n, q, a[mxN];
segtree st;
void Solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  p[0] = a[0];
  for (int i = 1; i < n; i++) p[i] = p[i - 1] + a[i];
  st.init(n, a);
  cin >> q;
  while (q--) {
    int i, j;
    cin >> i >> j;
    --j;
    cout << p[j] + st.query(j - i + 1, j, i - j) << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(12) << fixed;
  int t = 1;
  while (t--) Solve();
  return 0;
}
