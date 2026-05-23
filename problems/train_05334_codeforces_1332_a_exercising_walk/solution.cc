#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long x, y, x1, y1, x2, y2;
  cin >> x >> y >> x1 >> y1 >> x2 >> y2;
  bool flag = true;
  long long lefte = a - b;
  if (x - lefte < x1 or x - lefte > x2) flag = false;
  if (x2 - x1 == 0 and (a != 0 or b != 0)) flag = false;
  long long downe = c - d;
  if (y - downe < y1 or y - downe > y2) flag = false;
  if (y2 - y1 == 0 and (c != 0 or d != 0)) flag = false;
  if (flag)
    cout << "Yes\n";
  else
    cout << "No\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) solve();
}
