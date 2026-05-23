#include <bits/stdc++.h>
using namespace std;
pair<int, int> mat[103][103];
int org[103][103];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      mat[i][j] = make_pair(i, j);
    }
  }
  for (int i = 1; i <= q; ++i) {
    int t, r, c, x;
    pair<int, int> temp;
    cin >> t;
    if (t == 1) {
      cin >> r;
      temp = mat[r][1];
      for (int i = 1; i < m; ++i) {
        mat[r][i] = mat[r][i + 1];
      }
      mat[r][m] = temp;
    } else if (t == 2) {
      cin >> c;
      temp = mat[1][c];
      for (int i = 1; i < n; ++i) {
        mat[i][c] = mat[i + 1][c];
      }
      mat[n][c] = temp;
    } else {
      cin >> r >> c >> x;
      org[mat[r][c].first][mat[r][c].second] = x;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << org[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
