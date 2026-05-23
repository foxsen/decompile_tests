#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long s = (a + 2 * b + 3 * c);
  if (s % 2 != 0)
    cout << 1;
  else
    cout << 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
