#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FR first
#define SC second
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, f, n) for(int i = (int)(f); i < (int)(n); i++)
#define each(a, b) for(auto& a : b)

typedef pair<int, int> P;

const int inf = 1LL << 55;

#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
#define lt(a, b) ((a) - (b) < -EPS)

// ???/????????????
struct Point {
  double x, y;
  Point(double x = 0.0, double y = 0.0):x(x), y(y){}
  
  Point operator + (Point p) { return Point(x + p.x, y + p.y); }
  Point operator - (Point p) { return Point(x - p.x, y - p.y); }
  Point operator * (double a) { return Point(x * a, y * a); }
  Point operator / (double a) { return Point(x / a, y / a); }

  double abs() { return sqrt(norm()); }
  double norm() { return x*x + y*y; }

  bool operator < (const Point& p) const {
    return x != p.x ? x < p.x : y < p.y;
  }
  bool operator == (const Point& p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};
typedef Point Vector;

// ???
struct Circle {
  Point c;
  double r;
  Circle(Point c = Point(), double r = 0.0):c(c), r(r){}
};

// ????§???¢
typedef vector<Point> Polygon;

// ??????/??´???
struct Segment {
  Point p1, p2;
  Segment(Point p1 = Point(), Point p2 = Point()):p1(p1), p2(p2){}
};
typedef Segment Line;

// ????????????????????????
double norm(Vector v)
{
  return v.x*v.x + v.y*v.y;
}
// ?????????????????§??????
double abs(Vector v)
{
  return sqrt(norm(v));
}
// ?????????????????????
double dot(Vector a, Vector b)
{
  return a.x*b.x + a.y*b.y;
}
// ??????????????????????????§??????
double cross(Vector a, Vector b)
{
  return a.x*b.y - a.y*b.x;
}
// ??´?????????
bool isOrthogonal(Vector a, Vector b)
{
  return equals(dot(a, b), 0.0);
}
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2)
{
  return isOrthogonal(a1 - a2, b1 - b2);
}
bool isOrthogonal(Segment s1, Segment s2)
{
  return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}
// ????????????
bool isParallel(Vector a, Vector b)
{
  return equals(cross(a, b), 0.0);
}
bool isParallel(Point a1, Point a2, Point b1, Point b2)
{
  return isParallel(a1 - a2, b1 - b2);
}
bool isParallel(Segment s1, Segment s2)
{
  return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}
// ?°???±
Point project(Segment s, Point p)
{
  Vector base = s.p2 - s.p1;
  double r = dot(p - s.p1, base) / norm(base);
  return s.p1 + base * r;
}
// ????°?
Point reflect(Segment s, Point p)
{
  return p + (project(s, p) - p) * 2.0;
}
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE         = -1;
static const int ONLINE_BACK       = 2;
static const int ONLINE_FRONT      = -2;
static const int ON_SEGMENT        = 0;
// ???????¨???????
int ccw(Point p0, Point p1, Point p2)
{
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if(cross(a, b) < -EPS) return CLOCKWISE;
  if(dot(a, b) < -EPS) return ONLINE_BACK;
  if(a.norm() < b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
}
// ????????????
bool intersect(Point p1, Point p2, Point p3, Point p4)
{
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
	  ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersect(Segment s1, Segment s2)
{
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
// ?????????????????¢
double getDistance(Point a, Point b)
{
  return abs(a - b);
}
// ??´?????¨?????¨????????¢
double getDistanceLP(Line l, Point p)
{
  return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}
// ????????¨?????¨????????¢
double getDistanceSP(Segment s, Point p)
{
  if(dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
  if(dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
  return getDistanceLP(s, p);
}
// ????????????????????¢
double getDistance(Segment s1, Segment s2)
{
  if(intersect(s1, s2)) return 0.0;
  return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
	     min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}
// ???????????????
Point getCrossPoint(Segment s1, Segment s2)
{
  Vector base = s2.p2 - s2.p1;
  double d1 = abs(cross(base, s1.p1 - s2.p1));
  double d2 = abs(cross(base, s1.p2 - s2.p1));
  double t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}
Point getCrossPointLL(Line l1, Line l2)
{
  Vector v1 = l1.p2 - l1.p1, v2 = l2.p2 - l2.p1;
  double d = cross(v2, v1);
  if(abs(d) < EPS) return l2.p1;
  return l1.p1 + v1 * cross(v2, l2.p2 - l1.p1) * (1.0 / d);
}
// ?????´????????????
Line getPerpendicularBisector(Point p1, Point p2)
{
  Point c = (p1 + p2) / 2.0;
  Point q = Point(c.x + (p1.y - p2.y), c.y + (p2.x - p1.x));
  return Line(c, q);
}
// ????´?????§???¢?????¢???
double getArea(Polygon p)
{
  double ret = 0.0;
  for(int i = 0; i < (int)p.size(); i++) {
    ret += cross(p[i], p[(i+1)%p.size()]);
  }
  return abs(ret) / 2.0;
}
  
// ????????????
static const int IN_POLYGON = 2;
static const int ON_POLYGON = 1;
static const int OUT_POLYGON = 0;
int contains(Polygon g, Point p)
{
  int n = g.size();
  bool x = false;
  for(int i = 0; i < n; i++) {
    Point a = g[i] - p, b = g[(i+1) % n] - p;
    if(abs(cross(a, b)) < EPS && dot(a, b) < EPS) return ON_POLYGON;
    if(a.y > b.y) swap(a, b);
    if(a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
  }
  return (x ? IN_POLYGON : OUT_POLYGON);
}
// ???????§???¢?????????
// ???????§???¢???????????´?????§???????????????????????´???????????????
Polygon convexCut(Polygon s, Line l)
{
  Polygon t;
  for(int i = 0; i < (int)s.size(); i++) {
    Point a = s[i], b = s[(i+1)%s.size()];
    if(ccw(l.p1, l.p2, a) != -1) t.push_back(a);
    if(ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) < 0) {
      t.push_back(getCrossPointLL(Line(a, b), l));
    }
  }
  return t;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);
  int N, M;
  while(cin >> N >> M, N) {
    Polygon l(N), C(M);
    rep(i, N) cin >> l[i].x >> l[i].y;
    rep(i, M) cin >> C[i].x >> C[i].y;
    rep(i, M) {
      Polygon p = l;
      rep(j, M) if(i != j) p = convexCut(p, getPerpendicularBisector(C[i], C[j]));
      cout << getArea(p) << endl;
    }
  }
  return 0;
}