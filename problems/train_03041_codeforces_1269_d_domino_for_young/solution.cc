#include <bits/stdc++.h>
using namespace std;
long long a[300005];
signed main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long black = 0, wite = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 2) {
      black++;
      black += (a[i] - 1) / 2;
      wite += a[i] / 2;
    } else {
      wite++;
      wite += (a[i] - 1) / 2;
      black += a[i] / 2;
    }
  }
  cout << min(wite, black) << endl;
}
