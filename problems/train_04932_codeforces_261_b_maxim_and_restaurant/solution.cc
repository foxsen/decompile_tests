#include <bits/stdc++.h>
using namespace std;
int N, P;
int A[50];
long long dp[52][52][52][52];
double C[52][52];
double fac[52], res;
int main() {
  scanf("%d", &N);
  for (int(i) = 0; (i) < (N); (i)++) scanf("%d", &A[i]);
  scanf("%d", &P);
  C[0][0] = 1;
  for (int(i) = (1); (i) < (52); (i)++)
    for (int(j) = 0; (j) < (i + 1); (j)++) {
      if (j) C[i][j] = C[i - 1][j - 1];
      C[i][j] += C[i - 1][j];
    }
  fac[0] = 1;
  for (int(i) = (1); (i) < (52); (i)++) fac[i] = fac[i - 1] * i;
  for (int(can) = (0); (can) < (P + 1); (can)++) {
    memset((dp), (0), sizeof(dp));
    dp[0][can][0][0] = 1;
    for (int(i) = 0; (i) < (N); (i)++)
      for (int(j) = 0; (j) < (can + 1); (j)++)
        for (int(k) = 0; (k) < (N + 1); (k)++)
          for (int(l) = 0; (l) < (N + 1); (l)++)
            if (dp[i][j][k][l]) {
              if (A[i] >= P - can)
                dp[i + 1][j][k + 1][l] += dp[i][j][k][l];
              else
                dp[i + 1][j][k][l] += dp[i][j][k][l];
              if (A[i] <= j) dp[i + 1][j - A[i]][k][l + 1] += dp[i][j][k][l];
            }
    for (int(k) = 0; (k) < (N + 1); (k)++)
      for (int(l) = 0; (l) < (N + 1); (l)++) {
        if (dp[N][0][k][l] && l - 1 >= 0)
          res += fac[N - l] * l * fac[l - 1] * dp[N][0][k][l];
      }
  }
  printf("%.12f\n", res / fac[N]);
}
