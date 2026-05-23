#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[105][105];
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  if (n % 2 != 0)
    cout << n << endl;
  else {
    int i, j, k, l;
    while (n % 2 == 0) {
      i = 1;
      k = n;
      for (; i <= n / 2; i++, k--) {
        for (j = 1, l = 1; j <= m; j++, l++) {
          if (a[i][j] != a[k][l]) {
            cout << n << endl;
            return 0;
          }
        }
      }
      n /= 2;
    }
    cout << n << endl;
  }
  return 0;
}
