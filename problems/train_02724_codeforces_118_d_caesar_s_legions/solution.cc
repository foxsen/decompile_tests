#include <bits/stdc++.h>
using namespace std;
long long int a[110][110][2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, ans = 0, mod = 100000000, k, n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  a[0][0][0] = 1;
  a[0][0][1] = 1;
  for (i = 0; i <= n1; i++) {
    for (j = 0; j <= n2; j++) {
      for (k = 1; k <= min(k1, i); k++) {
        a[i][j][0] += a[i - k][j][1];
        a[i][j][0] = a[i][j][0] % mod;
      }
      for (k = 1; k <= min(k2, j); k++) {
        a[i][j][1] += a[i][j - k][0];
        a[i][j][1] = a[i][j][1] % mod;
      }
    }
  }
  cout << (a[n1][n2][0] + a[n1][n2][1]) % mod;
  return 0;
}
