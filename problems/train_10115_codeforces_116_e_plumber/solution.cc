#include <bits/stdc++.h>
using namespace std;
const int mod = int(1e6 + 3);
vector<vector<int> > v;
char second[600000];
int n, m;
int main() {
  scanf("%d%d\n", &n, &m);
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    gets(second);
    v[i].resize(m);
    for (int j = 0; j < m; ++j) {
      v[i][j] = (second[j] == '.') ? -1 : second[j] - '0';
    }
  }
  int res = 1;
  for (int i = 0; i < n; ++i) {
    int dir = -1;
    for (int j = 0; j < m; ++j)
      if (v[i][j] != -1) {
        dir = (v[i][j] > 2) ? 1 : 0;
        if (j & 1) dir = 1 - dir;
        break;
      }
    if (dir != -1) {
      for (int j = 0; j < m; ++j)
        if (v[i][j] != -1) {
          int d2 = (v[i][j] > 2) ? 1 : 0;
          if (j & 1) d2 = 1 - d2;
          if (dir != d2) res = 0;
        }
    } else if (dir == -1)
      res = (res * 2) % mod;
  }
  for (int j = 0; j < m; ++j) {
    int dir = -1;
    for (int i = 0; i < n; ++i)
      if (v[i][j] != -1) {
        dir = (v[i][j] > 1 && v[i][j] < 4) ? 1 : 0;
        if (i & 1) dir = 1 - dir;
        break;
      }
    if (dir != -1) {
      for (int i = 0; i < n; ++i)
        if (v[i][j] != -1) {
          int d2 = (v[i][j] > 1 && v[i][j] < 4) ? 1 : 0;
          if (i & 1) d2 = 1 - d2;
          if (dir != d2) res = 0;
        }
    } else if (dir == -1)
      res = (res * 2) % mod;
  }
  printf("%d\n", res);
  return 0;
}
