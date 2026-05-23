#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
struct SegmentTree {
 private:
  long long n;
  vector<long long> node;

 public:
  SegmentTree(vector<long long> v) {
    long long sz = (long long)v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1);
    for (long long i = (0); i < (sz); i++) node[i + n - 1] = v[i];
    for (long long i = (n - 1 - 1); i >= 0; i--)
      node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
  }
  void update(long long k, long long a) {
    k += n - 1;
    node[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      node[k] = min(node[k * 2 + 1], node[k * 2 + 2]);
    }
  }
  long long query(long long a, long long b, long long k = 0, long long l = 0,
                  long long r = -1) {
    if (r < 0) r = n;
    if (r <= a || b <= l) return (1LL << 60);
    if (a <= l && r <= b)
      return node[k];
    else {
      long long vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      long long vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return min(vl, vr);
    }
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, q;
  cin >> n >> m >> q;
  vector<long long> p(n);
  for (long long i = (0); i < (n); i++) cin >> p[i];
  vector<long long> a(m);
  for (long long i = (0); i < (m); i++) cin >> a[i];
  vector<long long> fol(n + 1);
  for (long long i = (0); i < (n); i++) fol[p[i]] = p[(i + 1) % n];
  long long d = log2(n) + 1;
  vector<vector<long long>> next(m, vector<long long>(d, (1LL << 60)));
  vector<long long> id(n + 1, (1LL << 60));
  for (long long i = (m - 1); i >= 0; i--) {
    id[a[i]] = i;
    next[i][0] = id[fol[a[i]]];
  }
  for (long long i = (1); i < (d); i++) {
    for (long long j = (0); j < (m); j++) {
      long long in = j;
      for (long long _ = (0); _ < (2); _++)
        if (in != (1LL << 60)) in = next[in][i - 1];
      next[j][i] = in;
    }
  }
  vector<long long> tmp(m);
  for (long long i = (0); i < (m); i++) {
    long long cur = i, sum = 0;
    for (long long j = (d - 1); j >= 0; j--) {
      if (sum + pow(2, j) > n - 1) continue;
      if (cur == (1LL << 60)) break;
      cur = next[cur][j];
      sum += pow(2, j);
    }
    tmp[i] = cur;
  }
  SegmentTree seg(tmp);
  for (long long _ = (0); _ < (q); _++) {
    long long l, r;
    cin >> l >> r;
    if (seg.query(l - 1, r) < r)
      cout << 1;
    else
      cout << 0;
  }
  cout << endl;
  return 0;
}
