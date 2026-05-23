#include <bits/stdc++.h>
using namespace std;
int a[105], mark[105];
int main() {
  int n, k, t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (!mark[a[i]]) cnt++, mark[a[i]] = 1;
    }
    int ans = 0;
    if (cnt <= k)
      cout << 1 << endl;
    else if (k == 1) {
      if (cnt == 1)
        cout << 1 << endl;
      else
        cout << -1 << endl;
    } else {
      cnt -= k;
      if (cnt == 0)
        cout << 1 << endl;
      else if (cnt <= (k - 1))
        cout << 2 << endl;
      else if (cnt % (k - 1))
        cout << cnt / (k - 1) + 2 << endl;
      else
        cout << cnt / (k - 1) + 1 << endl;
    }
    memset(mark, 0, sizeof(mark));
  }
  return 0;
}
