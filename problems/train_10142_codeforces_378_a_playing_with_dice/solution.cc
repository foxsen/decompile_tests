#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a, b, c = 0, d = 0, e = 0;
  cin >> a >> b;
  for (int x = 1; x <= 6; x++) {
    if (abs(a - x) > abs(b - x)) c++;
    if (abs(a - x) < abs(b - x)) e++;
    if (abs(a - x) == abs(b - x)) d++;
  }
  cout << e << " " << d << " " << c;
  return 0;
}
