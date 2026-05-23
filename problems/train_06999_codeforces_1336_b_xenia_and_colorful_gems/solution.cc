#include <bits/stdc++.h>
using namespace std;
void hi() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void bye() {}
long long nr, nb, ng, m, ans = 9e18;
long long sq(int x) { return 1ll * x * x; }
void solve(vector<int> a, vector<int> b, vector<int> c) {
  for (auto x : a) {
    auto y = lower_bound(b.begin(), b.end(), x);
    auto z = upper_bound(c.begin(), c.end(), x);
    if (y == b.end() || z == c.begin()) {
      continue;
    }
    z--;
    ans = min(ans, sq(x - *y) + sq(*y - *z) + sq(*z - x));
  }
}
int main() {
  hi();
  long long test_cases = 1;
  cin >> test_cases;
  for (long long t = 1; t <= test_cases; t++) {
    cin >> nr >> nb >> ng;
    vector<int> r, b, g;
    ans = 9e18;
    for (int i = 0; i < nr; i++) cin >> m, r.push_back(m);
    for (int i = 0; i < nb; i++) cin >> m, b.push_back(m);
    for (int i = 0; i < ng; i++) cin >> m, g.push_back(m);
    sort(r.begin(), r.end()), sort(b.begin(), b.end()),
        sort(g.begin(), g.end());
    solve(r, g, b);
    solve(r, b, g);
    solve(g, b, r);
    solve(g, r, b);
    solve(b, r, g);
    solve(b, g, r);
    cout << ans << "\n";
    r.clear(), b.clear(), g.clear();
  }
  bye();
  return 0;
}
