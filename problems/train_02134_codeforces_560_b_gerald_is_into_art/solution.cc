#include <bits/stdc++.h>
using namespace std;
bool fit(int a1, int b1, int a2, int b2, int a3, int b3) {
  if ((a2 + a3 <= a1 && b2 <= b1 && b3 <= b1) ||
      (a2 + b3 <= a1 && b2 <= b1 && a3 <= b1) ||
      (b2 + a3 <= a1 && a2 <= b1 && b3 <= b1) ||
      (b2 + b3 <= a1 && a2 <= b1 && a3 <= b1))
    return true;
  else
    return false;
}
int main(int argc, char *argv[]) {
  int a1, b1, a2, b2, a3, b3;
  cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
  if (fit(a1, b1, a2, b2, a3, b3) || fit(b1, a1, a2, b2, a3, b3))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
