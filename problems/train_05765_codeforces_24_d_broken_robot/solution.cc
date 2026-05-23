#include <bits/stdc++.h>
using namespace std;
const int Mn = 1000 + 10;
int n, m, ix, iy;
long double a[Mn][Mn], c[Mn][Mn], z[Mn][Mn];
int main() {
  cin >> n >> m >> ix >> iy;
  ix--;
  iy--;
  if (m == 1) {
    cout << (n - 1 - ix) * 2 << endl;
    exit(0);
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (j == 0) {
        c[i][j] = 3 / 2.0 + a[i + 1][j] / 2;
        z[i][j] = 1 / 2.0;
      } else {
        c[i][j] = (1 + 1 / 4.0 * c[i][j - 1] + 1 / 4.0 * a[i + 1][j]) /
                  (1 - 1 / 4.0 * (1 + z[i][j - 1]));
        z[i][j] = 1 / (4 - (1 + z[i][j - 1]));
      }
      if ((m - 1) / 2 == j) {
        if (m % 2 == 0) {
          a[i][m - 1 - j] = a[i][j] = c[i][j] / (1 - z[i][j]);
        } else {
          a[i][j] =
              (c[i][j] + z[i][j] * c[i][j - 1]) / (1 - z[i][j] * z[i][j - 1]);
        }
        for (int k = j - 1; k >= 0; k--) {
          a[i][m - 1 - k] = a[i][k] = c[i][k] + z[i][k] * a[i][k + 1];
        }
        break;
      }
    }
  }
  cout << fixed << setprecision(10) << a[ix][iy] << endl;
}
