#include <bits/stdc++.h>
using namespace std;
int main() {
  double r, d;
  cin >> r >> d;
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    double x, y, r1;
    cin >> x >> y >> r1;
    double c = sqrt(x * x + y * y);
    if (r - c >= r1 && r - c <= d - r1) ans++;
  }
  cout << ans << "\n";
  return 0;
}
