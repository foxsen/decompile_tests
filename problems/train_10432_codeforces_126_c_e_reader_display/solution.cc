#include <bits/stdc++.h>
using namespace std;
int n, i, j, a[2001][2001], b[2001][2001], ans, J, C, A[2001][2001],
    B[2001][2001];
char c[2001][2001];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) cin >> c[i][j];
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(A, 0, sizeof(A));
  memset(B, 0, sizeof(B));
  ans = 0;
  for (J = n; J >= 2; J--) {
    i = 1;
    j = J;
    for (C = 1; C <= n + 1 - J; C++) {
      if (c[i][j] == '0' && (a[i][j] + b[i][j]) % 2 == 1 ||
          c[i][j] == '1' && (a[i][j] + b[i][j]) % 2 == 0) {
        ans++;
        a[i][j - 1] = a[i][j] + 1;
        b[i + 1][j] = b[i][j] + 1;
      } else {
        a[i][j - 1] = a[i][j];
        b[i + 1][j] = b[i][j];
      }
      i++;
      j++;
    }
    i = n;
    j = n + 1 - J;
    for (C = 1; C <= n + 1 - J; C++) {
      if (c[i][j] == '0' && (A[i][j] + B[i][j]) % 2 == 1 ||
          c[i][j] == '1' && (A[i][j] + B[i][j]) % 2 == 0) {
        ans++;
        A[i][j + 1] = A[i][j] + 1;
        B[i - 1][j] = B[i][j] + 1;
      } else {
        A[i][j + 1] = A[i][j];
        B[i - 1][j] = B[i][j];
      }
      i--;
      j--;
    }
  }
  for (i = 1; i <= n; i++) {
    if (c[i][i] == '0' && (a[i][i] + b[i][i] + A[i][i] + B[i][i]) % 2 == 1 ||
        c[i][i] == '1' && (a[i][i] + b[i][i] + A[i][i] + B[i][i]) % 2 == 0)
      ans++;
  }
  cout << ans << endl;
}
