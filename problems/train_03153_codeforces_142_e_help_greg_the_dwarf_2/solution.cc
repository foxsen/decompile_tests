#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T, class U>
inline void print(T first, U second) {
  printsp(first);
  println(second);
}
template <class T, class U, class V>
inline void print(T first, U second, V z) {
  printsp(first);
  printsp(second);
  println(z);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
struct point {
  long double first, second, z;
  point(long double first = 0, long double second = 0, long double z = 0)
      : first(first), second(second), z(z) {}
  point operator-(point a) {
    return point(first - a.first, second - a.second, z - a.z);
  }
  point operator+(point a) {
    return point(first + a.first, second + a.second, z + a.z);
  }
  point operator*(long double a) { return point(first * a, second * a, z * a); }
  point operator/(long double a) { return point(first / a, second / a, z / a); }
  point operator^(point a) {
    return point(second * a.z - z * a.second, -(first * a.z - z * a.first),
                 first * a.second - second * a.first);
  }
  long double operator*(point a) {
    return first * a.first + second * a.second + z * a.z;
  }
  point norm() {
    long double s = nor();
    if (s < 1e-12) return *this;
    return point(first / s, second / s, z / s);
  }
  long double nor() { return sqrtl(*this * *this); }
  bool operator<(const point &a) const {
    if (fabsl(first - a.first) > 1e-12) return first < a.first;
    if (fabsl(second - a.second) > 1e-12) return second < a.second;
    return z < a.z - 1e-12;
  }
  bool operator>(const point &a) const {
    if (fabsl(first - a.first) > 1e-12) return first > a.first;
    if (fabsl(second - a.second) > 1e-12) return second > a.second;
    return z > a.z - 1e-12;
  }
  bool operator==(const point &a) const {
    if (fabsl(first - a.first) > 1e-12) return 0;
    if (fabsl(second - a.second) > 1e-12) return 0;
    return fabs(z - a.z) < 1e-12;
  }
  void input() { cin >> first >> second >> z; }
  void print() {
    printf("%lf %lf %lf\n", (double)first, (double)second, (double)z);
  }
};
void print_ans(long double first) {
  cout << fixed << setprecision(15) << first << endl;
  exit(0);
}
long double pi = acosl(-1.0);
long double r, h, L;
point a, b, H;
long double calc3(point a, long double al) {
  long double be = atan2l(a.second, a.first);
  long double delta = fabsl(be - al);
  if (delta > 2 * pi) delta -= 2 * pi;
  smin(delta, 2 * pi - delta);
  return sqrtl(L * L + (H - a) * (H - a) -
               (H - a).nor() * 2 * L * cosl(delta * r / L));
}
long double calc2(long double al, long double be) {
  return calc3(a, al) + calc3(b, be) +
         (point(cosl(al), sinl(al)) - point(cosl(be), sinl(be))).nor() * r;
}
long double calc1(long double al) {
  long double ans = 1e100;
  for (int j = 0; j < 6; j++) {
    long double st = pi / 3 * j, ed = st + pi / 2;
    for (int i = 0; i < 50; i++) {
      long double x1 = (st * 2 + ed) / 3, x2 = (st + ed * 2) / 3;
      long double y1 = calc2(al, x1), y2 = calc2(al, x2);
      if (y1 < y2)
        ed = x2;
      else
        st = x1;
    }
    smin(ans, calc2(al, st));
  }
  return ans;
}
long double calc(long double al) {
  return calc3(b, al) + (a - point(cosl(al) * r, sinl(al) * r)).nor();
}
int main() {
  cin >> r >> h;
  a.input();
  b.input();
  H = point(0, 0, h);
  L = sqrtl(r * r + h * h);
  if (a.z < 1e-12 && b.z < 1e-12) print_ans((a - b).nor());
  if (a.z > 1e-12 && b.z > 1e-12) {
    long double la = (H - a).nor(), lb = (H - b).nor();
    long double delta =
        fabsl(atan2l(a.second, a.first) - atan2l(b.second, b.first));
    smin(delta, 2 * pi - delta);
    long double ans = sqrtl((H - a) * (H - a) + (H - b) * (H - b) -
                            2 * la * lb * cosl(delta * r / L));
    for (int i = 0; i < 6; i++) {
      long double st = pi / 3 * i, ed = st + pi / 2;
      for (int j = 0; j < 50; j++) {
        long double x1 = (st * 2 + ed) / 3, x2 = (st + ed * 2) / 3;
        long double y1 = calc1(x1), y2 = calc1(x2);
        smin(ans, y1);
        smin(ans, y2);
        if (y1 < y2)
          ed = x2;
        else
          st = x1;
      }
      smin(ans, calc1(st));
    }
    print_ans(ans);
  }
  if (b.z < 1e-12) swap(a, b);
  long double ans = 1e100;
  for (int i = 0; i < 6; i++) {
    long double st = pi / 3 * i, ed = st + pi / 2;
    for (int j = 0; j < 100; j++) {
      long double x1 = (st * 2 + ed) / 3, x2 = (st + ed * 2) / 3;
      long double y1 = calc(x1), y2 = calc(x2);
      smin(ans, y1);
      smin(ans, y2);
      if (y1 < y2)
        ed = x2;
      else
        st = x1;
    }
    smin(ans, calc(st));
  }
  print_ans(ans);
  return 0;
}
