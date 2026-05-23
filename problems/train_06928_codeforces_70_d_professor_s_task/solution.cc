#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int INF32 = 0x3f3f3f3f;
const long long INF64 = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1.0e-8;
struct Point {
  double x, y, t, d;
  Point(double _x = 0, double _y = 0, double _t = 0, double _d = 0) {
    x = _x;
    y = _y;
    t = _t;
    d = _d;
  }
  friend Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
  }
  friend Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
  }
  friend double operator^(Point a, Point b) { return a.x * b.y - a.y * b.x; }
  friend int operator==(const Point &a, const Point &b) {
    if (fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS) return 1;
    return 0;
  }
  friend double operator*(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
  }
};
struct V {
  Point start, end;
  double ang;
  V(Point _start = Point(0, 0), Point _end = Point(0, 0), double _ang = 0.0) {
    start = _start;
    end = _end;
    ang = _ang;
  }
  friend V operator+(const V &a, const V &b) {
    return V(a.start + b.start, a.end + b.end);
  }
  friend V operator-(const V &a, const V &b) {
    return V(a.start - b.start, a.end - b.end);
  }
};
Point Basic, points[MAXN];
set<Point> S;
int N;
int Sgn(double key) { return fabs(key) < EPS ? 0 : (key < 0 ? -1 : 1); }
int Cmp(double key1, double key2) { return Sgn(key1 - key2); }
double GetLen(Point key) { return sqrt(key * key); }
bool operator<(Point key1, Point key2) {
  key1 = key1 - Basic;
  key2 = key2 - Basic;
  double Ang1 = atan2(key1.y, key1.x), Ang2 = atan2(key2.y, key2.x);
  double Len1 = GetLen(key1), Len2 = GetLen(key2);
  if (Cmp(Ang1, Ang2) != 0) return Cmp(Ang1, Ang2) < 0;
  return Cmp(Len1, Len2) < 0;
}
set<Point>::iterator Prev(set<Point>::iterator key) {
  if (key == S.begin()) key = S.end();
  return --key;
}
set<Point>::iterator Next(set<Point>::iterator key) {
  ++key;
  return key == S.end() ? S.begin() : key;
}
int Query(Point key) {
  set<Point>::iterator it = S.lower_bound(key);
  if (it == S.end()) it = S.begin();
  return Sgn((key - *(Prev(it))) ^ (*(it) - *(Prev(it)))) <= 0;
}
void Insert(Point key) {
  if (Query(key)) return;
  S.insert(key);
  set<Point>::iterator Cur = Next(S.find(key));
  while (S.size() > 3 &&
         Sgn((key - *(Next(Cur))) ^ (*(Cur) - *(Next(Cur)))) <= 0) {
    S.erase(Cur);
    Cur = Next(S.find(key));
  }
  Cur = Prev(S.find(key));
  while (S.size() > 3 && Sgn((key - *(Cur)) ^ (*(Cur) - *(Prev(Cur)))) >= 0) {
    S.erase(Cur);
    Cur = Prev(S.find(key));
  }
}
int main() {
  scanf("%d", &N);
  Basic = Point(0, 0);
  for (int i = 1, T; i <= 3; ++i) {
    scanf("%d%lf%lf", &T, &points[i].x, &points[i].y);
    Basic = Basic + points[i];
  }
  Basic.x /= 3.0;
  Basic.y /= 3.0;
  for (int i = 1; i <= 3; ++i) {
    S.insert(points[i]);
  }
  for (int i = 4, T; i <= N; ++i) {
    scanf("%d%lf%lf", &T, &points[i].x, &points[i].y);
    if (T == 1)
      Insert(points[i]);
    else {
      if (Query(points[i]))
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
}
