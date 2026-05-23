#include <bits/stdc++.h>
using namespace std;
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
const int N = 120000;
const int M = 120000;
const int oo = 10000 * 10000 * 10;
const double g = 9.8;
double ang[N];
double wx[M], wy[M];
double ax[N], ay[N];
int pd[N];
int wd[M];
int n, m;
double v;
bool pcmp(int i, int j) { return ang[i] < ang[j]; }
bool wcmp(int i, int j) { return wx[i] < wx[j]; }
void solve() {
  int i, j, k;
  for (i = 0; i < n; ++i) pd[i] = i;
  for (j = 0; j < m; ++j) wd[j] = j;
  sort(pd, pd + n, pcmp);
  sort(wd, wd + m, wcmp);
  j = 0;
  for (i = 0; i < n; ++i) {
    int id = pd[i];
    double vx = v * cos(ang[id]);
    double vy = v * sin(ang[id]);
    double t = 2.0 * vy / g;
    double sx = vx * t;
    while (j < m) {
      int jd = wd[j];
      if (wx[jd] <= sx) {
        double tt = wx[jd] / vx;
        double ty = vy * tt - 0.5 * g * tt * tt;
        if (ty <= wy[jd]) {
          ax[id] = wx[jd];
          ay[id] = ty;
          break;
        } else
          ++j;
      } else {
        ax[id] = sx;
        ay[id] = 0;
        break;
      }
    }
    if (j == m) {
      ax[id] = sx;
      ay[id] = 0;
    }
  }
  for (i = 0; i < n; ++i) {
    printf("%.10f %.10f\n", ax[i], ay[i]);
  }
}
int main() {
  int i, j, cas = 0;
  scanf("%d", &n);
  scanf("%lf", &v);
  for (i = 0; i < n; ++i) scanf("%lf", &ang[i]);
  scanf("%d", &m);
  for (i = 0; i < m; ++i) {
    scanf("%lf %lf", &wx[i], &wy[i]);
  }
  solve();
  return 0;
}
