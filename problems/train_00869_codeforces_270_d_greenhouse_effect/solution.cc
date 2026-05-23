#include <bits/stdc++.h>
using namespace std;
int xx[5002][5002];
int lon_com_sub(int *ar, int *br, int n) {
  int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        xx[i][j] = 0;
      else if (ar[i - 1] == br[j - 1])
        xx[i][j] = xx[i - 1][j - 1] + 1;
      else {
        if (xx[i - 1][j] > xx[i][j - 1])
          xx[i][j] = xx[i - 1][j];
        else
          xx[i][j] = xx[i][j - 1];
      }
    }
  }
  return xx[n][n];
}
int main() {
  int n, m, i, x;
  int ar[5002];
  double arr[5002];
  int br[5002];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d %lf", &ar[i], &arr[i]);
    br[i] = ar[i];
  }
  sort(br, br + n);
  x = lon_com_sub(ar, br, n);
  printf("%d\n", n - x);
  return 0;
}
