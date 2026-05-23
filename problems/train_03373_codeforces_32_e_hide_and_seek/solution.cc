#include <bits/stdc++.h>
using namespace std;
class vec {
 public:
  double x, y;
  vec() {}
  vec(double tx, double ty) { x = tx, y = ty; }
  vec operator+(const vec &t) { return vec(x + t.x, y + t.y); }
  vec operator-(const vec &t) { return vec(x - t.x, y - t.y); }
  double operator*(const vec &t) { return x * t.y - y * t.x; }
  double operator^(const vec &t) { return x * t.x + y * t.y; }
  double length() { return sqrt(x * x + y * y); }
  bool operator==(const vec &t) {
    return fabs(x - t.x) <= 1e-6 && fabs(y - t.y) <= 1e-6;
  }
  bool operator!=(const vec &t) { return !(*this == t); }
  vec operator/(const double &t) { return vec(x / t, y / t); }
} alice, bob;
class seg {
 public:
  vec st, ed;
  seg() {}
  seg(vec a, vec b) { st = a, ed = b; }
} wall, mirror;
bool issq(seg a, seg b) {
  vec &p1 = a.st, &p2 = a.ed, &q1 = b.st, &q2 = b.ed;
  bool ret = min(p1.x, p2.x) <= max(q1.x, q2.x) &&
             min(q1.x, q2.x) <= max(p1.x, p2.x) &&
             min(p1.y, p2.y) <= max(q1.y, q2.y) &&
             min(q1.y, q2.y) <= max(p1.y, p2.y);
  return ret;
}
bool crosstest(seg a, seg b) {
  return ((b.st - a.st) * (a.ed - a.st)) * ((b.ed - a.st) * (a.ed - a.st)) <=
         1e-6;
}
bool intersect(seg a, seg b) {
  return issq(a, b) && crosstest(a, b) && crosstest(b, a);
}
vec reflect(vec a, seg b) {
  vec A = a - b.st, B = b.ed - b.st;
  double cs = (A ^ B) / (A.length() * B.length());
  double sn = sqrt(1 - cs * cs);
  vec out =
      vec(B.x * cs - B.y * sn, B.x * sn + B.y * cs) / (B.length() / A.length());
  if (out != A) return b.st + out;
  out = vec(B.x * cs + B.y * sn, -B.x * sn + B.y * cs) /
        (B.length() / A.length());
  return b.st + out;
}
int main() {
  scanf("%lf%lf%lf%lf", &alice.x, &alice.y, &bob.x, &bob.y);
  scanf("%lf%lf%lf%lf", &wall.st.x, &wall.st.y, &wall.ed.x, &wall.ed.y);
  scanf("%lf%lf%lf%lf", &mirror.st.x, &mirror.st.y, &mirror.ed.x, &mirror.ed.y);
  if (!intersect(seg(alice, bob), wall) &&
      !intersect(seg(alice, bob), mirror)) {
    puts("YES");
    return 0;
  }
  vec alice2 = reflect(alice, mirror), bob2 = reflect(bob, mirror);
  if (intersect(seg(alice2, bob), mirror)) {
    if (!intersect(seg(alice2, bob), wall) &&
        !intersect(seg(alice, bob2), wall)) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
