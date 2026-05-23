#include <bits/stdc++.h>
using namespace std;
int main() {
  long double s;
  cin >> s;
  long double a, b, c;
  cin >> a >> b >> c;
  if (a == 0 && b == 0 && c == 0) {
    cout << 0 << " " << 0 << " " << 0;
    return 0;
  }
  long double n1 = s * a, n2 = s * b, n3 = s * c, d1 = a + b + c,
              d2 = a + b + c, d3 = a + b + c;
  n1 /= d1;
  n2 /= d2;
  n3 /= d3;
  cout << fixed << setprecision(20) << n1 << " " << n2 << " " << n3;
  return 0;
}
