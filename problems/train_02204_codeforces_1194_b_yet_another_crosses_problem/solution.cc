#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;
    string str[n + 5];
    for (int i = 0; i < n; i++) {
      cin >> str[i];
    }
    int hor = INT_MAX, ver = INT_MAX;
    vector<int> row, col;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < m; j++) {
        if (str[i][j] == '.') {
          cnt++;
        }
      }
      hor = min(hor, cnt);
    }
    for (int i = 0; i < m; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (str[j][i] == '.') {
          cnt++;
        }
      }
      ver = min(ver, cnt);
    }
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < m; j++) {
        if (str[i][j] == '.') {
          cnt++;
        }
      }
      if (cnt == hor) {
        row.push_back(i);
      }
    }
    for (int i = 0; i < m; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (str[j][i] == '.') {
          cnt++;
        }
      }
      if (ver == cnt) {
        col.push_back(i);
      }
    }
    int ans = hor + ver;
    for (int i = 0; i < row.size(); i++) {
      int j;
      for (j = 0; j < col.size(); j++) {
        if (str[row[i]][col[j]] == '.') {
          ans--;
          break;
        }
      }
      if (j != col.size()) break;
    }
    cout << ans;
    if (q) cout << '\n';
  }
  return 0;
}
