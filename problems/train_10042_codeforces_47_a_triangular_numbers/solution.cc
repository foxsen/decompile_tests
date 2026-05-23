#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  for (int i = 1; i < 501; i++) {
    x = (i * (i + 1)) / 2;
    if (x == n) {
      cout << "YES" << endl;
      return 0;
    } else if (x > n)
      break;
  }
  cout << "NO" << endl;
  return 0;
}
