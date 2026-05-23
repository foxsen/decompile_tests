#include <bits/stdc++.h>
using namespace std;
int max(int i, int j) { return i > j ? i : j; }
vector<int> v1, v2;
char c[25][25];
int minx, miny, a, b, ans, f;
int ju(int x1, int y1, int x2, int y2, int x, int y) {
  char cp1[25][25], cp2[25][25];
  int i, j, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      cp1[i][j] = c[x1 + i][y1 + j];
      cp2[i][j] = c[x2 + i][y2 + j];
    }
  }
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      if (c[x1 + i][y1 + j] != c[x2 + i][y2 + j]) {
        flag1++;
        break;
      }
    }
    if (flag1 == 1) break;
  }
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      if (c[x1 + i][y1 + j] != c[x2 + x - i - 1][y2 + y - j - 1]) {
        flag2++;
        break;
      }
    }
    if (flag2 == 1) break;
  }
  if (x == y) {
    if (x == 1) {
      flag3 = 1;
      flag4 = 1;
    } else {
      for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
          if (cp1[i][j] != cp2[j][x - i - 1]) {
            flag3++;
            break;
          }
        }
        if (flag3 == 1) break;
      }
      for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
          if (cp1[i][j] != cp2[y - j - 1][i]) {
            flag4++;
            break;
          }
        }
        if (flag4 == 1) break;
      }
    }
  }
  if (x == y) {
    if (flag1 && flag2 && flag3 && flag4)
      return 1;
    else
      return 0;
  } else {
    if (flag1 && flag2)
      return 1;
    else
      return 0;
  }
}
void cnt(int x, int y) {
  int xi, xj, yi, yj;
  for (xi = 0; xi < a; xi += x) {
    for (yi = 0; yi < b; yi += y) {
      for (xj = 0; xj < a; xj += x) {
        for (yj = 0; yj < b; yj += y) {
          if (xi == xj && yi == yj) continue;
          if (ju(xi, yi, xj, yj, x, y) == 0) {
            f = 1;
            break;
          }
        }
        if (f) break;
      }
      if (f) break;
    }
    if (f) break;
  }
  if (!f) ans++;
}
int main() {
  int i, j;
  while (scanf("%d%d", &a, &b) != EOF) {
    ans = 0;
    minx = a;
    miny = b;
    for (i = 0; i < a; i++) scanf(" %s", c[i]);
    v1.clear();
    v2.clear();
    for (i = 1; i <= a; i++)
      if (a % i == 0) v1.push_back(i);
    for (i = 1; i <= b; i++)
      if (b % i == 0) v2.push_back(i);
    for (i = 0; i < v1.size(); i++) {
      for (j = 0; j < v2.size(); j++) {
        f = 0;
        cnt(v1[i], v2[j]);
        if (!f) {
          if (v1[i] * v2[j] < minx * miny) {
            minx = v1[i];
            miny = v2[j];
          } else if (v1[i] * v2[j] == minx * miny) {
            if (v1[i] <= minx) {
              minx = v1[i];
              miny = v2[j];
            }
          }
        }
      }
    }
    printf("%d\n", ans);
    printf("%d %d\n", minx, miny);
  }
  return 0;
}
