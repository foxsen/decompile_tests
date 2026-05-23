#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long i, j, k;
  long long q;
  cin >> q;
  while (q) {
    q--;
    long long c, m, x;
    cin >> c >> m >> x;
    long long ans = min(min(c, m), x);
    if (ans == x) {
      c -= x;
      m -= x;
      ans += min(c, min(m, (m + c) / 3));
    }
    cout << ans << '\n';
  }
}
