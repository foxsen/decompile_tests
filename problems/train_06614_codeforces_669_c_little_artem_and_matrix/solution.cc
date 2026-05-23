#include <bits/stdc++.h>
using namespace std;
vector<int> row, col, A;
vector<pair<pair<int, int>, int> > mat;
int grid[111][111];
void shift_up(int c, int n, int m) {
  int i, temp;
  temp = grid[n][c];
  for (i = n; i > 1; i--) grid[i][c] = grid[i - 1][c];
  grid[1][c] = temp;
}
void shift_left(int r, int n, int m) {
  int i, temp;
  temp = grid[r][m];
  for (i = m; i > 1; i--) grid[r][i] = grid[r][i - 1];
  grid[r][1] = temp;
}
int main() {
  int n, q, i, m, j, type, id, r, c, x;
  cin >> n >> m >> q;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) grid[i][j] = 0;
  while (q--) {
    cin >> type;
    A.push_back(type);
    if (type == 2) {
      cin >> id;
      col.push_back(id);
    } else if (type == 1) {
      cin >> id;
      row.push_back(id);
    } else {
      cin >> r >> c >> x;
      mat.push_back(make_pair(make_pair(r, c), x));
    }
  }
  int im = mat.size() - 1, ir = row.size() - 1, ic = col.size() - 1;
  for (i = A.size() - 1; i >= 0; i--) {
    type = A[i];
    if (type == 2) {
      c = col[ic];
      ic--;
      shift_up(c, n, m);
    } else if (type == 1) {
      r = row[ir];
      ir--;
      shift_left(r, n, m);
    } else {
      r = mat[im].first.first;
      c = mat[im].first.second;
      x = mat[im].second;
      grid[r][c] = x;
      im--;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) cout << grid[i][j] << " ";
    cout << '\n';
  }
}
