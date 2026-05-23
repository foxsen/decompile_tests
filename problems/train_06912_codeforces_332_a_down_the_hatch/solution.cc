#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long INFLL = 1e12;
const long long MOD = 1000000007;
const long double eps = 1e-6;
const long long MOD2 = (1 << 30) + 1;
const long long dosz = 5e5;
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
string s;
void solve() {
  long long n;
  cin >> n;
  cin >> s;
  long long ans = 0;
  for (long long i = n; i < s.size(); i += n) {
    if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]) {
      ans++;
    }
  }
  cout << ans;
}
signed main() {
  fast_io();
  long long q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
