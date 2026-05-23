#include <bits/stdc++.h>
using namespace std;
long long int C[1001][1001];
long long int nCr(int n, int r) {
  if (n < r) {
    return 0;
  }
  if (r > n - r) r = n - r;
  if (r == 0) return 1;
  if (C[n][r] != -1) return C[n][r];
  C[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % 1000000007;
  return C[n][r];
}
int main() {
  memset(C, -1, sizeof C);
  int n = ({
    int _x;
    scanf("%d", &_x);
    _x;
  }),
      m = ({
        int _x;
        scanf("%d", &_x);
        _x;
      }),
      k = ({
        int _x;
        scanf("%d", &_x);
        _x;
      });
  long long ans;
  if (2 * k > n - 1 || 2 * k > m - 1)
    ans = 0;
  else
    ans = (nCr(n - 1, 2 * k) * nCr(m - 1, 2 * k)) % 1000000007;
  cout << ans << endl;
  return 0;
}
