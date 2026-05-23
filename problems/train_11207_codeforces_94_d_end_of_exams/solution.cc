#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
int main() {
  int n;
  double w, m;
  scanf("%d%lf%lf", &n, &w, &m);
  double ans = n * w / m;
  int flag = 0, id = 0;
  double res = 0;
  for (int i = 0; i < m; i++) {
    double ha = ans;
    if (res > ha + eps) {
      flag = 1;
      break;
    }
    ha -= res;
    while (ha > eps) {
      if (ha >= w)
        ha -= w, res = 0;
      else
        res = w - ha, ha = 0;
    }
  }
  if (flag)
    printf("NO\n");
  else {
    printf("YES\n");
    res = 0;
    int id = 1;
    for (int i = 0; i < m; i++) {
      double ha = ans;
      int ff = 0;
      if (res > eps) {
        printf("%d %.6lf", id, res);
        ha -= res;
        id++, ff = 1;
        res = 0;
      }
      while (ha > eps) {
        if (ha >= w) {
          ha -= w;
          if (ff == 1)
            printf(" %d %.6lf", id, w);
          else
            printf("%d %.6lf", id, w), ff = 1;
          id++;
          res = 0;
        } else {
          res = w - ha;
          if (ff == 1)
            printf(" %d %.6lf", id, ha);
          else
            printf("%d %.6lf", id, ha), ff = 1;
          ha = 0;
        }
      }
      printf("\n");
    }
  }
  return 0;
}
