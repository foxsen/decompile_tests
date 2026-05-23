#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
constexpr auto MOD = 1000000007LL;
constexpr auto LINF = (1LL << 60);
constexpr auto INF = 2147483647LL;
constexpr auto PI = 3.1415926535897932384626433;
constexpr auto EPS = 1E-9;
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> p) {
  out << p.first << ' ' << p.second;
  return out;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v) in >> x;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> v) {
  for (int i = 0; i < v.size(); i++)
    out << v[i] << (i + 1 == v.size() ? '\n' : ' ');
  out.flush();
  return out;
}
using point_t = double;
struct point {
  point_t x, y;
  point() { x = y = 0; }
  point(point_t x, point_t y) : x(x), y(y) {}
  inline bool operator<(point rhs) const {
    if (fabs(x - rhs.x) > EPS) return x < rhs.x;
    return y < rhs.y;
  }
  inline bool operator==(point rhs) const {
    return (fabs(x - rhs.x) < EPS && fabs(y - rhs.y) < EPS);
  }
};
istream &operator>>(istream &in, point &pt) {
  in >> pt.x >> pt.y;
  return in;
}
struct vec {
  point_t x, y;
  vec(point_t x, point_t y) : x(x), y(y) {}
  vec(point a, point b) { *this = vec(b.x - a.x, b.y - a.y); }
  inline vec operator*(point_t r) const { return vec(x * r, y * r); }
  inline vec operator+(point x) const {
    return vec(this->x + x.x, this->y + x.y);
  }
};
inline point operator+(point p, vec v) {
  p.x += v.x;
  p.y += v.y;
  return p;
}
struct line {
  point_t a, b, c;
  line(point p1, point p2) {
    if (fabs(p1.x - p2.x) < EPS) {
      a = 1.0;
      b = 0.0;
      c = -p1.x;
      return;
    } else {
      a = -1.0 * (p1.y - p2.y) / (p1.x - p2.x);
      b = 1.0;
      c = -(a * p1.x) - p1.y;
      return;
    }
  }
};
inline point_t dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}
inline point_t dot(vec a, vec b) { return a.x * b.x + a.y * b.y; }
inline point_t norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
inline bool areParallel(line l1, line l2) {
  return (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS);
}
point_t distToLine(point p, point a, point b, point &ret) {
  vec ap = vec(a, p);
  vec ab = vec(a, b);
  point_t u = dot(ap, ab) / norm_sq(ab);
  ret = a + ab * u;
  return dist(p, ret);
}
point_t distToLineSegment(point p, point a, point b, point &ret) {
  vec ap = vec(a, p);
  vec ab = vec(a, b);
  point_t u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) {
    ret = a;
    return dist(p, a);
  } else if (u > 1.0) {
    ret = b;
    return dist(p, b);
  }
  return distToLine(p, a, b, ret);
}
inline bool areSame(line l1, line l2) {
  return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}
bool areIntersect(line l1, line l2, point &ret) {
  if (areParallel(l1, l2)) return false;
  ret.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS)
    ret.y = -(l1.a * ret.x + l1.c);
  else
    ret.y = -(l2.a * ret.x + l2.c);
  assert(fabs(ret.x * l1.a + ret.y * l1.b + l1.c) < EPS);
  return true;
}
point_t angle(point a, point o, point b) {
  vec oa = vec(o, a);
  vec ob = vec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
inline point rotate(point p, point_t theta) {
  point_t rad = theta * PI / 180.0;
  return point(p.x * cos(rad) - p.y * sin(rad),
               p.x * sin(rad) + p.y * cos(rad));
}
inline point_t cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
inline point_t ccw(point p, point q, point r) {
  return cross(vec(p, q), vec(p, r));
}
point_t area(const vector<point> &P) {
  point_t ret = 0, x1, y1, x2, y2;
  for (int i = 0; i + 1 < P.size(); i++) {
    x1 = P[i].x, x2 = P[i + 1].x;
    y1 = P[i].y, y2 = P[i + 1].y;
    ret += (x1 * y2 - x2 * y1);
  }
  return ret / 2;
}
bool isConvex(const vector<point> &P) {
  int sz = P.size();
  if (sz <= 3) return false;
  bool isLeft = (ccw(P[0], P[1], P[2]) > 0);
  for (int i = 1; i + 1 < sz; i++)
    if (ccw(P[i], P[i + 1], (i + 2 == sz ? P[1] : P[i + 2])) != isLeft)
      return false;
  return true;
}
bool inPolygon(point pt, const vector<point> &P) {
  if (P.size() == 0) return false;
  point_t sum = 0;
  for (int i = 0; i + 1 < P.size(); i++)
    if (ccw(pt, P[i], P[i + 1]) > 0)
      sum += angle(P[i], pt, P[i + 1]);
    else
      sum -= angle(P[i], pt, P[i + 1]);
  if (fabs(sum - 2 * PI) < EPS) return true;
  if (fabs(sum + 2 * PI) < EPS) return true;
  return false;
}
void sortList(vector<point> &a) {
  sort(a.begin(), a.end(), [](point x, point y) { return x.y < y.y; });
  sort(a.begin() + 1, a.end(), [&a](point x, point y) {
    point_t ret = ccw(x, a[0], y);
    if (fabs(ret) < EPS)
      return dist(x, a[0]) < dist(y, a[0]);
    else
      return ret < 0;
  });
  return;
}
vector<point> convexHull(vector<point> &a) {
  vector<point> ret;
  sortList(a);
  for (point x : a) {
    while (ret.size() >= 2 &&
           ccw(ret[ret.size() - 2], ret[ret.size() - 1], x) < -EPS)
      ret.pop_back();
    ret.push_back(x);
  }
  return ret;
}
void closestHelp(point *a, int l, int r, point_t &gmin) {
  if (l + 1 == r) return;
  int mid = l + r >> 1;
  closestHelp(a, l, mid, gmin);
  closestHelp(a, mid, r, gmin);
  vector<point> ord;
  int sweep = 0;
  for (int i = l, j = mid; i < mid && j < r;) {
    int id = (i < mid && (a[i].y < a[j].y || j < r) ? i++ : j++);
    while (sweep < ord.size() && a[id].y - ord[sweep].y >= gmin) sweep++;
    for (int i = sweep; i < ord.size(); i++)
      gmin = min(gmin, dist(ord[i], a[id]));
    ord.push_back(a[id]);
  }
  for (int i = 0; i < ord.size(); i++) a[i] = ord[i];
  return;
}
point_t closestPair(point *a, int n) {
  sort(a, a + n, [](point x, point y) { return x.x < y.x; });
  point_t res = LINF;
  closestHelp(a, 0, n, res);
  return res;
}
vector<point> a, b;
int main() {
  ios_base::sync_with_stdio(false);
  a.resize(4), b.resize(4);
  cin >> a >> b;
  a.push_back(a.front());
  b.push_back(b.front());
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      if (a[i] == b[j]) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  for (int i = 0; i < 4; i++) {
    if (inPolygon(a[i], b) || inPolygon(b[i], a)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      point at;
      if (areIntersect(line(a[i], a[(i + 1) % 4]), line(b[j], b[(j + 1) % 4]),
                       at)) {
        point to;
        distToLineSegment(at, a[i], a[(i + 1) % 4], to);
        if (at == to)
          ;
        else
          break;
        distToLineSegment(at, b[j], b[(j + 1) % 4], to);
        if (at == to) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  cout << "No" << endl;
  return 0;
}
