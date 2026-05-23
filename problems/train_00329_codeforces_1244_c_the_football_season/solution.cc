#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int mod1 = 998244353;
const long long inf = 5e18;
long long n, p, w, d;
void solve() {
  cin >> n >> p >> w >> d;
  for (long long draw = 0; draw < w; draw++) {
    long long score = draw * d;
    long long win = (p - score) / w;
    if (win >= 0 && score >= 0 && score + win * w == p && win + draw <= n) {
      cout << win << " " << draw << " " << n - win - draw;
      return;
    }
  }
  cout << -1;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
