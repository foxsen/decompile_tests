#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b * c) {
      cout << -1 << '\n';
      continue;
    }
    if (c <= d) {
      cout << a << '\n';
      continue;
    }
    auto val = [&](long long x) {
      long long heal = x * b * d;
      if (x * d > c) heal += d % c * b;
      return heal < a;
    };
    long long l = 0, r = c / d + 2;
    while (l < r) {
      long long m = (l + r + 1) / 2;
      if (val(m))
        l = m;
      else
        r = m - 1;
    }
    l++;
    long long ans = l * a - d * b * (l - 1) * (l) / 2;
    cout << ans << '\n';
  }
  exit(0);
}
