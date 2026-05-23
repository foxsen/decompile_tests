#include <bits/stdc++.h>
using namespace std;
char ch[9][9];
int abs(int n) { return n < 0 ? -1 * n : n; }
int moves(int x, int y, int i, int j) {
  return max(abs(x - i) / 2, abs(y - j) / 2);
}
bool canReach(int x, int y, int i, int j) {
  if (ch[i][j] == '#')
    return false;
  else
    return (
        ((x - i) % 2 == 0 && (y - j) % 2 == 0 && ((x - i) - (y - j)) % 4 == 0)
            ? true
            : false);
}
int main() {
  int t, x1, y1, x2, y2, tmp = 1;
  cin >> t;
  for (int a = 0; a < t; a++) {
    tmp = 1;
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        cin >> ch[i][j];
        if (ch[i][j] == 'K') {
          if (tmp) {
            x1 = i;
            y1 = j;
            tmp = 0;
          } else {
            x2 = i;
            y2 = j;
          }
        }
      }
    }
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        if (canReach(x1, y1, i, j) && canReach(x2, y2, i, j) &&
            moves(x1, y1, i, j) % 2 == moves(x2, y2, i, j) % 2)
          tmp = 1;
      }
    }
    cout << (tmp ? "YES" : "NO") << endl;
  }
  return 0;
}
