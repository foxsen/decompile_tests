#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)(1e9 + 7);
char grid[1005][1005];
int main() {
  int h, w;
  cin >> h >> w;
  int r[h], c[w];
  for (int i = 0; i < h; i++) cin >> r[i];
  for (int i = 0; i < w; i++) cin >> c[i];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      grid[i][j] = 'n';
    }
  }
  for (int i = 0; i < h; i++) {
    if (r[i] > w) {
      cout << 0 << endl;
      return 0;
    }
    for (int j = 0; j < r[i]; j++) {
      if (grid[i][j] == 'e') {
        cout << 0 << endl;
        return 0;
      }
      grid[i][j] = 'f';
    }
    if (grid[i][r[i]] == 'f') {
      cout << 0 << endl;
      return 0;
    }
    grid[i][r[i]] = 'e';
  }
  for (int j = 0; j < w; j++) {
    if (c[j] > h) {
      cout << 0 << endl;
      return 0;
    }
    for (int i = 0; i < c[j]; i++) {
      if (grid[i][j] == 'e') {
        cout << 0 << endl;
        return 0;
      }
      grid[i][j] = 'f';
    }
    if (grid[c[j]][j] == 'f') {
      cout << 0 << endl;
      return 0;
    }
    grid[c[j]][j] = 'e';
  }
  long long ans = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == 'f' || grid[i][j] == 'e') continue;
      ans *= 2;
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
