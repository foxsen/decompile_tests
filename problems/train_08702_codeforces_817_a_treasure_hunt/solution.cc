#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> a >> b;
  if (abs(x1 - x2) % a == 0 && abs(y1 - y2) % b == 0 &&
      (abs(abs(x1 - x2) / a - abs(y1 - y2) / b) % 2 == 0))
    cout << "YES";
  else
    cout << "NO";
}
