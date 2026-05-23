#include <bits/stdc++.h>
using namespace std;
struct prefSum {
  short int cnt[41][41];
  bool val[41][41];
  prefSum() {
    for (int i = 0; i < 41; i++)
      for (int j = 0; j < 41; j++) cnt[i][j] = val[i][j] = 0;
  }
  inline void build(int n, int m) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cnt[i][j] = (short int)val[i - 1][j - 1] + cnt[i - 1][j] +
                    cnt[i][j - 1] - cnt[i - 1][j - 1];
  }
  inline int query(int l1, int c1, int l2, int c2) {
    return cnt[l2 + 1][c2 + 1] + cnt[l1][c1] - cnt[l1][c2 + 1] -
           cnt[l2 + 1][c1];
  }
};
int main() {
  int n, m, q, a, b, c, d;
  scanf("%d%d%d", &n, &m, &q);
  char str[m + 1];
  prefSum init;
  prefSum **Q = new prefSum *[n + 1];
  for (int i = 0; i <= n; i++) Q[i] = new prefSum[m + 1];
  getchar();
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    for (int j = 0; j < m; j++)
      if (str[j] == '1') init.val[i][j] = 1;
  }
  init.build(n, m);
  for (int h = 1; h <= n; h++)
    for (int w = 1; w <= m; w++)
      for (int i = 0; i <= n - h; i++)
        for (int j = 0; j <= m - w; j++)
          if (init.query(i, j, i + h - 1, j + w - 1) == 0)
            Q[h][w].val[i][j] = 1;
  for (int h = 1; h <= n; h++)
    for (int w = 1; w <= m; w++) Q[h][w].build(n, m);
  int ****memo = new int ***[41];
  for (int i = 0; i < 41; i++) {
    memo[i] = new int **[41];
    for (int j = 0; j < 41; j++) {
      memo[i][j] = new int *[41];
      for (int k = 0; k < 41; k++) {
        memo[i][j][k] = new int[41];
        for (int l = 0; l < 41; l++) memo[i][j][k][l] = -1;
      }
    }
  }
  while (q--) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    a--, b--, c--, d--;
    int cnt = 0;
    if (memo[a][b][c][d] == -1) {
      int d1 = 1 + c - a, d2 = 1 + d - b;
      for (int h = 1; h <= d1; h++)
        for (int w = 1; w <= d2; w++)
          cnt += Q[h][w].query(a, b, 1 + c - h, 1 + d - w);
      memo[a][b][c][d] = cnt;
    } else
      cnt = memo[a][b][c][d];
    printf("%d\n", cnt);
  }
}
