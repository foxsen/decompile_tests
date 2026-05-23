#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = 1e18;
template <typename Monoid>
struct SegmentTree {
  using F = function<Monoid(Monoid, Monoid)>;
  long long sz;
  vector<Monoid> seg;
  const F f;
  const Monoid M1;
  SegmentTree(long long n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while (sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
  void set(long long k, const Monoid &x) { seg[k + sz] = x; }
  void build() {
    for (long long k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
  void update(long long k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
  void add(long long k, const Monoid &x) {
    k += sz;
    seg[k] += x;
    while (k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
  Monoid query(long long a, long long b) {
    Monoid L = M1, R = M1;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = f(L, seg[a++]);
      if (b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
  Monoid operator[](const long long &k) const { return seg[k + sz]; }
};
long long n, k, q, p[200000][5];
signed main() {
  cin >> n >> k;
  auto f = [&](const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
    return pair<long long, long long>(min(a.first, b.first),
                                      max(a.second, b.second));
  };
  vector<SegmentTree<pair<long long, long long> > > segs;
  for (long long i = 0; i < (1 << k); i++) {
    SegmentTree<pair<long long, long long> > seg(
        n, f, pair<long long, long long>{INT_MAX, -INT_MAX});
    segs.emplace_back(seg);
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < k; j++) {
      scanf("%lld", &p[i][j]);
    }
    for (long long j = 0; j < (1 << k); j++) {
      long long tmp = 0;
      for (long long l = 0; l < k; l++) {
        if (j & (1 << l))
          tmp += p[i][l];
        else
          tmp -= p[i][l];
      }
      segs[j].set(i, pair<long long, long long>{tmp, tmp});
    }
  }
  for (long long i = 0; i < (1 << k); i++) segs[i].build();
  cin >> q;
  while (q--) {
    long long c;
    scanf("%lld", &c);
    if (c == 1) {
      long long i;
      scanf("%lld", &i);
      i--;
      for (long long j = 0; j < k; j++) {
        scanf("%lld", &p[i][j]);
      }
      for (long long j = 0; j < (1 << k); j++) {
        long long tmp = 0;
        for (long long l = 0; l < k; l++) {
          if (j & (1 << l))
            tmp += p[i][l];
          else
            tmp -= p[i][l];
        }
        segs[j].update(i, pair<long long, long long>{tmp, tmp});
      }
    } else {
      long long l, r;
      scanf("%lld %lld", &l, &r);
      l--;
      r--;
      long long ans = 0;
      for (long long i = 0; i < (1 << k); i++) {
        pair<long long, long long> tmp = segs[i].query(l, r + 1);
        ans = max(ans, tmp.second - tmp.first);
      }
      printf("%lld\n", ans);
    }
  }
}
