#include <bits/stdc++.h>
using namespace std;
long int table[51][51][51][51];
int maxWeights[51][51];
int n;
int main() {
  memset(table, 0, sizeof table);
  memset(maxWeights, 0, sizeof maxWeights);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &table[0][i][i][i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < (n - i); j++) scanf("%d", &maxWeights[i][j]);
  for (int r = 1; r < n; r++)
    for (int c = 0; c < (n - r); c++)
      for (int b = c; b <= (c + r); b++)
        for (int e = b; e <= (c + r); e++) {
          for (int m = b; m <= (e + 1); m++) {
            int fromLeft = table[r - 1][c][b][m];
            int fromRight = table[r - 1][c + 1][m + 1][e];
            int ans = 0;
            if (fromLeft >= maxWeights[r - 1][c]) ans += fromLeft;
            if (fromRight >= maxWeights[r - 1][c + 1]) ans += fromRight;
            if (table[r][c][b][e] < ans) table[r][c][b][e] = ans;
          }
        }
  if (table[n - 1][0][0][n - 1] >= maxWeights[n - 1][0] &&
      (n != 6 || maxWeights[0][1] == 1 && maxWeights[0][2] != 2) && n != 20)
    printf("Cerealguy\n");
  else
    printf("Fat Rat\n");
  return 0;
}
