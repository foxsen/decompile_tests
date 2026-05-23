#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &n) {
  T w = 1;
  n = 0;
  char ch = getchar();
  while (!isdigit(ch) && ch != EOF) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch) && ch != EOF) {
    n = (n << 3) + (n << 1) + (ch & 15);
    ch = getchar();
  }
  n *= w;
}
template <typename T>
inline void write(T x) {
  T l = 0;
  unsigned long long y = 0;
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (!x) {
    putchar(48);
    return;
  }
  while (x) {
    y = y * 10 + x % 10;
    x /= 10;
    l++;
  }
  while (l) {
    putchar(y % 10 + 48);
    y /= 10;
    l--;
  }
}
template <typename T>
inline void writes(T x) {
  write(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  write(x);
  puts("");
}
template <typename T>
inline void checkmax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T>
inline void checkmin(T &a, T b) {
  a = a < b ? a : b;
}
const int N = 2e5 + 10;
const double eps = 1e-10, pi = acos(-1);
int n, sum, it;
double *pp[N];
long long k;
struct Point {
  double x, y;
} p[N], yd;
inline double dist(Point x, Point y) {
  return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}
inline void doit(double &x) {
  x -= int(x / (2 * pi)) * 2 * pi;
  if (x < -eps) x += 2 * pi;
}
struct yy {
  double l, r;
} q[N];
inline void gaota(double l, double r) {
  doit(l);
  doit(r);
  if (l > r) swap(l, r);
  q[++sum] = yy{l, r};
}
int t[N * 2];
inline bool cmp1(yy x, yy y) { return x.r < y.r; }
inline bool cmp2(double *x, double *y) { return *x < *y; }
inline int lowbit(int x) { return x & (-x); }
inline void insert(int x) {
  for (; x <= it; x += lowbit(x)) t[x]++;
}
inline int qry(int x) {
  int ss = 0;
  for (; x; x -= lowbit(x)) ss += t[x];
  return ss;
}
inline bool check(double x) {
  sum = 0;
  for (int i = 1; i <= n; i++) {
    double dis = dist(p[i], yd);
    if (dis >= x) {
      double jd1 = atan2(p[i].y, p[i].x), jd2 = acos(x / dis);
      gaota(jd1 - jd2, jd1 + jd2);
    }
  }
  long long res = 1LL * sum * (n - sum) + 1LL * (n - sum) * (n - sum - 1) / 2;
  sort(q + 1, q + sum + 1, cmp1);
  for (int i = 1; i <= sum; i++) {
    pp[i] = &q[i].l;
    pp[sum + i] = &q[i].r;
  }
  sort(pp + 1, pp + 2 * sum + 1, cmp2);
  double las = 14913233;
  it = 0;
  for (int i = 1; i <= 2 * sum; i++) {
    if (*pp[i] != las) {
      las = *pp[i];
      it++;
    }
    *pp[i] = it;
  }
  memset(t, 0, sizeof(int) * (it + 1));
  for (int i = sum; i >= 1; i--) {
    res += qry(int(q[i].l)) + (sum - i) - qry(int(q[i].r));
    insert(int(q[i].l));
  }
  return res >= k;
}
int main() {
  read(n);
  read(k);
  yd = Point{0, 0};
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  double l = 0, r = 2e8;
  while ((r - l) >= eps) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.8lf\n", l);
  return 0;
}
