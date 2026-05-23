#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  cout << n + (m - 1) << endl;
  for (int i = 1; i <= 1; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << i << ' ' << j << endl;
    }
  }
  for (int i = 2; i <= n; ++i) cout << i << ' ' << 1 << endl;
  return 0;
}
