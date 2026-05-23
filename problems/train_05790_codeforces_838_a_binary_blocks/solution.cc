#include <bits/stdc++.h>
using namespace std;
const int M = 2505;
char S[M][M];
int n, m, sum[M][M];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", S[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) sum[i][j] = (S[i][j] == '1') + sum[i][j - 1];
    for (int j = 1; j <= m; j++) sum[i][j] += sum[i - 1][j];
  }
  int ans = n * m;
  for (int i = 2, up = max(n, m); i <= up; i++) {
    int cnt = 0, mar = i * i;
    for (int j = 1; j <= n; j += i)
      for (int k = 1; k <= m; k += i) {
        int tmp = sum[min(j + i - 1, n)][min(k + i - 1, m)] +
                  sum[j - 1][k - 1] - sum[j - 1][min(k + i - 1, m)] -
                  sum[min(j + i - 1, n)][k - 1];
        cnt += min(tmp, mar - tmp);
      }
    if (cnt < ans) ans = cnt;
  }
  printf("%d\n", ans);
  return 0;
}
