#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long n;
  cin >> n;
  unsigned long add = 5, multi = 2;
  unsigned long s = 1, i = 0, l = 0, p = 0, r = 0, h = 0;
  if (n < 6) {
    if (n == 1)
      cout << "Sheldon\n";
    else if (n == 2)
      cout << "Leonard\n";
    else if (n == 3)
      cout << "Penny\n";
    else if (n == 4)
      cout << "Rajesh\n";
    else
      cout << "Howard\n";
  } else {
    while (1) {
      s += add;
      if (n < s) {
        cout << "Howard\n";
        break;
      }
      l = s + multi;
      if (n < l) {
        cout << "Sheldon\n";
        break;
      }
      p = l + multi;
      if (n < p) {
        cout << "Leonard\n";
        break;
      }
      r = p + multi;
      if (n < r) {
        cout << "Penny\n";
        break;
      }
      h = r + multi;
      if (n < h) {
        cout << "Rajesh\n";
        break;
      }
      add *= 2;
      multi *= 2;
    }
  }
}
