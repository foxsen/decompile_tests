#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    int l[n], r[n];
    for (i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
    }
    if (n == 1)
      cout << 0 << endl;
    else {
      sort(l, l + n);
      sort(r, r + n);
      if (l[n - 1] > r[0]) {
        int ans = abs(r[0] - l[n - 1]);
        cout << ans << endl;
      } else
        cout << 0 << endl;
    }
  }
}
