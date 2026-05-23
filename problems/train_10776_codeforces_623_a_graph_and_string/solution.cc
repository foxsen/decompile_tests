#include <bits/stdc++.h>
double eps = 1e-9;
using namespace std;
vector<int> g[600];
int d, a[505][505], n, m, c;
char col[505];
bool used[505];
bool DFS(int v) {
  used[v] = 1;
  for (int i = 1; i <= n; i++) {
    if (!a[v][i]) continue;
    if (col[v] == 'a' && col[i] == 'c') return 0;
    if (col[v] == 'c' && col[i] == 'a') return 0;
    if (a[v][i] && !used[i]) {
      if (!DFS(i)) return 0;
    }
  }
  return 1;
}
bool dfs(int v, char ch) {
  c++;
  col[v] = ch;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (col[to] >= 'a' && col[to] <= 'c') {
      if ((ch == 'a' && col[to] == 'a') || (ch == 'c' && col[to] == 'c'))
        return 0;
    } else {
      char x = 'a';
      if (ch == 'a') x = 'c';
      if (!dfs(to, x)) return 0;
    }
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    a[x][y] = 1;
    a[y][x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (!a[i][j]) g[i].push_back(j);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 0) {
      col[i] = 'b';
      continue;
    }
    if (col[i] >= 'a' && col[i] <= 'c') continue;
    c = 0;
    if (!dfs(i, 'a')) {
      puts("No");
      return 0;
    }
    d++;
    if (d > 1) {
      if (c > 1) {
        puts("No");
        return 0;
      } else {
        continue;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      if (!DFS(i)) {
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  for (int i = 1; i <= n; i++) cout << col[i];
}
