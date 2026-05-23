#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8, PI = acos(-1);

inline bool eq(double a, double b) { return fabs(b - a) < EPS; }

struct Point
{
  double x, y;

  Point() {}

  Point(double x, double y) : x(x), y(y) {}

  Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }

  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }

  Point operator*(const double b) const { return Point(x * b, y * b); }

  Point operator*(const Point &b) const { return Point(x * b.x - y * b.y, x * b.y + y * b.x); }

  Point operator/(const double b) const { return Point(x / b, y / b); }

  bool operator<(const Point &b) const { return x != b.x ? x < b.x : y < b.y; }

  bool operator==(const Point &b) const { return eq(x, b.x) && eq(y, b.y); }

  double norm() { return x * x + y * y; }

  double arg() { return atan2(x, y); }

  double abs() { return sqrt(norm()); }

  Point rotate(double theta) { return Point(cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y); }

  Point rotate90() { return Point(-y, x); }

  friend ostream &operator<<(ostream &os, Point &p) { return os << "(" << p.x << "," << p.y << ")"; }

  friend istream &operator>>(istream &is, Point &a) { return is >> a.x >> a.y; }
};

double cross(const Point &a, const Point &b)
{
  return a.x * b.y - a.y * b.x;
}

double dot(const Point &a, const Point &b)
{
  return a.x * b.x + a.y * b.y;
}

double RadianToDegree(double r)
{
  return (r * 180.0 / acos(-1));
}

double DegreeToRadian(double d)
{
  return (d * acos(-1) / 180.0);
}

double GetAngle(const Point &a, const Point &b, const Point &c)
{
  const Point v = b - a, w = c - b;
  double alpha = atan2(v.y, v.x), beta = atan2(w.y, w.x);
  if(alpha > beta) swap(alpha, beta);
  double theta = (beta - alpha);
  return min(theta, 2 * acos(-1) - theta);
}

struct Line
{
  Point a, b;

  Line() {};

  Line(Point a, Point b) : a(a), b(b) {};

  // Ax + By = C
  Line(double A, double B, double C)
  {
    if(eq(A, 0)) {
      a = Point(0, C / B);
      b = Point(1, C / B);
    } else if(eq(B, 0)) {
      a = Point(C / A, 0);
      b = Point(C / A, 1);
    } else {
      a = Point(0, C / B);
      b = Point(C / A, 0);
    }
  }

  friend ostream &operator<<(ostream &os, Line &p) { return os << "(" << p.a.x << "," << p.a.y << ") to (" << p.b.x << "," << p.b.y << ")"; }

  friend istream &operator>>(istream &is, Line &a) { return is >> a.a.x >> a.a.y >> a.b.x >> a.b.y; }
};

struct Segment
{
  Point a, b;

  Segment() {};

  Segment(Point a, Point b) : a(a), b(b) {};

  friend ostream &operator<<(ostream &os, Segment &p) { return os << "(" << p.a.x << "," << p.a.y << ") to (" << p.b.x << "," << p.b.y << ")"; }

  friend istream &operator>>(istream &is, Segment &a) { return is >> a.a.x >> a.a.y >> a.b.x >> a.b.y; }
};

typedef vector< Point > Polygon;

int ccw(const Point &a, Point b, Point c)
{
  b = b - a, c = c - a;
  if(cross(b, c) > EPS) return +1;
  if(cross(b, c) < -EPS) return -1;
  if(dot(b, c) < 0) return +2;
  if(b.norm() < c.norm()) return -2;
  return 0;
}

bool Intersect(const Segment &s, const Segment &t)
{
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

bool Intersect(const Segment &s, const Point &p)
{
  return ccw(s.a, s.b, p) == 0;
}

void WarshallFloyd(vector< vector< double > > &g)
{
  for(int k = 0; k < g.size(); k++) {
    for(int i = 0; i < g.size(); i++) {
      for(int j = 0; j < g.size(); j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}


int main()
{
  Point pt[2];
  cin >> pt[0] >> pt[1];
  int N;
  cin >> N;
  Polygon ps(N);
  for(auto &p : ps) cin >> p;

  vector< vector< double > > g(N + 2, vector< double >(N + 2, 1e9));
  for(int i = 0; i < g.size(); i++) g[i][i] = 0;

  auto add = [&](int u, int v, double cost)
  {
    g[u][v] = g[v][u] = min(g[v][u], cost);
  };

  for(int i = 0; i < N; i++) {
    add(i, (i + 1) % N, (ps[i] - ps[(i + 1) % N]).abs());
  }
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < N; j++) {
      Segment base(pt[i], ps[j]);
      bool intersect = false;
      for(int k = 0; k < N; k++) {
        if(j == k) continue;
        if(j == (k + 1) % N) continue;
        intersect |= Intersect((Segment) {ps[k], ps[(k + 1) % N]}, base);
      }
      if(!intersect) add(i + N, j, (base.a - base.b).abs());
    }
  }

  WarshallFloyd(g);
  double ret = g[N][N + 1];
  for(int i = 0; i < N; i++) {
    double low = 0, high = 1.0;
    Segment s(ps[i], ps[(i + 1) % N]);

    auto getDist = [&](double v)
    {
      Point peet = s.a + (s.b - s.a) * v;
      Segment latte = Segment(pt[0], peet);
      Segment malta = Segment(pt[1], peet);
      bool intersect = false;
      for(int k = 0; k < N; k++) {
        if(i == k) continue;
        intersect |= Intersect(latte, (Segment) {ps[k], ps[(k + 1) % N]});
        intersect |= Intersect(malta, (Segment) {ps[k], ps[(k + 1) % N]});
      }
      double dist = 1145141919;
      if(!intersect) dist = (latte.a - latte.b).abs() + (malta.a - malta.b).abs();
      return (dist);
    };

    for(int j = 0; j < 300; j++) {
      double left = (low * 2 + high) / 3;
      double right = (low + high * 2) / 3;

      if(getDist(left) < getDist(right)) high = right;
      else low = left;
    }
    ret = min(ret, getDist(low));
  }

  cout << fixed << setprecision(10) << ret << endl;
}