#include <bits/stdc++.h>
using namespace std;
int c[5][5], n;
long long f[45][5][5];
int main() {
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) {
      cin >> c[i][j];
      f[0][i][j] = 0;
    }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      for (int k = 1; k <= 3; k++)
        if (j != k) {
          f[i][j][k] =
              (f[i][j][k] <
                       f[i - 1][j][6 - j - k] + c[j][k] + f[i - 1][6 - j - k][k]
                   ? f[i][j][k]
                   : f[i - 1][j][6 - j - k] + c[j][k] + f[i - 1][6 - j - k][k]);
          f[i][j][k] =
              (f[i][j][k] < f[i - 1][j][k] + c[j][6 - j - k] + f[i - 1][k][j] +
                                c[6 - j - k][k] + f[i - 1][j][k]
                   ? f[i][j][k]
                   : f[i - 1][j][k] + c[j][6 - j - k] + f[i - 1][k][j] +
                         c[6 - j - k][k] + f[i - 1][j][k]);
        }
    }
  }
  cout << f[n][1][3] << endl;
  return 0;
}
