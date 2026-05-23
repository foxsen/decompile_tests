#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 7;
const long long WN = 1e5 + 7;
const long long inf = 1e9 + 7;
const long long INF = 2e18 + 7;
const long long MOD = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  cout << 2 << ' ';
  long long last = 2;
  for (long long i = 2; i <= n; i++) {
    cout << last + 1 << ' ';
    last = last + 1;
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
