#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, b = 0, s = 0, z = 0;
  cin >> a >> b;
  if (a > b) {
    z = b;
    s = a -= b;
    cout << z << " " << s / 2;
    return 0;
  }
  if (b > a) {
    z = a;
    s = b -= a;
    cout << z << " " << s / 2;
    return 0;
  }
  if (a == b) {
    z = b;
    s = a -= b;
    cout << z << " " << s / 2;
    return 0;
  }
  return 0;
}
