#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, c[10][10], i, mx = 0, h, j, k, l, r;
  int a[10] = {1, 2, 3, 4, 5};
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      cin >> c[i][j];
    }
  }
  for (h = 0; h < 5; h++) {
    for (i = 0; i < 5; i++) {
      if (i == h) continue;
      for (j = 0; j < 5; j++) {
        if (j == i || j == h) continue;
        for (k = 0; k < 5; k++) {
          if (k == h || k == i || k == j) continue;
          for (l = 0; l < 5; l++) {
            if (l == h || l == i || l == j || l == k) continue;
            r = c[h][i] + c[i][h] + c[i][j] + c[j][i] +
                2 * (c[j][k] + c[k][j]) + 2 * (c[k][l] + c[l][k]);
            if (r > mx) mx = r;
          }
        }
      }
    }
  }
  cout << mx << endl;
}
