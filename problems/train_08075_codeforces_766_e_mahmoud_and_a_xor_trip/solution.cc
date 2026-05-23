#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
template <class T>
inline T isqrt(T k) {
  T r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
template <class T>
inline T icbrt(T k) {
  T r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
struct CentroidTree {
  struct Info {
    int d;
    Info() : d(0) {}
    Info(int d) : d(d) {}
    Info(const Info& rhs) : d(rhs.d) {}
  };
  static const int maxn = 100000 + 10;
  static const int logn = 20;
  int n, rt;
  int a[maxn];
  vector<int> adj[maxn];
  int size[maxn];
  int del[maxn];
  vector<int> tree[maxn];
  int lev[maxn];
  int p[logn][maxn];
  Info info[logn][maxn];
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      tree[i].clear();
      del[i] = 0;
    }
  }
  void addedge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void dfs(int u, int p) {
    size[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
      int v = adj[u][i];
      if (v != p && !del[v]) {
        dfs(v, u);
        size[u] += size[v];
      }
    }
  }
  int findcentroid(int u) {
    dfs(u, -1);
    int p = -1, t = size[u];
    while (1) {
      pair<int, int> best;
      for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != p && !del[v]) {
          best = max(best, make_pair(size[v], v));
        }
      }
      if (best.first + best.first <= t) {
        return u;
      }
      p = u, u = best.second;
    }
  }
  void upd(int u, int dep, int p) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
      int v = adj[u][i];
      if (v != p && !del[v]) {
        info[dep][v].d = info[dep][u].d ^ a[v];
        upd(v, dep, u);
      }
    }
  }
  int divide(int u, int dep) {
    lev[u = findcentroid(u)] = dep;
    p[0][u] = u;
    info[dep][u] = Info(a[u]);
    upd(u, dep, -1);
    del[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
      int v = adj[u][i];
      if (!del[v]) {
        int w = divide(v, dep + 1);
        tree[u].push_back(w);
        p[0][w] = u;
      }
    }
    return u;
  }
  void build() { rt = divide(0, 0); }
  long long ans;
  int hs[2][20], tmp;
  void add(int u, int ix) {
    for (int k = (0); k < (20); k++) {
      hs[(((info[ix][u].d) >> (k)) & 1)][k]++;
    }
    for (int i = 0; i < (int)tree[u].size(); i++) {
      int v = tree[u][i];
      add(v, ix);
    }
  }
  void rem(int u, int ix) {
    for (int k = (0); k < (20); k++) {
      hs[(((info[ix][u].d) >> (k)) & 1)][k]--;
    }
    for (int i = 0; i < (int)tree[u].size(); i++) {
      int v = tree[u][i];
      rem(v, ix);
    }
  }
  void query(int u, int ix) {
    for (int k = (0); k < (20); k++) {
      if ((((info[ix][u].d) >> (k)) & 1)) ans += 1 << k + 1;
      int x = ((((info[ix][u].d ^ tmp)) >> (k)) & 1);
      ans += (long long)hs[1 - x][k] * (1 << k);
    }
    for (int i = 0; i < (int)tree[u].size(); i++) {
      int v = tree[u][i];
      query(v, ix);
    }
  }
  void work(int u) {
    memset(hs, 0, sizeof(hs)), tmp = a[u];
    for (int k = (0); k < (20); k++) {
      ans += (((a[u]) >> (k)) & 1) * (1 << k + 1);
    }
    int ix = lev[u];
    for (int i = 0; i < (int)tree[u].size(); i++) {
      int v = tree[u][i];
      add(v, ix);
    }
    for (int i = 0; i < (int)tree[u].size(); i++) {
      int v = tree[u][i];
      rem(v, ix);
      query(v, ix);
      add(v, ix);
    }
    for (int i = 0; i < (int)tree[u].size(); i++) {
      int v = tree[u][i];
      work(v);
    }
  }
} ct;
int n;
void solve() {
  cin >> n;
  ct.init(n);
  for (int i = (0); i < (n); i++) cin >> ct.a[i];
  for (int i = (0); i < (n - 1); i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    ct.addedge(u, v);
  }
  ct.build();
  ct.work(ct.rt);
  cout << ct.ans / 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
