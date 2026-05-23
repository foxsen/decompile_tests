#include <bits/stdc++.h>
int main() {
  int map[5][5], sum[5][5], flag = 0, mini;
  int i, j, n;
  scanf("%d", &n);
  for (i = 1; i <= 4; i++)
    for (j = 1; j <= 4; j++) scanf("%d", &map[i][j]);
  for (i = 1; i <= 4; i++) {
    sum[i][1] = map[i][1] + map[i][3];
    sum[i][2] = map[i][1] + map[i][4];
    sum[i][3] = map[i][2] + map[i][3];
    sum[i][4] = map[i][2] + map[i][4];
  }
  for (i = 1; i <= 4; i++) {
    for (j = 1; j <= 4; j++)
      if (sum[i][j] <= n) {
        flag = 1;
        break;
      }
    if (flag) break;
  }
  if (flag == 0) {
    printf("-1\n");
    return 0;
  }
  if (map[i][1] >= map[i][2])
    mini = map[i][2];
  else
    mini = map[i][1];
  printf("%d %d %d\n", i, mini, n - mini);
  return 0;
}
