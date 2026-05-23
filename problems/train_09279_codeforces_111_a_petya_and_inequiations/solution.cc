#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y, i, ans;
  while (cin >> n >> x >> y) {
    if (y < n) {
      cout << -1 << endl;
      continue;
    }
    if (y - n + 1 > 1000000)
      ans = 1000000;
    else
      ans = y - n + 1;
    if ((n - 1) + ans * ans >= x) {
      for (i = 1; i < n; i++) cout << 1 << endl;
      cout << y - n + 1 << endl;
    } else
      cout << -1 << endl;
  }
}
