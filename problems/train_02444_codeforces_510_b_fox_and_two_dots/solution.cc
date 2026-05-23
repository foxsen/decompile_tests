#include <bits/stdc++.h>
using namespace std;
int n, m;
char board[50][51];
bool bb[26], visit[50][50];
bool dfs(int d, int x, int y, char a) {
  if (d != 0 && x + 1 < n && board[x + 1][y] == a) {
    if (visit[x + 1][y]) return true;
    visit[x + 1][y] = true;
    if (dfs(1, x + 1, y, a)) return true;
  }
  if (d != 1 && x - 1 >= 0 && board[x - 1][y] == a) {
    if (visit[x - 1][y]) return true;
    visit[x - 1][y] = true;
    if (dfs(0, x - 1, y, a)) return true;
  }
  if (d != 2 && y + 1 < m && board[x][y + 1] == a) {
    if (visit[x][y + 1]) return true;
    visit[x][y + 1] = true;
    if (dfs(3, x, y + 1, a)) return true;
  }
  if (d != 3 && y - 1 >= 0 && board[x][y - 1] == a) {
    if (visit[x][y - 1]) return true;
    visit[x][y - 1] = true;
    if (dfs(2, x, y - 1, a)) return true;
  }
  return false;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", board[i]);
    for (int j = 0; j < m; j++) bb[board[i][j] - 'A'] = true;
  }
  for (char a = 0; a < 26; a++) {
    if (!bb[a]) continue;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (board[i][j] == a + 'A') visit[i][j] = false;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (board[i][j] == a + 'A' && !visit[i][j]) {
          visit[i][j] = true;
          if (dfs(-1, i, j, a + 'A')) {
            puts("Yes");
            return 0;
          }
        }
  }
  puts("No");
  return 0;
}
