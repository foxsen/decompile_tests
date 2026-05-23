#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MAX = 300010;
const long long MOD = (long long)1e9 + 7;
const long long INF = 1e9;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
struct Segtree {
  vector<long long> seg, lazy;
  long long n, LOG;
  Segtree(long long n = 0) {
    this->n = n;
    LOG = ceil(log2(n));
    seg.assign(2 * n, 0);
    lazy.assign(2 * n, 0);
  }
  long long merge(long long a, long long b) { return a + b; }
  void poe(long long p, long long x, long long tam, bool prop = 1) {
    seg[p] += x * tam;
    if (prop and p < n) lazy[p] += x;
  }
  void sobe(long long p) {
    for (long long tam = 2; p /= 2; tam *= 2) {
      seg[p] = merge(seg[2 * p], seg[2 * p + 1]);
      poe(p, lazy[p], tam, 0);
    }
  }
  void prop(long long p) {
    long long tam = 1 << (LOG - 1);
    for (long long s = LOG; s; s--, tam /= 2) {
      long long i = p >> s;
      if (lazy[i]) {
        poe(2 * i, lazy[i], tam);
        poe(2 * i + 1, lazy[i], tam);
        lazy[i] = 0;
      }
    }
  }
  void build() {
    for (long long i = n - 1; i; i--)
      seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
  }
  long long query(long long a, long long b) {
    long long ret = 0;
    for (prop(a += n), prop(b += n); a <= b; ++a /= 2, --b /= 2) {
      if (a % 2 == 1) ret = merge(ret, seg[a]);
      if (b % 2 == 0) ret = merge(ret, seg[b]);
    }
    return ret;
  }
  void update(long long a, long long b, long long x) {
    long long a2 = a += n, b2 = b += n, tam = 1;
    for (; a <= b; ++a /= 2, --b /= 2, tam *= 2) {
      if (a % 2 == 1) poe(a, x, tam);
      if (b % 2 == 0) poe(b, x, tam);
    }
    sobe(a2), sobe(b2);
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < (long long)n; i++) cin >> v[i];
  Segtree st1 = Segtree(MAX);
  Segtree st2 = Segtree(MAX);
  Segtree st3 = Segtree(MAX);
  long long res = 0;
  for (long long k = 0; k < n; k++) {
    res += v[k] * st1.query(v[k], MAX - 1);
    res += v[k] * st1.query(1, v[k]) - st2.query(v[k], v[k]);
    res += st3.query(1, v[k]);
    res += st3.query(v[k], MAX - 1);
    for (long long m = 1; m * v[k] < MAX; m++) {
      res -= m * v[k] * st1.query(m * v[k], min((m + 1) * v[k] - 1, MAX - 1));
    }
    st1.update(v[k], v[k], 1);
    for (long long m = 1; m * v[k] < MAX; m++) {
      st2.update(m * v[k], min((m + 1) * v[k] - 1, MAX - 1), m * v[k]);
    }
    st3.update(v[k], v[k], v[k]);
    cout << res << " ";
  }
  cout << '\n';
  return 0;
}
