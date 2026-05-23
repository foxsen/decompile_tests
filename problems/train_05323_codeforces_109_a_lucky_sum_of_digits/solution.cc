#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x = (2 * n) % 7, y = (n - 4 * x) / 7;
  if (y < 0) {
    cout << "-1";
    return 0;
  }
  while (1) {
    if (x > 0) {
      cout << "4";
      x--;
    } else if (y > 0) {
      cout << "7";
      y--;
    } else
      break;
  }
  return 0;
}
