#include <bits/stdc++.h>
using namespace std;
char mtx1[51][51];
int n1, m1;
char mtx2[51][51];
int n2, m2;
int x, y, ans, X, Y;
void input() {
  int i;
  scanf("%d%d", &n1, &m1);
  for (i = 1; i <= n1; i++) {
    scanf("%s", mtx1[i] + 1);
  }
  scanf("%d%d", &n2, &m2);
  for (i = 1; i <= n2; i++) {
    scanf("%s", mtx2[i] + 1);
  }
}
int cnt(int xi, int yi) {
  int res = 0, i, j;
  for (i = 1; i <= n1 && i + x <= n2; i++) {
    if (i + x < 1) continue;
    for (j = 1; j <= m1 && j + y <= m2; j++) {
      if (j + y < 1) continue;
      res += (mtx1[i][j] - '0') * (mtx2[i + x][j + y] - '0');
    }
  }
  return res;
}
void solv() {
  ans = -1;
  for (x = -50; x < 51; x++) {
    for (y = -50; y < 51; y++) {
      int tmp = cnt(x, y);
      if (tmp > ans) {
        ans = tmp;
        X = x;
        Y = y;
      }
    }
  }
  printf("%d %d\n", X, Y);
}
int main() {
  input();
  solv();
  return 0;
}
