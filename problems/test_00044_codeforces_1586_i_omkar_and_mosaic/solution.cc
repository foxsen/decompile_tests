#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, id[N][N], d[N][N], c[N];
char g[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
  if (n & 1) {
    puts("NONE");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) d[i][j] = ((i - 1) ^ (j - 1)) >> 1 & 1;
  for (int i = 1; i <= n / 2; i++) {
    for (int x = 1, y = i * 2 - 1; y >= 1; x++, y--) id[x][y] = i;
    for (int x = n - (i - 1) * 2, y = n; x <= n; x++, y--) id[x][y] = i;
    for (int x = 1, y = i * 2; y <= n; x++, y++) id[x][y] = i;
    for (int x = i * 2, y = 1; x <= n; x++, y++) id[x][y] = i;
  }
  memset(c, -1, sizeof(c));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (g[i][j] != '.') {
        int t = (g[i][j] == 'S') ^ d[i][j];
        if (c[id[i][j]] != -1 && c[id[i][j]] != t) {
          puts("NONE");
          return 0;
        }
        c[id[i][j]] = t;
      }
  for (int i = 1; i <= n / 2; i++)
    if (c[i] == -1) {
      puts("MULTIPLE");
      return 0;
    }
  puts("UNIQUE");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) putchar(c[id[i][j]] ^ d[i][j] ? 'S' : 'G');
    putchar('\n');
  }
  return 0;
}
