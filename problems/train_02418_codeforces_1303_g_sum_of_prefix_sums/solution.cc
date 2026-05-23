#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const long long is_query = -(1LL << 62);
struct Line {
  long long m, b;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    long long x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};
struct CHT : public multiset<Line> {
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return (x->b - y->b) * (z->m - y->m) >= (y->b - z->b) * (y->m - x->m);
  }
  void insert_line(long long m, long long b) {
    auto y = insert({m, b});
    if (bad(y)) {
      erase(y);
      return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    while (y != begin() && bad(prev(y))) erase(prev(y));
    if (y != begin()) prev(y)->succ = [=] { return &*y; };
  }
  long long eval(long long x) {
    auto l = *lower_bound((Line){x, is_query});
    return l.m * x + l.b;
  }
};
long long n, ans, a[N], sz[N], big[N];
bool dead[N];
vector<int> nei[N];
void input() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    nei[--u].push_back(--v);
    nei[v].push_back(u);
  }
  for (int i = 0; i < n; i++) cin >> a[i];
}
void dfs(int v, int par, long long len, long long sigma1, long long sigma2,
         long long sum,
         vector<pair<pair<long long, long long>, pair<long long, long long> > >*
             vec) {
  vec->push_back(pair<pair<long long, long long>, pair<long long, long long> >(
      pair<long long, long long>(sum, len),
      pair<long long, long long>(sigma1, sigma2)));
  for (int u : nei[v])
    if (dead[u] == false && u != par)
      dfs(u, v, len + 1, sigma1 + (len + 1) * a[u], sigma2 + (sum + a[u]),
          sum + a[u], vec);
}
void go(int v, int par = -1) {
  sz[v] = 1;
  big[v] = -1;
  for (int u : nei[v])
    if (dead[u] == false && u != par) {
      go(u, v);
      if (big[v] == -1 || sz[u] > sz[big[v]]) big[v] = u;
      sz[v] += sz[u];
    }
}
int get_cen(int v) {
  go(v);
  int n = sz[v];
  while (big[v] != -1 && 2 * sz[big[v]] > n) v = big[v];
  return v;
}
void solve(int v = 0) {
  int cen = get_cen(v);
  dead[cen] = true;
  CHT data;
  data.insert_line(1, a[cen]);
  for (int u : nei[cen])
    if (dead[u] == false) {
      solve(u);
      vector<pair<pair<long long, long long>, pair<long long, long long> > >
          vec;
      dfs(u, cen, 1, a[u], a[u], a[u], &vec);
      for (pair<pair<long long, long long>, pair<long long, long long> > p :
           vec) {
        ans = max(ans, p.second.first + data.eval(p.first.first));
        ans = max(ans, (p.first.second + 1) * a[cen] + p.second.second);
      }
      for (pair<pair<long long, long long>, pair<long long, long long> > p :
           vec)
        data.insert_line(p.first.second + 1,
                         p.second.second + (p.first.second + 1) * a[cen]);
    }
  data.clear();
  data.insert_line(1, a[cen]);
  reverse(nei[cen].begin(), nei[cen].end());
  for (int u : nei[cen])
    if (dead[u] == false) {
      vector<pair<pair<long long, long long>, pair<long long, long long> > >
          vec;
      dfs(u, cen, 1, a[u], a[u], a[u], &vec);
      for (pair<pair<long long, long long>, pair<long long, long long> > p :
           vec)
        ans = max(ans, p.second.first + data.eval(p.first.first));
      for (pair<pair<long long, long long>, pair<long long, long long> > p :
           vec)
        data.insert_line(p.first.second + 1,
                         p.second.second + (p.first.second + 1) * a[cen]);
    }
  dead[cen] = false;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  input();
  solve();
  cout << ans << '\n';
}
