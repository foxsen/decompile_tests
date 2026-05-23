#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int n1 = max(a, b) - min(a, b) - 1;
  int x = min(a, b);
  int t = x - 1;
  if (t > n1) {
    cout << "-1" << endl;
    return;
  }
  int t2 = n1 - t;
  int maxLim = max(a, b) + t2;
  if (maxLim & 1) {
    cout << "-1" << endl;
    return;
  }
  if (c > maxLim) {
    cout << "-1" << endl;
    return;
  }
  int ans;
  if (c >= max(a, b)) {
    ans = c - (max(a, b) - min(a, b));
    if (ans <= 0) {
      ans = maxLim - ans;
    }
  } else {
    ans = c + (max(a, b) - min(a, b));
    if (ans > maxLim) {
      ans = ans % maxLim;
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
