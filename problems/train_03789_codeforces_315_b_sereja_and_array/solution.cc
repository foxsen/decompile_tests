#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, num1, num2, i, j;
  cin >> n >> m;
  int v[n];
  int acum[n];
  int acumu = 0;
  for (i = 0; i < n; i++) {
    cin >> x;
    v[i] = x;
    acum[i] = 0;
  }
  for (i = 0; i < m; i++) {
    cin >> x;
    if (x == 1) {
      cin >> num1 >> num2;
      v[num1 - 1] = num2;
      acum[num1 - 1] = acumu;
    } else if (x == 2) {
      cin >> num1;
      acumu += num1;
    } else {
      cin >> num1;
      cout << v[num1 - 1] - acum[num1 - 1] + acumu << "\n";
    }
  }
}
