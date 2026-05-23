#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c;
  d = b * b - 4 * a * c;
  if (a == 0) {
    double h = (-c) / b;
    cout << fixed << setprecision(20) << h;
    return 0;
  }
  double n1 = (-b - sqrt(d)) / a;
  double n2 = (-b + sqrt(d)) / a;
  cout << fixed << setprecision(20) << max(n1, n2) / 2 << endl;
  if (n1 != n2) cout << fixed << setprecision(20) << min(n1, n2) / 2;
  return 0;
}
