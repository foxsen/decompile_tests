#include <bits/stdc++.h>
using namespace std;
void read_file(bool outToFile = true) {}
const int DEBUGING = 1;
const long double OO = 100000;
const int itrMax = 1000;
struct point {
  long double x, y;
  point() {}
  point(long double nx, long double ny) { x = nx, y = ny; }
  bool operator==(point q) {
    return fabs(x - q.x) <= (1e-7) && fabs(y - q.y) <= (1e-7);
  }
};
long double tmax, vmax;
point p1, p2, p3;
point w1, w2;
long double ans;
bool read(point &p) {
  cin >> p.x >> p.y;
  if (cin.fail()) return 0;
  return 1;
}
long double dot(point p, point q) { return p.x * q.x + p.y * q.y; }
long double abs(point p) { return sqrt(dot(p, p)); }
long double alpha(point w, point p, point q) {
  point r;
  r.x = q.x - p.x;
  r.y = q.y - p.y;
  if (w == point(0, 0)) return vmax / abs(r);
  long double cos_theta = dot(w, r) / abs(w) / abs(r);
  long double sin_theta_2 = 1 - cos_theta * cos_theta;
  long double ret = abs(w) * cos_theta;
  long double tmp = vmax * vmax - sin_theta_2 * dot(w, w);
  if (tmp <= 0 + (1e-7))
    ret += 0;
  else
    ret += sqrt(tmp);
  ret /= abs(r);
  return ret;
}
long double tryy(long double ux, long double uy) {
  point v;
  v.x = ux + w1.x;
  v.y = uy + w1.y;
  p2.x = p1.x + v.x * tmax;
  p2.y = p1.y + v.y * tmax;
  return 1 / alpha(w2, p2, p3) + tmax;
}
long double f(long double ux) {
  long double tmp = vmax * vmax - ux * ux;
  if (tmp <= 0 + (1e-7)) return tryy(ux, 0);
  long double uy = sqrt(tmp);
  long double c1 = tryy(ux, uy);
  long double c2 = tryy(ux, -uy);
  return min(c1, c2);
}
void TS() {
  long double lo = -vmax, hi = +vmax;
  int itr = 0;
  while (itr < itrMax) {
    itr++;
    long double md1 = (hi - lo) / 3 + lo;
    long double md2 = (hi - lo) / 3 * 2 + lo;
    if (f(md1) < f(md2))
      hi = md2;
    else
      lo = md1;
  }
  ans = f(lo);
}
bool special() {
  if (p1 == p3) return ans = 0, 1;
  long double t = 1 / alpha(w1, p1, p3);
  if (t - (1e-7) > tmax) return 0;
  ans = t;
  return 1;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_file();
  while (read(p1)) {
    read(p3);
    cin >> vmax >> tmax;
    read(w1);
    read(w2);
    if (!special()) {
      TS();
    }
    cout << setprecision(25) << fixed << ans << '\n';
  }
}
