#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
template <typename TI, typename TX, typename TL>
class SegmentTree {
 public:
  struct node {
    long long x = -INF;
    node(){};
    node(const TX &y) { set(y); };
    void set(const TX &y) { x = y; };
  };
  node merge(const node &a, const node &b) {
    node ans;
    ans.x = max(a.x, b.x);
    return ans;
  }
  template <typename T>
  node merge(const node &a, const T &x, int n) {
    node ans = a;
    ans.x += x;
    return ans;
  }
  int n;
  vector<node> tree;
  vector<TL> lazy;
  const TL undefined = 0;
  inline void unite(int v, int a, int b) { tree[v] = merge(tree[a], tree[b]); }
  void build(int v, int l, int r, const vector<TX> &A) {
    if (l == r) {
      tree[v].set(A[l]);
      return;
    }
    int left = v << 1, right = v << 1 | 1;
    int md = (l + r) >> 1;
    build(left, l, md, A);
    build(right, md + 1, r, A);
    unite(v, left, right);
  }
  void build(int v, int l, int r) {
    if (l == r) {
      return;
    }
    int left = v << 1, right = v << 1 | 1;
    int md = (l + r) >> 1;
    build(left, l, md);
    build(right, md + 1, r);
    unite(v, left, right);
  }
  SegmentTree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(4 * n);
    lazy.assign(4 * n, undefined);
    build(1, 0, n - 1);
  }
  SegmentTree(const vector<TX> &A) {
    n = A.size();
    assert(n > 0);
    tree.resize(4 * n);
    lazy.assign(4 * n, undefined);
    build(1, 0, n - 1, A);
  }
  node get(int v, int ll, int rr, int l, int r) {
    if (l > r) {
      return node();
    }
    if (l == ll && r == rr) {
      return tree[v];
    }
    push(v, ll, rr);
    int left = v << 1, right = v << 1 | 1;
    int md = (ll + rr) >> 1;
    node a = get(left, ll, md, l, min(md, r));
    node b = get(right, md + 1, rr, max(md + 1, l), r);
    return merge(a, b);
  }
  template <typename T>
  inline void uplazy(int v, int ll, int rr, const T &x) {
    tree[v] = merge(tree[v], x, rr - ll + 1);
    lazy[v] += x;
  }
  void push(int v, int ll, int rr) {
    if (lazy[v] != undefined) {
      if (ll != rr) {
        int left = v << 1, right = v << 1 | 1;
        int md = (ll + rr) >> 1;
        uplazy(left, ll, md, lazy[v]);
        uplazy(right, md + 1, rr, lazy[v]);
      }
      lazy[v] = undefined;
    }
  }
  template <typename T>
  void update(int v, int ll, int rr, int l, int r, const T &x) {
    if (l > r) {
      return;
    }
    if (ll == l && rr == r) {
      uplazy(v, ll, rr, x);
    } else {
      push(v, ll, rr);
      int left = v << 1, right = v << 1 | 1;
      int md = (ll + rr) >> 1;
      update(left, ll, md, l, min(md, r), x);
      update(right, md + 1, rr, max(md + 1, l), r, x);
      unite(v, left, right);
    }
  }
  node get(int i) {
    assert(i >= 0 && i < n);
    node ans = get(1, 0, n - 1, i, i);
    return ans;
  }
  node get(int l, int r) {
    r = min(n - 1, r);
    l = max(0, l);
    assert(l <= r);
    assert(l >= 0 && r < n);
    node ans = get(1, 0, n - 1, l, r);
    return ans;
  }
  template <typename T>
  void update(int p, const T &x) {
    assert(p >= 0 && p < n);
    update(1, 0, n - 1, p, p, x);
  }
  template <typename T>
  void update(int l, int r, const T &x) {
    r = min(n - 1, r);
    l = max(0, l);
    assert(l <= r);
    assert(l >= 0 && r < n);
    update(1, 0, n - 1, l, r, x);
  }
};
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long>> A(n + 2, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  vector<long long> dp(m);
  for (int i = n - 1; i >= 0; i--) {
    vector<long long> dp2(m);
    SegmentTree<long long, long long, long long> sg(dp);
    long long res = 0;
    for (int j = 0; j < k - 1; j++) {
      sg.update(j - k + 1, j, -A[i + 1][j]);
      res += A[i][j] + A[i + 1][j];
    }
    for (int j = 0; j < m; j++) {
      if (j + k <= m) {
        res += A[i][j + k - 1] + A[i + 1][j + k - 1];
        sg.update(j, j + k - 1, -A[i + 1][j + k - 1]);
      }
      auto tr = sg.get(0, m - 1).x;
      tr = max(tr, 0LL);
      dp2[j] = res + tr;
      sg.update(j - k + 1, j, A[i + 1][j]);
      res -= A[i][j] + A[i + 1][j];
    }
    dp2.swap(dp);
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}
