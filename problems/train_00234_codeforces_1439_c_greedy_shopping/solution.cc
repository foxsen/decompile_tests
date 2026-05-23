#include <bits/stdc++.h>
using namespace std;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vc<vc<T>>;
template <class T>
void mkuni(vector<T> &v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
long long rand_int(long long l, long long r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<long long>(l, r)(gen);
}
template <class T>
void print(T x, int suc = 1) {
  cout << x;
  if (suc == 1)
    cout << '\n';
  else
    cout << ' ';
}
template <class T>
void print(const vector<T> &v, int suc = 1) {
  for (int i = 0; i < v.size(); i++)
    print(v[i], i == (int)(v.size()) - 1 ? suc : 2);
}
const int N = 3e5 + 10;
struct Tree {
  long long l, r, lazy, sum, mi, ma;
} tree[N << 2];
void push_up(int rt) {
  tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
  tree[rt].ma = tree[rt << 1].ma;
  tree[rt].mi = tree[rt << 1 | 1].mi;
}
void build(int l, int r, int rt, vector<int> &a) {
  tree[rt].l = l, tree[rt].r = r, tree[rt].lazy = 0;
  if (l == r) {
    tree[rt].sum = tree[rt].mi = tree[rt].ma = a[l];
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, rt << 1, a);
  build(mid + 1, r, rt << 1 | 1, a);
  push_up(rt);
}
void push_down(int rt) {
  if (tree[rt].lazy) {
    int x = tree[rt].lazy, l = tree[rt].l, r = tree[rt].r;
    tree[rt].lazy = 0;
    tree[rt << 1].sum = 1ll * (tree[rt << 1].r - tree[rt << 1].l + 1) * x;
    tree[rt << 1].mi = tree[rt << 1].ma = x;
    tree[rt << 1].lazy = x;
    tree[rt << 1 | 1].sum =
        1ll * (tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1) * x;
    tree[rt << 1 | 1].mi = tree[rt << 1 | 1].ma = x;
    tree[rt << 1 | 1].lazy = x;
  }
}
void update_range(int L, int R, long long Y, int rt) {
  int l = tree[rt].l, r = tree[rt].r;
  if (tree[rt].mi >= Y || l > R) return;
  if (tree[rt].ma <= Y && r <= R) {
    tree[rt].sum = 1ll * (r - l + 1) * Y;
    tree[rt].mi = tree[rt].ma = Y;
    tree[rt].lazy = Y;
    return;
  }
  push_down(rt);
  update_range(L, R, Y, rt << 1);
  update_range(L, R, Y, rt << 1 | 1);
  push_up(rt);
}
int query_range(int L, int R, int rt, long long &Y) {
  int l = tree[rt].l, r = tree[rt].r;
  if (tree[rt].mi > Y || r < L) return 0;
  if (tree[rt].sum <= Y && l >= L) {
    Y -= tree[rt].sum;
    return r - l + 1;
  }
  push_down(rt);
  long long res = 0;
  res += query_range(L, R, rt << 1, Y);
  res += query_range(L, R, rt << 1 | 1, Y);
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(1, n, 1, a);
  while (q--) {
    long long x, y, op;
    cin >> op >> x >> y;
    if (op == 1) {
      update_range(1, x, y, 1);
    } else
      cout << query_range(x, n, 1, y) << '\n';
  }
}
