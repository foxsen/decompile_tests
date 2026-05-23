#include <bits/stdc++.h>
struct Point {
  int x, y;
} pos[1000][2];
char map[31][31];
bool used[100][100], found[100][100];
int count, n, m, k, square[31][31], c[1000], saved[31][31], t;
Point find(Point p) {
  int i, j;
  for (i = -1; i <= 1; i++)
    for (j = -1; j <= 1; j++)
      if (i != j && map[p.x + i][p.y + j] == map[p.x][p.y]) {
        p.x += i;
        p.y += j;
        return p;
      }
}
void pre() {
  int i, j;
  Point p, p2;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (!square[i][j] && map[i][j] != '.')
        square[i][j] = square[i][j + 1] = square[i + 1][j] =
            square[i + 1][j + 1] = ++k;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (!found[i][j] && map[i][j] != '.') {
        found[i][j] = true;
        p.x = i;
        p.y = j;
        p2 = find(p);
        found[p2.x][p2.y] = true;
        pos[++t][0] = p;
        pos[t][1] = p2;
      }
  memset(c, -1, sizeof(c));
}
void dfs(int kk, int num) {
  if (kk == k + 1) {
    memset(used, false, sizeof(used));
    for (int i = 1; i <= t; i++) {
      int s1 = square[pos[i][0].x][pos[i][0].y];
      int s2 = square[pos[i][1].x][pos[i][1].y];
      if (used[c[s1]][c[s2]]) return;
      used[c[s1]][c[s2]] = true;
      used[c[s2]][c[s1]] = true;
    }
    if (count == 0)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
          saved[i][j] = map[i][j] == '.' ? -1 : c[square[i][j]];
    count++;
    return;
  }
  if (c[kk] > -1) {
    dfs(kk + 1, num);
    return;
  }
  c[kk] = num;
  for (int i = kk + 1; i <= k; i++)
    if (c[i] == -1) {
      c[i] = num;
      dfs(kk + 1, num + 1);
      c[i] = -1;
    }
  c[kk] = -1;
}
int main() {
  scanf("%d%d", &n, &m);
  int i, j;
  for (i = 1; i <= n; i++) {
    getchar();
    for (j = 1; j <= m; j++) scanf("%c", &map[i][j]);
  }
  pre();
  dfs(1, 0);
  printf("%d\n", count * 5040);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++)
      printf("%c", map[i][j] == '.' ? '.' : ('0' + saved[i][j]));
    printf("\n");
  }
}
