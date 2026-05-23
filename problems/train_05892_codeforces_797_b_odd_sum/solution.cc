#include <bits/stdc++.h>
using namespace std;
const long double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230781640628620899863;
const long long INF = 1e9 + 7;
void edit() { return; }
void solve() {
  int n, x, sum = 0, mx = -100000, mxo = 100000;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x >= 0) {
      sum += x;
      if (x & 1) mxo = min(mxo, x);
    } else if (x & 1)
      mx = max(mx, x);
  }
  if (sum & 1)
    cout << sum;
  else {
    cout << max(sum + mx, sum - mxo);
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
