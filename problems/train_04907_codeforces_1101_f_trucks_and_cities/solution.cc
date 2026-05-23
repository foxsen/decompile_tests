#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int MAXN = 401;
const int INF = 1e9 + 5;
int city[MAXN], dp[MAXN][MAXN][MAXN];
int main() {
  for (int i = 0; i < int(MAXN); i++)
    for (int j = 0; j < int(MAXN); j++)
      for (int k = 0; k < int(MAXN); k++) dp[i][j][k] = INF;
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < int(n); i++) scanf("%d", &city[i]);
  for (int i = 0; i < int(n); i++)
    for (int j = int(i); j < int(n); j++) dp[0][i][j] = city[j] - city[i];
  for (int k = int(1); k < int(n + 1); k++)
    for (int i = 0; i < int(n); i++) {
      int ind = i;
      for (int j = int(i); j < int(n); j++) {
        dp[k][i][j] = max(dp[k - 1][i][ind], city[j] - city[ind]);
        while (ind + 1 <= j && max(dp[k - 1][i][ind + 1],
                                   city[j] - city[ind + 1]) < dp[k][i][j]) {
          ind++;
          dp[k][i][j] =
              min(dp[k][i][j], max(dp[k - 1][i][ind], city[j] - city[ind]));
        }
      }
    }
  long long rta = 0;
  for (int i = 0; i < int(m); i++) {
    int s, f, c, r;
    scanf("%d %d %d %d", &s, &f, &c, &r);
    s--;
    f--;
    int val = dp[r][s][f];
    rta = max(rta, (long long)val * c);
  }
  printf("%lld", rta);
  return 0;
}
