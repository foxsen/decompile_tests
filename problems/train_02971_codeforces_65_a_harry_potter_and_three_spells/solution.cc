#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a < b) swap(a, b);
  while (b) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if (b != 0 && c != 0) {
    int l = lcm(b, c);
    a *= l / b;
    d *= l / c;
    b = c = l;
    if (d != 0 && e != 0) {
      int l = lcm(d, e);
      a *= l / d;
      b *= l / d;
      c *= l / d;
      f *= l / e;
      d = e = l;
      if (a == 0)
        cout << "Ron" << endl;
      else {
        if (f == 0)
          cout << "Hermione" << endl;
        else if (f > a)
          cout << "Ron" << endl;
        else
          cout << "Hermione" << endl;
      }
    } else if (d != 0 && e == 0) {
      if (f != 0) {
        f = a;
        if (d != 0)
          cout << "Ron" << endl;
        else
          cout << "Hermione" << endl;
      } else {
        if (a == 0)
          cout << "Ron" << endl;
        else
          cout << "Hermione" << endl;
      }
    } else
      cout << "Hermione" << endl;
  } else if (b == 0 && c != 0) {
    cout << "Hermione" << endl;
  } else {
    if (d != 0)
      cout << "Ron" << endl;
    else
      cout << "Hermione" << endl;
  }
  return 0;
}
