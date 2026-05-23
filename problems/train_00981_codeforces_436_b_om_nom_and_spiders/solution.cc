#include <bits/stdc++.h>
using namespace std;
char a[2345][2345];
int d[2345][2345];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int main() {
  int n, m, i, j, k;
  cin >> n >> m >> k;
  string s = "ULRD";
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (j = 1; j <= m; j++) {
    int d = 0;
    for (i = 1; i <= n; i++) {
      int t = (i - 1);
      for (k = 0; k < 4; k++) {
        int x = i + dx[k] * t;
        int y = j + dy[k] * t;
        if (x >= 1 && x <= n && y <= m && y >= 1 && a[x][y] == s[k]) d++;
      }
    }
    cout << d << " ";
  }
}
