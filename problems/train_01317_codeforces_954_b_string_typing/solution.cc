#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = n;
  for (int i = 0; i < n / 2; i++) {
    string temp1 = s.substr(0, i + 1);
    string temp2 = s.substr(i + 1, i + 1);
    if (temp1 == temp2) ans = min(ans, n - i);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
