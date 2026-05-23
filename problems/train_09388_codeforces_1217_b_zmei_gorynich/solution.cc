#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int maxN = 50 + 5;
int n, x, t, a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  for (int _ = (0); _ <= ((t)-1); ++_) {
    cin >> n >> x;
    int maxD = 0, maxDiff = 0;
    for (int i = (0); i <= ((n)-1); ++i) {
      cin >> a >> b;
      maxD = max(maxD, a);
      maxDiff = max(maxDiff, a - b);
    }
    if (maxD >= x) {
      cout << 1 << endl;
    } else {
      if (maxDiff <= 0) {
        cout << -1 << endl;
      } else {
        if ((x - maxD) % maxDiff == 0)
          cout << (x - maxD) / maxDiff + 1 << endl;
        else
          cout << (x - maxD + (maxDiff - (x - maxD) % maxDiff)) / maxDiff + 1
               << endl;
      }
    }
  }
  return 0;
}
