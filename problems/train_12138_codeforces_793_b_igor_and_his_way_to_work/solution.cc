#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
int n, m;
char grid[1001][1001];
bool vis[1001][1001][10][10];
bool valid(int i, int j) {
  if (i == n || i < 0) return false;
  if (j == m || j < 0) return false;
  if (grid[i][j] == '*') return false;
  return true;
}
bool res = 0;
void dfs(int i, int j, int t, int d) {
  if (!valid(i, j)) return;
  if (d > 3 || res) return;
  if (vis[i][j][t][d]) return;
  if (grid[i][j] == 'T') {
    res = true;
    return;
  }
  vis[i][j][t][d] = true;
  for (int k = 0; k < 4; k++) {
    dfs(i + dx[k], j + dy[k], k, d + (k != t));
    if (res) return;
  }
}
int main() {
  cin >> n >> m;
  int si = 0, sj = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'S') {
        si = i;
        sj = j;
      }
    }
  dfs(si, sj, 5, 0);
  cout << (res ? "YES" : "NO") << endl;
  return 0;
}
