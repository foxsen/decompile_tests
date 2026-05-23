#include<bits/stdc++.h>

using namespace std;

const double EPS = 1e-8, PI = acos(-1), INF = 1e9;

inline bool eq(double a, double b)
{
  return abs(b - a) < EPS;
}

struct Point
{
  double x, y;

  Point() {};

  Point(double x, double y) : x(x), y(y) {};

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


int ccw(const Point &a, Point b, Point c)
{
  b = b - a, c = c - a;
  if(cross(b, c) > EPS) return +1;
  if(cross(b, c) < -EPS) return -1;
  if(dot(b, c) < 0) return +2;
  if(b.norm() < c.norm()) return -2;
  return 0;
}

struct Segment
{
  Point a, b;

  Segment() {};

  Segment(Point a, Point b) : a(a), b(b) {};

  friend ostream &operator<<(ostream &os, Segment &p) { return os << "(" << p.a.x << "," << p.a.y << ") to (" << p.b.x << "," << p.b.y << ")"; }

  friend istream &operator>>(istream &is, Segment &a) { return is >> a.a.x >> a.a.y >> a.b.x >> a.b.y; }
};

bool Intersect(const Segment &s, const Point &p)
{
  return ccw(s.a, s.b, p) == 0;
}

bool Intersect(const Segment &s, const Segment &t)
{
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
         ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

Point Crosspoint(const Segment &l, const Segment &m)
{
  double A = cross(l.b - l.a, m.b - m.a);
  double B = cross(l.b - l.a, l.b - m.a);
  if(abs(A) < EPS && abs(B) < EPS) return m.a; // same line
  return m.a + (m.b - m.a) * B / A;
}

vector< vector< int > > SegmentArrangement(vector< Segment > &segs, vector< Point > &ps)
{
  vector< vector< int > > g;
  ps.clear();
  const int N = (int) segs.size();

  for(int i = 0; i < N; i++) {
    ps.emplace_back(segs[i].a);
    ps.emplace_back(segs[i].b);
    for(int j = i + 1; j < N; j++) {
      const Point p1 = segs[i].b - segs[i].a;
      const Point p2 = segs[j].b - segs[j].a;
      if(cross(p1, p2) == 0) continue;
      if(Intersect(segs[i], segs[j])) {
        ps.emplace_back(Crosspoint(segs[i], segs[j]));
      }
    }
  }
  sort(begin(ps), end(ps));
  ps.erase(unique(begin(ps), end(ps)), end(ps));

  const int M = (int) ps.size();
  g.resize(M);
  for(int i = 0; i < N; i++) {
    vector< int > vec;
    for(int j = 0; j < M; j++) {
      if(Intersect(segs[i], ps[j])) {
        vec.emplace_back(j);
      }
    }
    for(int j = 1; j < vec.size(); j++) {
      g[vec[j - 1]].push_back(vec[j]);
      g[vec[j]].push_back(vec[j - 1]);
    }
  }
  return (g);
}

double Dijkstra(vector< vector< int > > &g, Point &s, Point &t, vector< Point > &ps)
{
  int idx;
  for(int i = 0; i < ps.size(); i++) {
    if(ps[i] == s) idx = i;
  }
  vector< vector< double > > min_cost(g.size(), vector< double >(g.size(), INF));
  typedef tuple< double, int, int > State;
  priority_queue< State, vector< State >, greater< State > > que;
  for(auto &to : g[idx]) {
    que.emplace(0, idx, to);
    min_cost[idx][to] = 0.0;
  }
  while(!que.empty()) {
    double cost;
    int pre, cur;
    tie(cost, pre, cur) = que.top();
    que.pop();
    if(cost > min_cost[pre][cur]) continue;
    if(ps[cur] == t) return (cost);
    for(auto &to : g[cur]) {
      if(pre == to) continue;
      double ncost = cost + RadianToDegree(GetAngle(ps[pre], ps[cur], ps[to]));
      if(ncost < min_cost[cur][to]) {
        min_cost[cur][to] = ncost;
        que.emplace(ncost, cur, to);
      }
    }
  }

  return INF;
}

int main()
{
  int N;
  while(scanf("%d", &N), N) {
    vector< Segment > segs(N);
    Point S, T;
    for(auto &s : segs) cin >> s;
    cin >> S >> T;
    vector< Point > ps;
    auto g = SegmentArrangement(segs, ps);

    double ret = Dijkstra(g, S, T, ps);
    if(ret >= INF) cout << -1 << endl;
    else cout << fixed << setprecision(12) << ret << endl;
  }
}