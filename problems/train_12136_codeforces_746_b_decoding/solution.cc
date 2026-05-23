#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  string ans = "";
  for (int i = n; i > 0; --i) {
    if (i % 2 == 0) ans += s[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    if (i % 2) ans += s[i - 1];
  }
  if (n % 2 == 0) reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
