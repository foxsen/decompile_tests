#include <bits/stdc++.h>
using namespace std;
bool a[41][41];
long long d[41][41][41][41];
long long cld[41][41][41][41];
int cldh[41][41][41][41];
int lines_x[41][41];
int lines_y[41][41];
void print(int w, int e, int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d ", d[w][e][i][j]);
    }
    printf("\n");
  }
}
int main() {
  int n, m, q;
  scanf("%d %d %d\n", &n, &m, &q);
  char ch;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%c", &(ch));
      a[i][j] = ch == '0';
    }
    scanf("%c", &(ch));
  }
  for (int i = 0; i < n; ++i) {
    lines_x[i][0] = a[i][0] ? 1 : 0;
    for (int j = 1; j < m; ++j) {
      if (!a[i][j])
        lines_x[i][j] = 0;
      else
        lines_x[i][j] = lines_x[i][j - 1] + 1;
    }
  }
  for (int j = 0; j < m; ++j) {
    lines_y[0][j] = a[0][j] ? 1 : 0;
    for (int i = 1; i < n; ++i) {
      if (!a[i][j])
        lines_y[i][j] = 0;
      else
        lines_y[i][j] = lines_y[i - 1][j] + 1;
    }
  }
  for (int h = 0; h < n; ++h) {
    for (int w = 0; w < m; ++w) {
      for (int i = n - h - 1; i >= 0; --i) {
        for (int j = m - w - 1; j >= 0; --j) {
          if (h == 0 && w == 0) {
            d[i][j][h][w] = a[i][j];
            cld[i][j][h][w] = a[i][j];
            cldh[i][j][h][w] = a[i][j];
          } else {
            long long c1 = h > 0 ? d[i][j][h - 1][w] : 0;
            long long c2 = w > 0 ? d[i][j][h][w - 1] : 0;
            long long c3 = w > 0 && h > 0 ? d[i][j][h - 1][w - 1] : 0;
            if (!a[i + h][j + w]) {
              d[i][j][h][w] = c1 + c2 - c3;
              cld[i][j][h][w] = 0;
            } else {
              long long cy = max(min(lines_y[i + h][j + w] - 1, h), 0) + 1;
              long long c4 = cy;
              if (w > 0) {
                if (cy < cldh[i][j][h][w - 1]) {
                  c4 += cld[i + h - cy + 1][j][cy - 1][w - 1];
                } else
                  c4 += cld[i][j][h][w - 1];
              }
              cldh[i][j][h][w] = cy;
              cld[i][j][h][w] = c4;
              d[i][j][h][w] = c1 + c2 - c3 + c4;
            }
          }
        }
      }
    }
  }
  int x1, y1, x2, y2;
  for (int t = 0; t < q; ++t) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1 -= 1, y1 -= 1, x2 -= 1, y2 -= 1;
    printf("%I64d\n", d[x1][y1][x2 - x1][y2 - y1]);
  }
  return 0;
}
