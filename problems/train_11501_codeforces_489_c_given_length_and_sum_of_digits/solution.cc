#include <bits/stdc++.h>
using namespace std;
int a[107], b[107];
int ans = 0;
int main() {
  int m, s;
  while (~scanf("%d %d", &m, &s)) {
    if (m * 9 < s || (s == 0 && m != 1))
      cout << "-1 -1" << endl;
    else {
      memset(a, 0, sizeof(a));
      memset(b, 0, sizeof(b));
      int m1 = m, s1 = s;
      for (int i = m - 1; i >= 0; --i) {
        if (s > 9) {
          a[i] = 9;
          s -= 9;
        } else if (i != 0) {
          a[i] = s - 1;
          s = 1;
        } else {
          a[i] = s;
        }
      }
      for (int i = 0; i < m; ++i) {
        if (s1 > 9) {
          b[i] = 9;
          s1 -= 9;
        } else {
          b[i] = s1;
          s1 = 0;
        }
      }
      for (int i = 0; i < m; ++i) {
        printf("%d", a[i]);
      }
      printf(" ");
      for (int i = 0; i < m; ++i) {
        printf("%d", b[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
