#include <bits/stdc++.h>
using namespace std;
long long fp(long long x, long long y, long long m = 1000000007) {
  long long ANS = 1;
  if (y < 0) return 0;
  while (y) {
    if (y & 1) ANS = (ANS * x) % m;
    x = (x * x) % m;
    y >>= 1;
  }
  return ANS;
}
long long inv(long long x, long long m = 1000000007) { return fp(x, m - 2); }
long long testcases, n, m, X, Y, QQ;
vector<vector<char>> GRID;
char x;
long long COUNTDIR(long long X, long long Y) {
  long long Q = 4;
  for (long long i = -1; i <= 1; i++)
    for (long long l = -1; l <= 1; l++)
      if (abs(i) + abs(l) == 1)
        if (GRID[X + i][Y + l] == '#') Q--;
  return Q;
}
long long COUNTZ(long long X, long long Y) {
  long long Q = 0;
  for (long long i = -1; i <= 1; i++)
    for (long long l = -1; l <= 1; l++)
      if (abs(i) + abs(l) == 1)
        if (GRID[X + i][Y + l] == 'L' || GRID[X + i][Y + l] == '+') Q++;
  return Q;
}
void DFS(long long X, long long Y) {
  if (GRID[X][Y] == '#') return;
  if (GRID[X][Y] == '+' || (GRID[X][Y] == 'L' && QQ)) return;
  QQ = 1;
  long long DIR = COUNTDIR(X, Y), FR = COUNTZ(X, Y);
  if (FR + 1 >= DIR && DIR && GRID[X][Y] != 'L') {
    GRID[X][Y] = '+';
    DFS(X - 1, Y), DFS(X + 1, Y), DFS(X, Y + 1), DFS(X, Y - 1);
  }
  if (GRID[X][Y] == 'L') {
    DFS(X - 1, Y), DFS(X + 1, Y), DFS(X, Y + 1), DFS(X, Y - 1);
  }
}
int32_t main() {
  cin.tie(0), iostream::sync_with_stdio(0);
  cin >> testcases;
  while (testcases--) {
    GRID.clear();
    QQ = 0;
    cin >> n >> m;
    GRID.resize(n + 2);
    for (long long i = 1; i <= n; i++) {
      GRID[i].push_back('#');
      for (long long l = 0; l < m; l++) {
        cin >> x;
        if (x == 'L') X = i, Y = l + 1;
        GRID[i].push_back(x);
      }
      GRID[i].push_back('#');
    }
    for (long long l = 0; l <= m; l++)
      GRID[0].push_back('#'), GRID[n + 1].push_back('#');
    DFS(X, Y);
    for (long long i = 1; i <= n; i++) {
      for (long long l = 1; l <= m; l++) cout << GRID[i][l];
      cout << '\n';
    }
  }
}
