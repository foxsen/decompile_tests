#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, i, j, k, x, y, t;
  long long int a, b;
  cin >> t;
  while (t--) {
    cin >> k >> n >> a >> b;
    k -= n * a;
    if (k > 0) {
      cout << n << endl;
      continue;
    }
    k = -k;
    k++;
    x = a - b;
    m = (k + x - 1) / x;
    if (m > n) {
      cout << -1 << endl;
    } else {
      cout << n - m << endl;
    }
  }
}
