#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <set>
#include <vector>

using namespace std;

#define EPS 1e-10
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point {
public:
  double x, y;
  Point() {};
  Point(double x, double y): x(x), y(y) {}

  Point operator + (const Point &p) { return Point(x + p.x, y + p.y); }
  Point operator - (const Point &p) { return Point(x - p.x, y - p.y); }
  Point operator * (double d) { return Point(d * x, d * y); }
  Point operator / (double d) { return Point(x / d, y / d); }

  bool operator < (const Point &p) const {
    return (x != p.x ? x < p.x : y < p.y);
  }

  bool operator == (const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }

  friend ostream& operator << (ostream &os, Point &p) {
    return os << "Point(" << p.x << ", " << p.y << ")";
  }
};

class Segment {
public:
  Point p1, p2;
  Segment(Point p1, Point p2): p1(p1), p2(p2) {}
  friend ostream& operator << (ostream &os, Segment &seg) {
    return os << "<" << seg.p1 << ", " << seg.p2 << ">";
  }
};

#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

class EP {
public:
  Point p;
  int id, st;
  EP() {}
  EP(Point p, int id, int st): p(p), id(id), st(st) {}
  bool operator < (const EP &ep) const {
    return (p.y == ep.p.y ? st < ep.st : p.y < ep.p.y);
  }
};

int manhattan_geo(vector<Segment> s) {
  vector<EP> EPs(s.size() * 2);

  for (int i = 0, k = 0; i < s.size(); i++) {
    if (s[i].p1.y == s[i].p2.y) {
      if (s[i].p1.x > s[i].p2.x) swap(s[i].p1, s[i].p2);
    } else if (s[i].p1.y > s[i].p2.y) swap(s[i].p1, s[i].p2);

    if (s[i].p1.y == s[i].p2.y) {
      EPs[k++] = EP(s[i].p1, i, LEFT);
      EPs[k++] = EP(s[i].p2, i, RIGHT);
    } else {
      EPs[k++] = EP(s[i].p1, i, BOTTOM);
      EPs[k++] = EP(s[i].p2, i, TOP);
    }
  }

  sort(EPs.begin(), EPs.end());

  set<int> bin_tree;
  int cnt = 0;

  for (int i = 0; i < EPs.size(); i++) {
    if (EPs[i].st == TOP) {
      bin_tree.erase(EPs[i].p.x);
    } else if (EPs[i].st == BOTTOM) {
      bin_tree.insert(EPs[i].p.x);
    } else if (EPs[i].st == LEFT) {
      set<int>::iterator b = bin_tree.lower_bound(s[EPs[i].id].p1.x);
      set<int>::iterator e = bin_tree.upper_bound(s[EPs[i].id].p2.x);
      cnt += distance(b, e);
    }
  }

  return cnt;
}

int main() {
  int n; cin >> n;
  vector<Segment> s;

  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    s.push_back(Segment(Point(x1, y1), Point(x2, y2)));
  }

  cout << manhattan_geo(s) << endl;
}