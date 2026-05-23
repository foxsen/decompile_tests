#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using ld = long double;
inline void Solve() {
  int n = 6, m = 8;
  vector<vector<char>> data(n, vector<char>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> data[i][j];
  vector<vector<int>> points(n, vector<int>(m));
  points[0][0] = 3;
  points[0][1] = 3;
  points[1][0] = 3;
  points[1][1] = 3;
  points[2][0] = 2;
  points[2][1] = 2;
  points[3][0] = 2;
  points[3][1] = 2;
  points[4][0] = 1;
  points[4][1] = 1;
  points[5][0] = 1;
  points[5][1] = 1;
  points[0][3] = 4;
  points[0][4] = 4;
  points[1][3] = 4;
  points[1][4] = 4;
  points[2][3] = 3;
  points[2][4] = 3;
  points[3][3] = 3;
  points[3][4] = 3;
  points[4][3] = 2;
  points[4][4] = 2;
  points[5][3] = 2;
  points[5][4] = 2;
  points[0][6] = 3;
  points[0][7] = 3;
  points[1][6] = 3;
  points[1][7] = 3;
  points[2][6] = 2;
  points[2][7] = 2;
  points[3][6] = 2;
  points[3][7] = 2;
  points[4][6] = 1;
  points[4][7] = 1;
  points[5][6] = 1;
  points[5][7] = 1;
  int result = 0;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((data[i][j] == '.') && (result < points[i][j])) {
        result = points[i][j];
        x = i;
        y = j;
      }
    }
  }
  data[x][y] = 'P';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << data[i][j];
    cout << '\n';
  }
}
signed main() {
  cout << fixed << setprecision(20);
  Solve();
  return 0;
}
