#include <bits/stdc++.h>
using namespace std;
long long n, m, x, sum = 0, j = 1;
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x;
    if (x >= j) {
      sum += x - j;
    } else {
      sum += n - j + x;
    }
    j = x;
  }
  cout << sum << endl;
  return 0;
}
