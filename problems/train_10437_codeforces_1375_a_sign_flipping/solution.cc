#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  int t, n, i;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      if ((a[i] > 0) ^ (i & 1))
        cout << -a[i] << ' ';
      else
        cout << a[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
