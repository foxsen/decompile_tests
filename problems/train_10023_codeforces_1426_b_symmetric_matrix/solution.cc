#include <bits/stdc++.h>
using namespace std;
using ii = pair<int64_t, int64_t>;
using vb = vector<bool>;
using vi = vector<int64_t>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
struct tile {
  int64_t a, b, c, d;
};
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t n, m;
    cin >> n >> m;
    vector<tile> v(n);
    bool sym = false;
    for (int64_t i = 0; i < n; i++) {
      cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d;
      if (v[i].b == v[i].c) {
        sym = true;
      }
    }
    bool even = (m % 2 == 0);
    cout << ((even and sym) ? "YES" : "NO") << "\n";
  }
}
