#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const long double PI =
    3.141592653589793238462643383279502884197169399375105820974944;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const long long maxn = 1e5 + 5;
long long st[maxn];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    long long res = 0;
    for (long long j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        if (st[j] < i - y) res++;
        if (j * j != x) {
          if (st[x / j] < i - y) res++;
        }
        st[j] = i, st[x / j] = i;
      }
    }
    cout << res << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
