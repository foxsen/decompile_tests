#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, R, r;
  cin >> n >> R >> r;
  if (r > R) {
    cout << "NO\n";
    return 0;
  }
  if (n == 1) {
    cout << "YES";
    return 0;
  }
  if (r > R - r) {
    cout << "NO";
    return 0;
  }
  double al = asin(1.0 * r / (R - r)) * n;
  if (al - 1e-10 <= acos(-1.0)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
