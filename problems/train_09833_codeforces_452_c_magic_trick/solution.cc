#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  double n, m;
  cin >> n >> m;
  cout.precision(17);
  cout << fixed;
  if (n == 1 && m == 1)
    cout << 1. << endl;
  else
    cout << (1. + (n - 1.) * (m - 1.) / (n * m - 1.)) / n << endl;
  return 0;
}
