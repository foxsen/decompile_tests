#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long p, y;
  cin >> p >> y;
  long long i;
  vector<long long> v;
  long long z = 0, j, g = 0, ans;
  for (i = y; i >= p + 1; i--) {
    for (j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        if (j <= p) {
          z = 1;
          break;
        }
      }
    }
    if (z == 1) {
      z = 0;
      continue;
    } else {
      g = 1;
      ans = i;
      break;
    }
  }
  if (g == 1) {
    cout << ans << "\n";
  } else {
    cout << -1 << "\n";
  }
}
