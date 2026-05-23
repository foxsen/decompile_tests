#include <bits/stdc++.h>
using namespace std;
long long a[10];
int main() {
  long long x, y, n;
  while (cin >> x >> y >> n) {
    a[1] = (x + 2 * 1000000007) % 1000000007;
    a[2] = (y + 2 * 1000000007) % 1000000007;
    for (int i = 3; i <= 6; ++i)
      a[i] = (a[i - 1] - a[i - 2] + 1000000007) % 1000000007;
    n %= 6;
    if (n == 0) n = 6;
    cout << a[n] << endl;
  }
  return 0;
}
