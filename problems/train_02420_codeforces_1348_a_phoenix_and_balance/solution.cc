#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, sum;
  cin >> t;
  while (t--) {
    cin >> n;
    sum = 0;
    int p = n / 2 + 1;
    for (int i = p; p <= n; p++) {
      int x = n - i + 1;
      int s = 1;
      for (int k = 0; k < p - x; k++) s *= 2;
      sum += s;
    }
    cout << sum << endl;
  }
  return 0;
}
