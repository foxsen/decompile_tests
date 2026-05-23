#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, o = 0, t = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == 1) {
      o++;
    } else {
      t++;
    }
  }
  if (t == n) {
    cout << 0 << "\n";
  } else if (o == n) {
    cout << n / 3 << "\n";
  } else {
    if (o > t) {
      cout << t + (o - t) / 3 << "\n";
    } else {
      cout << o << "\n";
    }
  }
}
