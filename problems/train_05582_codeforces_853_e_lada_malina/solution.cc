#include <bits/stdc++.h>
template <typename T>
inline void repl(T& a, T b) {
  if (a > b) a = b;
}
template <typename T>
inline void repr(T& a, T b) {
  if (a < b) a = b;
}
char buf[10000000], *be = buf, obuf[10000000], *oe = obuf;
inline void read(int& x) {
  while ((*be < 48 || *be > 57) && *be != '-') be++;
  x = 0;
  bool y = 0;
  if (*be == '-') y = 1, be++;
  while (*be >= 48 && *be <= 57) x = x * 10 + *be++ - 48;
  if (y) x = -x;
}
inline void write(long long x) {
  static char o[20];
  int c = 0;
  if (x < 0) x = -x, o[c++] = '-';
  if (!x)
    o[c++] = '0';
  else {
    while (x) o[c++] = '0' + x % 10, x /= 10;
  }
  while (c--) *oe++ = o[c];
}
const int N = 100007;
const long double eps = 1e-10;
struct rec {
  int x1, y1, x2, y2, xv, yv;
  bool k1, k2;
} r[50];
struct data {
  int x, y, v;
} a[N], b[N];
int K, n, m;
inline bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
  return atan2(a.first, a.second) < atan2(b.first, b.second);
}
inline void pre() {
  static int x[10], y[10];
  static std::pair<int, int> t[10];
  int c = 0;
  for (int i = 0; i < K; i++) {
    read(x[c]), read(y[c]);
    if (x[c] < 0)
      x[c] = -x[c], y[c] = -y[c];
    else if (x[c] == 0 && y[c] < 0)
      y[c] = -y[c];
    bool flag = 1;
    for (int j = 0; j < c; j++) {
      if (x[c] * y[j] - x[j] * y[c] == 0) {
        x[j] += x[c];
        y[j] += y[c];
        flag = 0;
        break;
      }
    }
    if (flag) c++;
  }
  for (int i = 0; i < c; i++) t[i] = std::make_pair(x[i], y[i]);
  std::sort(t, t + c, cmp);
  for (int i = 0, iend = (c); i < iend; i++)
    x[i] = t[i].first, y[i] = t[i].second;
  int vx = 0, vy = 0;
  for (int i = 0, iend = (c); i < iend; i++) vx -= x[i], vy -= y[i];
  for (int i = 0, iend = (c); i < iend; i++) x[i] *= 2, y[i] *= 2;
  K = 0;
  for (int i = c - 1; i; i--) {
    int tx = vx, ty = vy;
    for (int j = 0; j < i; j++) {
      r[K++] = (rec){x[i], y[i], x[j], y[j], tx, ty, j + 1 == i, i == 1};
      tx += x[j], ty += y[j];
    }
    vx += x[i], vy += y[i];
  }
}
struct point {
  long double x, y;
} c[N], d[N];
struct query_ {
  long double p;
  int x, o, i, v;
  inline bool operator<(const query_& t) const { return p < t.p; }
} u[N * 3];
long double v[N];
int vm;
long long f[N], ans[N];
inline void modify(int x, int v) {
  for (; x <= vm; x += x & -x) f[x] += v;
}
inline long long query(int x) {
  long long r = 0;
  for (; x; x ^= x & -x) r += f[x];
  return r;
}
int main() {
  fread(buf, 1, sizeof buf, stdin);
  read(K), read(n), read(m);
  pre();
  for (int i = 0, iend = (n); i < iend; i++)
    read(a[i].x), read(a[i].y), read(a[i].v);
  for (int i = 0, iend = (m); i < iend; i++)
    read(b[i].x), read(b[i].y), read(b[i].v);
  for (int k = 0, kend = (K); k < kend; k++) {
    long double t = (long double)r[k].x2 * r[k].y1 -
                    (long double)r[k].x1 * r[k].y2,
                xa = -r[k].y2 / t, xb = r[k].x2 / t, ya = r[k].y1 / t,
                yb = -r[k].x1 / t;
    for (int i = 0, iend = (n); i < iend; i++)
      c[i] = (point){a[i].x * xa + a[i].y * xb, a[i].x * ya + a[i].y * yb};
    for (int i = 0, iend = (m); i < iend; i++) {
      int x = b[i].x + r[k].xv * b[i].v, y = b[i].y + r[k].yv * b[i].v;
      d[i] = (point){x * xa + y * xb, x * ya + y * yb};
    }
    for (int i = 0, iend = (n); i < iend; i++) v[i] = c[i].y;
    std::sort(v, v + n);
    vm = std::unique(v, v + n) - v;
    int um = 0;
    for (int i = 0, iend = (n); i < iend; i++) {
      u[um++] = (query_){c[i].x, int(std::upper_bound(v, v + vm, c[i].y) - v),
                         -1, 0, a[i].v};
    }
    for (int i = 0, iend = (m); i < iend; i++) {
      long double xl = d[i].x - eps,
                  xr = d[i].x + b[i].v + (r[k].k2 ? eps : -eps),
                  yl = d[i].y - eps,
                  yr = d[i].y + b[i].v + (r[k].k1 ? eps : -eps);
      int ul = std::upper_bound(v, v + vm, yl) - v,
          ur = std::upper_bound(v, v + vm, yr) - v;
      if (ul < ur) {
        u[um++] = (query_){xl, ul, ur, i, -1};
        u[um++] = (query_){xr, ul, ur, i, 1};
      }
    }
    std::sort(u, u + um);
    for (int i = 0, iend = (um); i < iend; i++) {
      if (u[i].o == -1) {
        modify(u[i].x, u[i].v);
      } else {
        ans[u[i].i] += u[i].v * (query(u[i].o) - query(u[i].x));
      }
    }
    for (int i = 1; i <= vm; i++) f[i] = 0;
  }
  for (int i = 0, iend = (m); i < iend; i++) write(ans[i]), *oe++ = '\n';
  fwrite(obuf, 1, oe - obuf, stdout);
}
