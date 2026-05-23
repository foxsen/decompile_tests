#include <bits/stdc++.h>
char map[110][110];
int prime1(int i, int j) {
  if (map[i - 1][j - 1] == '*') {
    return 0;
  }
  if (map[i - 1][j] == '*') {
    return 0;
  }
  if (map[i - 1][j + 1] == '*') {
    return 0;
  }
  if (map[i][j - 1] == '*') {
    return 0;
  }
  if (map[i][j + 1] == '*') {
    return 0;
  }
  if (map[i + 1][j - 1] == '*') {
    return 0;
  }
  if (map[i + 1][j] == '*') {
    return 0;
  }
  if (map[i + 1][j + 1] == '*') {
    return 0;
  }
  return 1;
}
int prime2(int i, int j) {
  int count = 0, d;
  d = map[i][j] - '0';
  if (map[i - 1][j - 1] == '*') {
    count++;
  }
  if (map[i - 1][j] == '*') {
    count++;
  }
  if (map[i - 1][j + 1] == '*') {
    count++;
  }
  if (map[i][j - 1] == '*') {
    count++;
  }
  if (map[i][j + 1] == '*') {
    count++;
  }
  if (map[i + 1][j - 1] == '*') {
    count++;
  }
  if (map[i + 1][j] == '*') {
    count++;
  }
  if (map[i + 1][j + 1] == '*') {
    count++;
  }
  if (count == d) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  int n, m, i, j, flag = 1;
  scanf("%d %d", &n, &m);
  getchar();
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%c", &map[i][j]);
    }
    getchar();
  }
  for (j = 0; j <= m + 1; j++) {
    map[0][j] = '-';
    map[n + 1][j] = '-';
  }
  for (i = 1; i <= n; i++) {
    map[i][0] = '-';
    map[i][m + 1] = '-';
  }
  for (i = 0; i < n + 1; i++) {
    for (j = 0; j < m + 1; j++) {
      if (map[i][j] == '*') {
        continue;
      } else if (map[i][j] == '.') {
        flag = prime1(i, j);
        if (!flag) {
          break;
        }
      } else if (map[i][j] >= '0' && map[i][j] <= '9') {
        flag = prime2(i, j);
        if (!flag) {
          break;
        }
      }
    }
    if (!flag) {
      break;
    }
  }
  if (!flag) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}
