#include <bits/stdc++.h>
using namespace std;
int n, m, tot;
int a[1010][1010];
int s0[1010][1010], s1[1010][1010], d[1010][1010];
int readInt() {
  char c;
  int n = 0;
  c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    n = n * 10 + c - '0';
    c = getchar();
  }
  return n;
}
int fa[1010 * 1010];
int sx, sy;
int ok(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
int find(int i) {
  if (fa[i] == i)
    return i;
  else
    return find(fa[i]);
}
int can(int k) {
  int i, j, x, y, mx, my, tmp;
  int dd = 0, fmx;
  fmx = (sx - 1) / k, mx = (n - sx) / k, my = (m - sy) / k, dd = 0;
  for (i = -fmx; i <= mx; i++)
    for (j = 0; j <= my; j++) {
      d[i + fmx][j] = 0;
      int num = (i + fmx) * (my + 1) + j;
      fa[num] = num;
    }
  for (i = -fmx; i <= mx; i++) {
    for (j = 0; j <= my; j++) {
      x = sx + i * k;
      y = sy + j * k;
      if (!a[x][y]) continue;
      dd++;
      if (ok(x + k, y) && a[x + k][y]) {
        tmp = s0[x + k - 1][y] - s0[x][y];
        if (tmp == k - 1) {
          d[i + fmx][j]++;
          d[i + 1 + fmx][j]++;
          dd += k - 1;
          fa[find((i + fmx) * (my + 1) + j)] =
              fa[find((i + 1 + fmx) * (my + 1) + j)];
        } else if (tmp > 0)
          return 0;
      }
      if (ok(x, y + k) && a[x][y + k]) {
        tmp = s1[x][y + k - 1] - s1[x][y];
        if (tmp == k - 1) {
          d[i + fmx][j]++;
          d[i + fmx][j + 1]++;
          dd += k - 1;
          fa[find((i + fmx) * (my + 1) + j)] =
              fa[find((i + fmx) * (my + 1) + j + 1)];
        } else if (tmp > 0)
          return 0;
      }
    }
  }
  if (dd != tot) return 0;
  int cnt = 0, thef = find((0 + fmx) * (my + 1) + 0);
  for (i = -fmx; i <= mx; i++)
    for (j = 0; j <= my; j++) {
      cnt += d[i + fmx][j] & 1;
    }
  for (i = -fmx; i <= mx; i++)
    for (j = 0; j <= my; j++) {
      x = sx + i * k;
      y = sy + j * k;
      if (!a[x][y]) continue;
      if (find((i + fmx) * (my + 1) + j) != thef) return 0;
    }
  return cnt <= 2;
}
int main() {
  int i, j, k;
  while (scanf("%d %d", &n, &m) != EOF) {
    tot = 0;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        tot += a[i][j];
      }
    if ((n < 3 && m < 3) || tot == 1) {
      printf("-1\n");
    } else {
      for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
          s0[i][j] = s0[i - 1][j] + a[i][j];
          s1[i][j] = s1[i][j - 1] + a[i][j];
        }
      sx = sy = 0;
      for (j = 1; j <= m; j++) {
        for (i = 1; i <= n; i++) {
          if (a[i][j]) {
            sx = i;
            sy = j;
            break;
          }
        }
        if (sx) break;
      }
      int flag = 1;
      for (k = 2; k <= min(n, m); k++) {
        if (can(k)) {
          if (flag)
            flag = 0;
          else
            printf(" ");
          printf("%d", k);
        }
      }
      if (flag)
        printf("-1\n");
      else
        printf("\n");
    }
  }
  return 0;
}
