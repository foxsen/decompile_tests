#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Segtree {
  int n;
  T e;
  vector<T> dat;
  typedef function<T(T a, T b)> Func;
  Func f;
  Segtree() {}
  Segtree(int n_input, Func f_input, T e_input) {
    initialize(n_input, f_input, e_input);
  }
  void initialize(int n_input, Func f_input, T e_input) {
    f = f_input;
    e = e_input;
    n = 1;
    while (n < n_input) n <<= 1;
    dat.resize(2 * n - 1, e);
  }
  void update(int k, T a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }
  T get(int k) { return dat[k + n - 1]; }
  T between(int a, int b) { return query(a, b + 1, 0, 0, n); }
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return dat[k];
    T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return f(vl, vr);
  }
  int bisect() {
    if (dat[0].first != -1) return n;
    int ans = 0, pt = 0, gain = n / 2;
    T now = e;
    while (true) {
      auto nxt = f(now, dat[2 * pt + 1]);
      if (nxt.first == -1) {
        pt = 2 * pt + 1;
      } else {
        now = nxt;
        ans += gain;
        pt = 2 * pt + 2;
      }
      gain /= 2;
      if (gain == 0) break;
    }
    return ans;
  }
};
template <typename T>
struct SparseTable {
  vector<vector<T>> dat;
  vector<int> lookup;
  void initialize(const vector<T>& v) {
    int N = v.size();
    int b = 0;
    while ((1 << b) <= N) b++;
    dat.assign(b, vector<T>(1 << b));
    for (int i = 0; i < N; i++) dat[0][i] = v[i];
    for (int i = 1; i < b; i++) {
      for (int j = 0; j + (1 << i) <= (1 << b); j++) {
        dat[i][j] = min(dat[i - 1][j], dat[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(N + 1, 0);
    for (int i = 2; i <= N; i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }
  T rmq(int l, int r) {
    r++;
    int b = lookup[r - l];
    return min(dat[b][l], dat[b][r - (1 << b)]);
  }
};
vector<int> children[200000];
int depth[200000];
int dfs_order[200000];
vector<int> euler_tour;
int euler_rev[200000];
void dfs(int i, int p, int& n, int d) {
  dfs_order[i] = n;
  depth[i] = d;
  n++;
  euler_tour.push_back(i);
  for (int j : children[i])
    if (j != p) {
      dfs(j, i, n, d + 1);
      euler_tour.push_back(i);
    }
}
SparseTable<pair<int, int>> spt;
int calc_lca(int i, int j) {
  i = euler_rev[i];
  j = euler_rev[j];
  if (i > j) swap(i, j);
  return spt.rmq(i, j).second;
}
bool isPC(int parent, int child) { return (calc_lca(parent, child) == parent); }
pair<int, int> merge_one(pair<int, int> a, int v) {
  if (a.first == -1 || v == -1) return {-1, -1};
  vector<int> nums = {a.first, a.second, v};
  sort(nums.begin(), nums.end());
  int root = calc_lca(calc_lca(a.first, a.second), v);
  if (nums[0] == root) {
    if (isPC(nums[1], nums[2])) {
      return {nums[0], nums[2]};
    } else if (calc_lca(nums[1], nums[2]) == nums[0]) {
      return {nums[1], nums[2]};
    }
  } else if (isPC(nums[1], nums[2])) {
    return {nums[0], nums[2]};
  } else if (isPC(nums[0], nums[1])) {
    return {nums[1], nums[2]};
  }
  return {-1, -1};
}
pair<int, int> merge_P(pair<int, int> a, pair<int, int> b) {
  if (a.first == -2) return b;
  if (b.first == -2) return a;
  auto ret = merge_one(merge_one(a, b.first), b.second);
  return ret;
}
int main() {
  int N, p[200000], p2[200000];
  cin >> N;
  for (int i = 0; i < N; i++) scanf("%d", &p[i]);
  for (int i = 1; i < N; i++) {
    int par;
    scanf("%d", &par);
    children[par - 1].push_back(i);
  }
  int tmp = 0;
  dfs(0, -1, tmp, 0);
  vector<pair<int, int>> v;
  for (int k = 0; k < euler_tour.size(); k++) {
    int i = euler_tour[k];
    euler_rev[dfs_order[i]] = k;
    v.emplace_back(depth[i], dfs_order[i]);
  }
  spt.initialize(v);
  Segtree<pair<int, int>> st(N, merge_P, {-2, -2});
  for (int i = 0; i < N; i++) {
    int pos = dfs_order[i];
    p2[pos] = p[i];
    st.update(p[i], {pos, pos});
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int i, j;
      scanf("%d %d", &i, &j);
      i = dfs_order[i - 1];
      j = dfs_order[j - 1];
      st.update(p2[i], {-1, -1});
      st.update(p2[j], {-1, -1});
      st.update(p2[i], {j, j});
      st.update(p2[j], {i, i});
      swap(p2[i], p2[j]);
    } else {
      int ans = st.bisect();
      printf("%d\n", ans);
    }
  }
  return 0;
}
