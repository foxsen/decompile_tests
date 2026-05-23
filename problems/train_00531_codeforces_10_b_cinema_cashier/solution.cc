#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100][100];
int xc, yc;
int lolol(int x, int y) { return abs(x - xc) + abs(y - yc); }
int main() {
  cin >> n >> k;
  xc = (k + 1) / 2;
  yc = (k + 1) / 2;
  for (int asdasd = 0; asdasd < n; asdasd++) {
    int m;
    cin >> m;
    int ans = 999999999;
    int xx1, yy1;
    int p;
    for (int i = 1; i <= k; i++) {
      p = 0;
      int kol = 0;
      for (int j = 1; j <= k; j++) {
        if (j > m) {
          kol -= a[i][j - m];
          p -= lolol(i, j - m);
        }
        kol += a[i][j];
        p += lolol(i, j);
        if (j >= m && kol == 0 && p < ans) {
          ans = p;
          xx1 = i;
          yy1 = j;
        }
      }
    }
    if (ans == 999999999) {
      cout << -1 << "\n";
    } else {
      cout << xx1 << " " << yy1 - m + 1 << " " << yy1 << "\n";
      for (int j = yy1 - m + 1; j <= yy1; ++j) a[xx1][j] = 1;
    }
  }
  return 0;
}
