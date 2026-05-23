#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[1005];
  while (cin >> n) {
    int f = 0, j = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0)
        f++;
      else
        j++;
    }
    if (n == 1) {
      if (a[0] == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (n > 1) {
      if (f == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
