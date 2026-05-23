#include <bits/stdc++.h>
int main() {
  int A[31][31];
  int n, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) scanf("%d", &A[i][j]);
  int result = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      int column = 0;
      int c = 0;
      for (; c < n; c++) column += A[c][j];
      int row = 0;
      int r = 0;
      for (; r < n; r++) row += A[i][r];
      if (column > row) result++;
    }
  printf("%d", result);
  return 0;
}
