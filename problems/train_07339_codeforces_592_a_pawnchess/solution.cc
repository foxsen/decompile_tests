#include <bits/stdc++.h>
using namespace std;
char a[10][10];
int main(void) {
  for (int i = 0; i < 8; i++) {
    cin >> a[i];
  }
  int b = 10, w = 10;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (a[i][j] == 'B') {
        int f = 0;
        for (int k = i + 1; k < 8; k++) {
          if (a[k][j] != '.') f = 1;
        }
        if (!f) b = min(8 - i - 1, b);
      }
      if (a[i][j] == 'W') {
        int f = 0;
        for (int k = i - 1; k >= 0; k--) {
          if (a[k][j] != '.') f = 1;
        }
        if (!f) w = min(i, w);
      }
    }
  }
  if (b < w)
    cout << "B";
  else
    cout << "A";
}
