#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100000];
int main() {
  int n, res = -1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = 0, y = 0;
      for (int k = 0; k < n; k++) {
        int f = (a[j] - a[i]) * (b[k] - b[j]) - (b[j] - b[i]) * (a[k] - a[j]);
        x = min(x, f);
        y = max(y, f);
      }
      if (x < 0 && y > 0) res = max(res, y - x);
    }
  }
  cout << fixed << setprecision(9) << res / 2.0 << endl;
}
