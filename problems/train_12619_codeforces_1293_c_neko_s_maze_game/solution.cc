#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int32_t main() {
  int n, q;
  cin >> n >> q;
  vector<vector<bool>> a(2, vector<bool>(n));
  int cnt = 0;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    a[x][y] = !a[x][y];
    if (a[x][y]) {
      if (a[x ^ 1][y]) cnt++;
      if (y < n - 1 and a[x ^ 1][y + 1]) cnt++;
      if (y > 0 and a[x ^ 1][y - 1]) cnt++;
    } else {
      if (a[x ^ 1][y]) cnt--;
      if (y < n - 1 and a[x ^ 1][y + 1]) cnt--;
      if (y > 0 and a[x ^ 1][y - 1]) cnt--;
    }
    if (cnt)
      cout << "No"
           << "\n";
    else
      cout << "Yes"
           << "\n";
  }
  return 0;
}
