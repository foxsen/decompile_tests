#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 2e18;
void add(int64_t& a, int64_t b) { a = min(INF, a + b); }
void mul(int64_t& a, int64_t b) {
  if (b == 0) {
    a = 0;
  } else if (a > INF / b) {
    a = INF;
  } else {
    a *= b;
  }
}
template <typename T>
struct BIT {
  int n;
  vector<T> dat;
  BIT(int n = 0) { initialize(n); }
  void initialize(int nin) {
    n = nin;
    dat.resize(n, 0);
  }
  T sum(int i) {
    T s = 0;
    while (i >= 0) {
      s += dat[i];
      i = (i & (i + 1)) - 1;
    }
    return s;
  }
  T sum_between(int i, int j) { return sum(j) - sum(i - 1); }
  void plus(int i, T x) {
    while (i < n) {
      dat[i] += x;
      i |= i + 1;
    }
  }
  int lower_bound(T x) {
    if (x < 0) return -1;
    int ret = -1;
    int k = 1;
    while (2 * k <= n) k <<= 1;
    for (; k > 0; k >>= 1) {
      if (ret + k < n && dat[ret + k] < x) {
        x -= dat[ret + k];
        ret += k;
      }
    }
    return ret + 1;
  }
};
struct UnionFind {
  vector<int> par;
  vector<int> sz;
  UnionFind(int n = 0) {
    if (n > 0) initialize(n);
  }
  void initialize(int n) {
    par.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i;
      sz[i] = 1;
    }
  }
  int find(int x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = find(par[x]);
    }
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] > sz[y]) swap(x, y);
    par[x] = y;
    sz[y] += sz[x];
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return sz[find(x)]; }
};
int main() {
  static int64_t fact[51];
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= 50; i++) {
    fact[i] = fact[i - 1];
    mul(fact[i], i);
  }
  static int64_t dp[51], dpi[51][51];
  dp[0] = dp[1] = dpi[1][1] = 1;
  for (int i = 2; i <= 50; i++) {
    dp[i] = dpi[i][1] = dp[i - 1];
    for (int j = 2; j <= i; j++) {
      int64_t res = fact[j - 2];
      mul(res, dp[i - j]);
      add(dp[i], res);
      dpi[i][j] = res;
    }
  }
  auto perm = [&](int N, int64_t D) {
    cerr << D << endl;
    vector<int> A(N);
    A[0] = N - 1;
    BIT<int> bit(N);
    UnionFind uf(N);
    for (int i = 0; i < N - 1; i++) bit.plus(i, 1);
    for (int i = 1; i < N; i++) {
      int take = 0;
      if (i < N - 1)
        for (int k = 0; k < N; k++)
          if (uf.same(i, k) && bit.sum_between(k, k) == 1) {
            take = k;
            bit.plus(take, -1);
            break;
          }
      int64_t f = (i == N - 1 ? 1 : fact[N - i - 2]);
      int r = D / f;
      int p = bit.lower_bound(r + 1);
      A[i] = p;
      uf.unite(i, p);
      bit.plus(p, -1);
      D -= f * r;
      bit.plus(take, 1);
    }
    return A;
  };
  int T;
  cin >> T;
  while (T--) {
    int N;
    int64_t K;
    cin >> N >> K;
    if (dp[N] < K) {
      cout << -1 << endl;
      continue;
    }
    K--;
    BIT<int> bit(N + 1);
    for (int i = 1; i <= N; i++) bit.plus(i, 1);
    vector<int> ans;
    int i = N;
    while (i) {
      for (int j = 1; j <= i; j++) {
        int64_t res = dpi[i][j];
        if (res <= K) {
          K -= res;
        } else {
          int64_t q = dp[i - j];
          int64_t r = K / q;
          auto pm = perm(j, r);
          vector<int> del;
          for (int a : pm) {
            int p = bit.lower_bound(a + 1);
            ans.push_back(p);
            del.push_back(p);
          }
          for (int p : del) bit.plus(p, -1);
          K -= r * q;
          i -= j;
          break;
        }
      }
    }
    for (int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
  }
  return 0;
}
