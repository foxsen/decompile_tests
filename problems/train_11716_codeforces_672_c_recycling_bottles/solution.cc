#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, l, cn, t, z, mx, mn, s;
char c[1000009], d[1000009], ch;
double ax, ay, bx, by, tx, ty, x[100005], y[100005], p[1000009], ans;
struct point {
  int id;
  double dis;
} a[1000009], b[1000009];
bool cmp(point aa, point bb) { return aa.dis < bb.dis; }
int main() {
  while (scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &tx, &ty) !=
         EOF) {
    ans = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%lf %lf", &x[i], &y[i]);
      a[i].dis = sqrt((x[i] - ax) * (x[i] - ax) + (y[i] - ay) * (y[i] - ay));
      b[i].dis = sqrt((x[i] - bx) * (x[i] - bx) + (y[i] - by) * (y[i] - by));
      p[i] = sqrt((x[i] - tx) * (x[i] - tx) + (y[i] - ty) * (y[i] - ty));
      a[i].dis -= p[i];
      b[i].dis -= p[i];
      a[i].id = i;
      b[i].id = i;
      ans += p[i];
    }
    ans *= 2;
    sort(a, a + n, cmp);
    sort(b, b + n, cmp);
    if (a[0].id == b[0].id) {
      ans += min(a[0].dis + b[1].dis,
                 min(a[1].dis + b[0].dis, min(a[0].dis, b[0].dis)));
    } else {
      ans += min(a[0].dis + b[0].dis, min(a[0].dis, b[0].dis));
    }
    printf("%.10lf\n", ans);
  }
  return 0;
}
