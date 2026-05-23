#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
class dsu {
 public:
  vector<int> p;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    dsu d(2 * n);
    vector<int> x(n - 1), y(n - 1), w(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      cin >> x[i] >> y[i] >> w[i];
      x[i]--;
      y[i]--;
      if (w[i] == -1) continue;
      if (__builtin_popcount(w[i]) & 1) {
        d.unite(x[i] + n, y[i]);
        d.unite(x[i], y[i] + n);
      } else {
        d.unite(x[i] + n, y[i] + n);
        d.unite(x[i], y[i]);
      }
    }
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      u--;
      v--;
      if (w) {
        d.unite(u + n, v);
        d.unite(u, v + n);
      } else {
        d.unite(u + n, v + n);
        d.unite(u, v);
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i)
      if (d.get(i) == d.get(i + n)) ok = false;
    if (ok) {
      cout << "YES" << '\n';
      for (int i = 0; i < n; ++i) {
        if (d.get(i) == d.get(0) || d.get(i + n) == d.get(0)) continue;
        d.unite(i, 0);
        d.unite(i + n, n);
      }
      for (int i = 0; i < n - 1; ++i) {
        if (w[i] == -1) {
          if (d.get(x[i]) == d.get(y[i]))
            w[i] = 0;
          else
            w[i] = 1;
        }
        cout << x[i] + 1 << ' ' << y[i] + 1 << ' ' << w[i] << '\n';
      }
    } else
      cout << "NO" << '\n';
  }
  return 0;
}
