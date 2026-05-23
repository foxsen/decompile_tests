#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 2 * (a + b);
  ans = min(ans, 2 * (a + c));
  ans = min(ans, 2 * (b + c));
  ans = min(ans, a + b + c);
  cout << ans << '\n';
  return 0;
}
