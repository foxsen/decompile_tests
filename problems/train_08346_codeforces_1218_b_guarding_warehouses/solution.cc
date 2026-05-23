#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const int maxn = 1e5 + 10;
const double PI = acos(-1.), eps = 1e-12;
struct vec {
  double x, y;
  vec(double x = 0, double y = 0) : x(x), y(y) {}
  vec operator+(const vec &b) const { return vec(x + b.x, y + b.y); }
  vec operator-(const vec &b) const { return vec(x - b.x, y - b.y); }
  bool operator==(const vec &b) const { return x == b.x and y == b.y; }
  double operator*(const vec &b) const { return x * b.y - y * b.x; }
  inline double length() { return sqrt(x * x + y * y); }
  inline double dir() { return atan2(y, x); }
} e;
struct seg {
  vec a, b;
  seg() {}
  seg(vec a, vec b) : a(a), b(b) {}
  inline vec cross(vec e = star::e) const {
    if (e.x == 0) return vec(0, b.y - (b - a).y / (b - a).x * b.x);
    if (a == b) return a;
    double x = ((b.y - a.y) * b.x - (b.x - a.x) * b.y) /
               (b.y - a.y - (b.x - a.x) * e.y / e.x);
    return vec(x, x * e.y / e.x);
  }
} a[maxn];
struct cmp {
  bool operator()(const seg &a, const seg &b) const {
    return a.cross().length() < b.cross().length() or
           a.cross(e + eps).length() < b.cross(e + eps).length();
  }
};
multiset<seg, cmp> st;
pair<vec, int> c[maxn];
int n, tot;
multiset<seg, cmp>::iterator it[maxn];
double ans;
inline double S(vec A, vec B, vec C) {
  if (A == B or B == C or A == C) return 0;
  double a = (A - B).length(), b = (B - C).length(), c = (A - C).length(),
         p = (a + b + c) / 2;
  double ans = sqrt(p * (p - a) * (p - b) * (p - c));
  return isnan(ans) ? 0 : ans;
}
inline void work() {
  int m = read();
  static vec b[maxn];
  e = vec(-1, 0);
  for (int cnt, i = 1; i <= m; i++) {
    for (int j = cnt = read(); j; j--) b[j].x = read(), b[j].y = read();
    b[++cnt] = b[1];
    for (int i = 1; i < cnt; i++)
      if (b[i].y * b[i + 1].x != b[i + 1].y * b[i].x) {
        vec x = b[i], z = b[i + 1];
        a[++n] = seg(x, z);
        vec y = a[n].cross();
        if (y.x < 0 and x.y * z.y < 0) {
          if (x.dir() < z.dir()) swap(x, z);
          a[n] = seg(x, y), c[++tot] = make_pair(x, n << 1),
          c[++tot] = make_pair(y, n << 1 | 1);
          a[++n] = seg(y, z), c[++tot] = make_pair(y, n << 1),
          c[++tot] = make_pair(z, n << 1 | 1);
        } else {
          if (x.y == 0) x.y += z.y > 0 ? eps : -eps;
          if (z.y == 0) z.y += x.y > 0 ? eps : -eps;
          if (x.dir() > z.dir()) swap(x, z);
          a[n] = seg(x, z), c[++tot] = make_pair(x, n << 1),
          c[++tot] = make_pair(z, n << 1 | 1);
        }
      }
  }
  sort(c + 1, c + 1 + tot, [](pair<vec, int> a, pair<vec, int> b) {
    return a.first.y == 0 ? a.second & 1 ^ 1
           : b.first.y == 0
               ? b.second & 1
               : atan2(a.first.y, a.first.x) < atan2(b.first.y, b.first.x);
  });
  vec A, B, C, D;
  for (int i = 1; i < tot; i++) {
    if (st.size() >= 2) {
      A = (*st.begin()).cross(), B = (*++st.begin()).cross();
      e = c[i].first;
      C = (*st.begin()).cross(), D = (*++st.begin()).cross();
      ans += S(A, B, C) + S(B, C, D);
      if (isnan(ans)) {
        printf("%f %f  ", e.x, e.y);
        printf("%f %f\n", S(A, B, C), S(B, C, D));
        printf("%f %f  ", A.x, A.y);
        printf("%f %f  ", B.x, B.y);
        printf("%f %f  ", C.x, C.y);
        printf("%f %f\n", D.x, D.y);
        for (auto x : st) printf("%f %f %f %f|", x.a.x, x.a.y, x.b.x, x.b.y);
        return;
      }
    } else
      e = c[i].first;
    int x = c[i].second >> 1;
    if (c[i].second & 1 ^ 1)
      it[x] = st.insert(a[x]);
    else
      st.erase(it[x]);
  }
  printf("%.10f", ans);
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
