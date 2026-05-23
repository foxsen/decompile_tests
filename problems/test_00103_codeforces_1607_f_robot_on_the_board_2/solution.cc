#include <bits/stdc++.h>
const int N = 2010;
int n, m;
char mp[N][N];
int a, b, d;
int f[N][N];
bool vis[N][N];
bool flg;
int top;
std::pair<int, int> stk[N * N];
int dx[N], dy[N];
int dfs(int x, int y) {
  stk[++top] = std::make_pair(x, y);
  if (x == 0 || y == 0 || x > n || y > m) return 0;
  if (vis[x][y]) {
    flg = true;
    return 0;
  }
  vis[x][y] = true;
  if (f[x][y]) return f[x][y];
  return f[x][y] = dfs(x + dx[mp[x][y]], y + dy[mp[x][y]]) + 1;
}
void solv() {
  a = 1, b = 1, d = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) f[i][j] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      flg = false;
      if (f[i][j] == 0) {
        top = 0;
        dfs(i, j);
      }
      if (flg) {
        std::pair<int, int> tmp = stk[top], tmp2 = stk[top];
        int val = f[tmp.first][tmp.second];
        do {
          vis[tmp2.first][tmp2.second] = false;
          f[tmp2.first][tmp2.second] = val;
          --top;
          tmp2 = stk[top];
        } while (stk[top] != tmp);
      }
      std::pair<int, int> tmp2;
      while (top) {
        tmp2 = stk[top];
        vis[tmp2.first][tmp2.second] = false;
        --top;
      }
      if (f[i][j] > d) {
        d = f[i][j];
        a = i;
        b = j;
      }
    }
  printf("%d %d %d\n", a, b, d);
}
int main() {
  dx['U'] = -1;
  dx['D'] = 1;
  dy['L'] = -1;
  dy['R'] = 1;
  int cza;
  scanf("%d", &cza);
  while (cza--) solv();
  return 0;
}
