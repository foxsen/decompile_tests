#include <bits/stdc++.h>
using namespace std;
int n, k, ans, x, y, t;
int main() {
  cin >> n >> k, x = n - 1;
  while (x) x /= k, ++ans;
  cout << ans << endl;
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      x = i - 1, y = j - 1, t = 0;
      while (x != y) x /= k, y /= k, ++t;
      cout << t << " ";
    }
  }
}
