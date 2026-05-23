////////////////////
// ???????????????
#include<cmath>
#include<algorithm>
#include<cassert>
////////////////////
// ??¨????????¢???
using D = double;
////////////////////
// ?????°
const D EPS = 1e-9;                // |EPS|???????????°???0??¨????????±???
enum POSITION {ONLINE_FRONT = -2, CLOCKWISE, ON_SEGMENT, COUNTER_CLOCKWISE, ONLINE_BACK};   // 3??????????????¢???
////////////////////
// ?§???????
struct Point {
  D x, y;
  Point(const D d = 0.0) : x(d), y(d) {}
  Point(const D x, const D y) : x(x), y(y) {}
};
struct Segment {
  Point ab, to;
  Segment(const Point& ab = 0, const Point& to = 0) : ab(ab), to(to) {}
  Segment(const D x1, const D y1, const D x2, const D y2) : ab(x1, y1), to(x2, y2) {}
};
struct Line {
  Point ab, to;
  Line(const Point& ab, const Point& to) : ab(ab), to(to) {}
  Line(const D x1, const D y1, const D x2, const D y2) : ab(x1, y1), to(x2, y2) {}
  Line(const Segment& s) : ab(s.ab), to(s.to) {}
};
////////////////////
// ????£?
bool relative_equal(const D d1, const D d2) {return d1 == 0 ? std::abs(d2) < EPS : std::abs((d1 - d2) / d1) < EPS;}
// ??????????????????????????????
bool operator==(const Point& lhs, const Point& rhs) {return relative_equal(lhs.x, rhs.x) && relative_equal(lhs.y, rhs.y);}
bool operator<(const Point& lhs, const Point& rhs) {return relative_equal(lhs.x, rhs.x) ? lhs.y < rhs.y : lhs.x < rhs.x;}
bool operator>(const Point& lhs, const Point& rhs) {return relative_equal(lhs.x, rhs.x) ? lhs.y > rhs.y : lhs.x > rhs.x;}
bool operator!=(const Point& lhs, const Point& rhs) {return !(lhs == rhs);}
bool operator<=(const Point& lhs, const Point& rhs) {return !(lhs > rhs);}
bool operator>=(const Point& lhs, const Point& rhs) {return !(lhs < rhs);}
const Point operator+(const Point& lhs, const Point& rhs) {return Point(lhs.x + rhs.x, lhs.y + rhs.y);}
const Point operator-(const Point& lhs, const Point& rhs) {return Point(lhs.x - rhs.x, lhs.y - rhs.y);}
const Point operator*(const Point& lhs, const Point& rhs) {return Point(lhs.x * rhs.x, lhs.y * rhs.y);}
const Point operator/(const Point& lhs, const Point& rhs) {return Point(lhs.x / rhs.x, lhs.y / rhs.y);}
const Point operator-(const Point& p) {return Point(-p.x, -p.y);}
// ???
D abs(const Point& p) {return std::hypot(p.x, p.y);}
D norm(const Point& p) {return p.x * p.x + p.y * p.y;}
D dot(const Point& a, const Point& b) {return a.x * b.x + a.y * b.y;}
D cross(const Point& a, const Point& b) {return a.x * b.y - a.y * b.x;}
// ??´???
bool parallel(const Line& l1, const Line& l2) {return relative_equal(0.0, cross(l2.to - l2.ab, l1.to - l1.ab));}
bool orthogonal(const Line& l1, const Line& l2) {return relative_equal(0.0, dot(l2.to - l2.ab, l1.to - l1.ab));}
// 3??????????????¢???
POSITION ccw(const Point& a, const Point& b, const Point& p) {
  Point v1 = b - a;
  Point v2 = p - a;
  if(cross(v1, v2) >= EPS) return COUNTER_CLOCKWISE;
  if(cross(v1, v2) <= -EPS) return CLOCKWISE;
  if(dot(v1, v2) <= -EPS) return ONLINE_BACK;
  if(norm(v1) < norm(v2)) return ONLINE_FRONT;              // ????????????: norm(v1)<norm(v2)+EPS?????¨WrongAnswer
  return ON_SEGMENT;
}
// ????????????
bool intersect(const Point& p1, const Point& p2) {return p1 == p2;}
bool intersect(const Point& p, const Segment& s) {return abs(p - s.ab) + abs(p - s.to) - abs(s.ab - s.to) <= EPS;}
bool intersect(const Segment& s, const Point& p) {return intersect(p, s);}
bool intersect(const Point& p, const Line& l) {return !parallel(Line(p, l.ab), Line(p, l.to));}
bool intersect(const Line& l, const Point& p) {return intersect(p, l);}
bool intersect(const Segment& s1, const Segment& s2) {
  return ccw(s1.ab, s1.to, s2.ab) * ccw(s1.ab, s1.to, s2.to) <= 0
      && ccw(s2.ab, s2.to, s1.ab) * ccw(s2.ab, s2.to, s1.to) <= 0;
}
bool intersect(const Segment& s, const Line& l) {
  auto v1 = l.to - l.ab;
  auto v2 = s.ab  - l.ab;
  auto v3 = s.to - l.ab;
  return cross(v1, v2) * cross(v1, v3) <= EPS;
}
bool intersect(const Line& l, const Segment& s) {return intersect(s, l);}
bool intersect(const Line& l1, const Line& l2) {return !parallel(l1, l2) || intersect(l1.ab, l2);}
// ???????§????
Point rotate(const Point& p, const D a) {return Point(p.x * std::cos(a) - p.y * std::sin(a), p.x * std::sin(a) + p.y * std::cos(a));}
Point projection(const Point& p, const Line& l) {
  auto v = l.ab - l.to;
  return l.ab + dot(p - l.ab, v) / norm(v) * v;
}
Point projection(const Line& l, const Point& p) {return projection(p, l);}
Point reflection(const Point& p, const Line& l) {return p + 2 * (projection(p, l) - p);}
Point reflection(const Line& l, const Point& p) {return reflection(p, l);}
// ?????¢
D distance(const Point& p1, const Point& p2) {
  auto p = p1 - p2;
  return hypot(p.x, p.y);
}
D distance(const Point& p, const Segment& s) {
  auto r = projection(s, p);
  return intersect(r, s) ? distance(p, r) : std::min(distance(p, s.ab), distance(p, s.to));
}
D distance(const Segment& s, const Point& p) {return distance(p, s);}
D distance(const Point& p, const Line& l) {return distance(p, projection(p, l));}
D distance(const Line& l, const Point& p) {return distance(p, l);}
D distance(const Segment& s1, const Segment& s2) {
  return intersect(s1, s2) ? 0.0 : std::min({distance(s1, s2.ab), distance(s1, s2.to), distance(s2, s1.ab), distance(s2, s1.to)});
}
D distance(const Segment& s, const Line& l) {return intersect(s, l) ? 0.0 : std::min(distance(s.ab, l), distance(s.to, l));}
D distance(const Line& l,const Segment& s) {return distance(s, l);}
D distance(const Line& l1, const Line& l2) {return intersect(l1, l2) ? 0.0 : distance(l1.ab, l2);}
// ??????
const Point crosspoint(const Line& l1, const Line& l2) {
  assert(intersect(l1, l2));
  if(parallel(l1, l2)) return l1.ab;                   // ???????????¨???l1????§?????????????
  D A = cross(l1.to - l1.ab, l2.to - l2.ab);
  D B = cross(l1.to - l1.ab, l1.to - l2.ab);
  return l2.ab + B / A * (l2.to - l2.ab);
}
const Point crosspoint(const Segment& s, const Line& l) {
  assert(intersect(s, l));
  if(parallel(s, l)) return s.ab;
  return crosspoint(Line(s), l);
}
const Point crosspoint(const Line& l, const Segment& s) {return crosspoint(s, l);}
const Point crosspoint(const Segment& s1, const Segment& s2) {
  assert(intersect(s1, s2));
  if(parallel(s1, s2)) {                                    // ???????????¨?????????????????????????????????
    if(intersect(s1.ab,  s2)) return s1.ab;
    if(intersect(s1.to, s2)) return s1.to;
    if(intersect(s2.ab,  s1)) return s2.ab;
    if(intersect(s2.to, s1)) return s2.to;
  }
  return crosspoint(Line(s1), Line(s2));
}
// ???????????°??¨
#include<iostream>
std::ostream& operator<<(std::ostream& os, const Point& p) {os<<"point: "; os<<"("<<p.x<<","<<p.y<<")"; return os;}
std::ostream& operator<<(std::ostream& os, const Segment& s) {os<<"segment: "; os<<s.ab<<" - "<<s.to; return os;}
std::ostream& operator<<(std::ostream& os, const Line& l) {os<<"line: "; os<<l.ab<<" - "<<l.to; return os;}

#include<bits/stdc++.h>
using namespace std;

const D INF = 1e18;

struct Mirror {
  int id;
  Segment body;
  Mirror(int i, D x1, D y1, D x2, D y2) : id(i), body(x1, y1, x2, y2) {}
};

struct Memo {
  D dist;
  int id;
  Point cp;
  Segment body;
};

int N;
vector<Point> P, Q;
vector<Mirror> M;
D TX, TY, LX, LY;

D check() {
  Segment lazer(TX, TY, LX, LY);
  for(auto i: M) if(intersect(lazer, i.body)) return INF;
  return distance(lazer.ab, lazer.to);
}

D check(vector<int> v) {
  if(v.empty()) return check();
//   vector<int>vv={0,1,0,1,0};
//   if(v!=vv)return INF;
//   for(auto i:v)cout<<" "<<i;cout<<endl;
  Point L(LX, LY);
  Point T(TX, TY);
  auto m = M;
  for(auto i: v) {
    Mirror t(-1, 0, 0, 0, 0);
    for(auto j: m) if(j.id == i) t = j;
    T = reflection(T, t.body);
    for(auto& j: m) {
      j.body.ab = reflection(j.body.ab, t.body);
      j.body.to = reflection(j.body.to, t.body);
    }
  }
//   cout<<"    "<<T<<endl;
  m = M;
  auto last = make_pair(-1, L);
  for(auto i: v) {
    Segment lazer(last.second, T);
    Memo memo;
    memo.id = -1;
    memo.dist = INF;
    for(auto j: m) {
      if(j.id == last.first) continue;
      if(!intersect(lazer, j.body)) continue;
      auto p = crosspoint(lazer, j.body);
      auto d = distance(last.second, p);
      if(d > memo.dist) continue;
      memo.dist = d;
      memo.cp = p;
      memo.id = j.id;
      memo.body = j.body;
    }
    if(memo.id != i) return INF;
    last = make_pair(memo.id, memo.cp);
    for(auto& j: m) {
      j.body.ab = reflection(j.body.ab, memo.body);
      j.body.to = reflection(j.body.to, memo.body);
    }
  }
  Segment lazer(last.second, T);
  for(auto j: m) {
    if(j.id == last.first) continue;
    if(!intersect(lazer, j.body)) continue;
    auto p = crosspoint(lazer, j.body);
    if(distance(last.second, p) < distance(last.second, T) + EPS) return INF;
  }
//   cout<<"    "<<distance(L, T)<<endl;
  return distance(L, T);
}

D dfs(vector<int>& v, int r) {
  D res = check(v);
  if(!r) return res;
  for(auto i = 0; i < N; ++i) {
    if(!v.empty() && v.back() == i) continue;
    v.emplace_back(i);
    res = min(res, dfs(v, r - 1));
    v.pop_back();
  }
  return res;
}

D solve() {
  M.clear();
  for(auto i = 0; i < N; ++i) M.emplace_back(i, P[i].x, P[i].y, Q[i].x, Q[i].y);
  vector<int> v;
  return dfs(v, 5);
}

int main() {
  while(cin >> N, N) {
    P.resize(N);
    Q.resize(N);
    for(auto i = 0; i < N; ++i) cin >> P[i].x >> P[i].y >> Q[i].x >> Q[i].y;
    cin >> TX >> TY >> LX >> LY;
    cout << setprecision(14) << fixed << solve() << endl;
  }
}