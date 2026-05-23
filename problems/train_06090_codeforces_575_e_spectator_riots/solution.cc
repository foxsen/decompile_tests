#include <bits/stdc++.h>
using namespace std;
double const eps = 1e-7;
struct Points {
  double x, y;
  Points(double _x = 0, double _y = 0) { x = _x, y = _y; }
  Points operator-(const Points &A) { return Points(x - A.x, y - A.y); }
  Points operator+(const Points &A) { return Points(x + A.x, y + A.y); }
  Points operator*(const double &k) { return Points(x * k, y * k); }
  bool operator<(const Points &A) const {
    return fabs(x - A.x) < eps ? y < A.y : x < A.x;
  }
} p1, p2, p3;
inline double sqr(double x) { return x * x; }
inline double Cross(Points A, Points B) { return A.x * B.y - A.y * B.x; }
inline double Dis(Points A, Points B) {
  return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}
inline Points Middle(Points A, Points B) {
  return Points((A.x + B.x) / 2.0, (A.y + B.y) / 2.0);
}
inline Points Rev(Points A) { return Points(-A.y, A.x); }
struct Lines {
  Points p, v;
  Lines(Points _p = 0, Points _v = 0) { p = _p, v = _v; }
};
inline Points Inter(Lines A, Lines B) {
  return A.v * (Cross(B.v, A.p - B.p) / Cross(A.v, B.v)) + A.p;
}
struct Circle {
  Points o;
  double r;
  Circle(Points _o = 0, double _r = 0) { o = _o, r = _r; }
  bool In(const Points &A) { return Dis(o, A) <= r; }
} O, ansO;
inline bool Check(Points A, Points B, Points C) {
  return Cross(A - B, A - C) != 0;
}
inline Circle MakeCircle(Points A, Points B, Points C) {
  Lines l1 = Lines(Middle(A, B), Rev(B - A));
  Lines l2 = Lines(Middle(A, C), Rev(C - A));
  Points o = Inter(l1, l2);
  double r = Dis(o, A);
  return Circle(o, r);
}
int const MAXN = 1e6 + 5;
vector<Points> G, Tb;
int stk1[MAXN], stk2[MAXN], top1, top2;
signed main() {
  int n, Mx = 1e5;
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) {
    int x, y, d;
    scanf("%d %d %d", &x, &y, &d);
    int minx = (x - d >= 0), maxx = (x + d <= Mx);
    int miny = (y - d >= 0), maxy = (y + d <= Mx);
    if (minx)
      G.push_back(Points(x - d, y));
    else {
      G.push_back(Points(0, max(0, y - d + x)));
      G.push_back(Points(0, min(Mx, y + d - x)));
    }
    if (miny)
      G.push_back(Points(x, y - d));
    else {
      G.push_back(Points(max(0, x - d + y), 0));
      G.push_back(Points(min(Mx, x + d - y), 0));
    }
    if (maxx)
      G.push_back(Points(x + d, y));
    else {
      G.push_back(Points(Mx, max(0, y - d + (Mx - x))));
      G.push_back(Points(Mx, min(Mx, y + d - (Mx - x))));
    }
    if (maxy)
      G.push_back(Points(x, y + d));
    else {
      G.push_back(Points(max(0, x - d + (Mx - y)), Mx));
      G.push_back(Points(min(Mx, x + d - (Mx - y)), Mx));
    }
  }
  int si = G.size();
  sort(G.begin(), G.end());
  for (register int i = 0; i < si; ++i) {
    while (top1 > 1 && Cross(G[stk1[top1]] - G[stk1[top1 - 1]],
                             G[i] - G[stk1[top1 - 1]]) <= 0)
      --top1;
    stk1[++top1] = i;
  }
  for (register int i = 0; i < si; ++i) {
    while (top2 > 1 && Cross(G[stk2[top2]] - G[stk2[top2 - 1]],
                             G[i] - G[stk2[top2 - 1]]) >= 0)
      --top2;
    stk2[++top2] = i;
  }
  for (register int i = 1; i <= top1; ++i) Tb.push_back(G[stk1[i]]);
  for (register int i = top2 - 1; i > 1; --i) Tb.push_back(G[stk2[i]]);
  Tb.push_back(Tb[0]);
  Tb.push_back(Tb[1]);
  si = Tb.size();
  for (register int i = 0; i < si - 2; ++i) {
    O = MakeCircle(Tb[i], Tb[i + 1], Tb[i + 2]);
    if (O.r > ansO.r) ansO = O, p1 = Tb[i], p2 = Tb[i + 1], p3 = Tb[i + 2];
  }
  printf("%.0lf %.0lf\n", p1.x + 0.1, p1.y + 0.1);
  printf("%.0lf %.0lf\n", p2.x + 0.1, p2.y + 0.1);
  printf("%.0lf %.0lf\n", p3.x + 0.1, p3.y + 0.1);
  return 0;
}
