#include <bits/stdc++.h>
using namespace std;
void mult(unsigned long long a[2][2], unsigned long long b[2][2],
          unsigned long long c[2][2]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      c[i][j] = 0;
      for (int k = 0; k < 2; k++) c[i][j] += a[i][k] * b[k][j];
      c[i][j] %= 1000000007;
    }
  }
}
void _copy(unsigned long long a[2][2], unsigned long long b[2][2]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) b[i][j] = a[i][j];
  }
}
int main() {
  unsigned long long n;
  cin >> n;
  unsigned long long a[2][2] = {{3, 1}, {1, 3}};
  unsigned long long res[2][2] = {{1, 0}, {0, 1}};
  while (n) {
    unsigned long long temp[2][2];
    if (n % 2 == 1) {
      _copy(res, temp);
      mult(a, temp, res);
    }
    _copy(a, temp);
    mult(temp, temp, a);
    n /= 2;
  }
  cout << res[0][0];
  return 0;
}
