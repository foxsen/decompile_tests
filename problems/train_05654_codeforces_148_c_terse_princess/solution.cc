#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, c, d, e, sum = 1;
  cin >> n >> b >> c;
  if (b == n - 1 && b != 0) {
    cout << "-1";
  } else if (c == 0) {
    if (n == 1)
      cout << "1";
    else {
      cout << "1 1 ";
      d = 2;
      for (int i = 2; i < n; i++) {
        if (b == 0) {
          cout << "1 ";
        } else {
          cout << d << " ";
          d++;
          b--;
        }
      }
    }
  } else {
    cout << "1 ";
    for (int i = 1; i < n; i++) {
      if (b == 0 && c == 0) {
        cout << "1 ";
      } else if (c != 0) {
        sum *= 2;
        cout << sum << " ";
        c--;
      } else {
        sum++;
        cout << sum << " ";
        b--;
      }
    }
  }
}
