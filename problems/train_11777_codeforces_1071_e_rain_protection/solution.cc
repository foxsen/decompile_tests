#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long double eps1 = 1e-4;
const long double eps2 = 1e-10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
struct point {
  long double x, y;
  point() {}
  point(long double x, long double y) : x(x), y(y) {}
  point operator+(const point &A) const { return point(x + A.x, y + A.y); }
  point operator-(const point &A) const { return point(x - A.x, y - A.y); }
  point operator*(long double v) const { return point(x * v, y * v); }
  bool operator<(const point &A) const {
    return x < A.x - eps1 || (fabsl(x - A.x) < eps1 && y < A.y - eps1);
  }
  bool operator==(const point &A) const {
    return fabsl(x - A.x) < eps1 && fabsl(y - A.y) < eps1;
  }
  long double operator%(const point &A) const { return x * A.y - y * A.x; }
  void print() { cerr << x << ' ' << y << '\n'; }
};
struct line {
  point p, v;
  line() {}
  line(point p, point q) : p(p), v(q - p) {}
  void setkb(long double k, long double b) {
    *this = line(point(0, b), point(1, k + b));
  }
} l[N];
vector<point> sec(line a, line b) {
  vector<point> ret;
  if (fabsl(b.v % a.v) < eps2) {
    if (fabsl(b.v % (a.p - b.p)) < eps2)
      ret.push_back(b.p), ret.push_back(b.p + b.v);
    return ret;
  }
  long double tmp = ((a.p - b.p) % a.v) / (b.v % a.v);
  if (-eps2 <= tmp && tmp <= 1 + eps2) ret.push_back(b.p + b.v * tmp);
  return ret;
}
int n, w, h, e1, e2, t[N];
bool sec(line l, vector<point> vec, point &p, point &q) {
  set<point> all;
  for (int j = 0; j < int(vec.size()); j++) {
    vector<point> tmp = sec(l, line(vec[j], vec[(j + 1) % int(vec.size())]));
    for (auto p : tmp) all.insert(p);
  }
  assert(int(all.size()) <= 2);
  if (int(all.size()) == 0) return 0;
  if (int(all.size()) == 1)
    p = q = *all.begin();
  else
    p = *all.begin(), q = *all.rbegin();
  return 1;
}
bool check(long double mid) {
  point p = point(e1, e2), q = p;
  for (int i = 1; i <= n; i++) {
    vector<point> vec;
    long double d = (t[i] - t[i - 1]) * mid;
    vec.push_back(p + point(-d, d));
    vec.push_back(p + point(d, d));
    vec.push_back(q + point(d, d));
    vec.push_back(q + point(d, -d));
    vec.push_back(q + point(-d, -d));
    vec.push_back(p + point(-d, -d));
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    while (int(vec.size()) > 1 && vec.back() == vec[0]) vec.pop_back();
    if (int(vec.size()) == 1) {
      auto r = vec[0], p = l[i].p, q = l[i].p + l[i].v;
      if (!(fabsl((r - p) % (r - q)) < eps2)) return 0;
      continue;
    }
    if (!sec(l[i], vec, p, q)) return 0;
    if (p == q) {
      if (!(-eps2 <= p.x && p.x <= w + eps2 && -eps2 <= p.y && p.y <= w + eps2))
        return 0;
    } else {
      vec.clear();
      vec.push_back(point(0, 0));
      vec.push_back(point(w, 0));
      vec.push_back(point(w, w));
      vec.push_back(point(0, w));
      point r, s;
      if (!sec(line(p, q), vec, r, s)) return 0;
      if (p.x < r.x) p = r;
      if (q.x > s.x) q = s;
      if (p.x > q.x) return 0;
    }
  }
  return 1;
}
int main() {
  cin >> n >> w >> h >> e1 >> e2;
  cout << setprecision(15) << fixed;
  cerr << setprecision(15) << fixed;
  for (int i = 1, a, b; i <= n; i++) {
    t[i] = gi();
    a = gi();
    b = gi();
    l[i].setkb(1.0 * (b - h) / b, 1.0 * a * h / b);
  }
  long double l = 0, r = w + 1;
  for (int T = 1; T <= 50; T++) {
    long double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (l > w + 0.5)
    cout << -1;
  else
    cout << l;
  return 0;
}
