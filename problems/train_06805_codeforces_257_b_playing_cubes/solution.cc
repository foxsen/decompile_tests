#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n < m) swap(n, m);
    int a = m - 1, b = m;
    if (m & 1) {
      int x = (n - m > 0) ? (n - m) : 0;
      a += x;
    } else {
      int x = (n - m > 0) ? (n - m) : 0;
      a += x;
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
