#include <bits/stdc++.h>
using namespace std;
inline void boost() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  cout.tie(0);
}
const long long maxn = 1e5 + 123;
const long long inf = 1e9 + 123;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
int main() {
  boost();
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, d, y, x;
    cin >> n >> x >> y >> d;
    int mn = inf;
    if (abs(y - x) % d == 0) {
      mn = min(mn, abs(y - x) / d);
    }
    if (abs(y - 1) % d == 0 && abs(x - 1) % d == 0) {
      mn = min(abs(x - 1) / d + abs(y - 1) / d, mn);
    }
    if (abs(y - 1) % d == 0 && abs(x - 1) % d != 0) {
      mn = min(abs(x - 1) / d + abs(y - 1) / d + 1, mn);
    }
    if (abs(y - n) % d == 0 && abs(x - n) % d == 0) {
      mn = min(abs(x - n) / d + abs(y - n) / d, mn);
    }
    if (abs(y - n) % d == 0 && abs(x - n) % d != 0) {
      mn = min(abs(x - n) / d + abs(y - n) / d + 1, mn);
    }
    if (mn == inf) {
      cout << "-1\n";
    } else {
      cout << mn << "\n";
    }
  }
  return 0;
}
