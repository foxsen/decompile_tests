#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-7;
const long double PI = acos(-1);
bool eq(long double a, long double b) { return fabsl(a - b) <= EPS; }
struct point {
  long double x, y;
  int id;
  point(long double x = 0, long double y = 0) : x(x), y(y) {}
  point operator+(const point &o) const { return {x + o.x, y + o.y}; }
  point operator-(const point &o) const { return {x - o.x, y - o.y}; }
  point operator*(long double t) const { return {x * t, y * t}; }
  point operator/(long double t) const { return {x / t, y / t}; }
  long double operator*(const point &o) const { return x * o.x + y * o.y; }
  long double operator^(const point &o) const { return x * o.y - y * o.x; }
  bool operator<(const point &o) const {
    if (!eq(x, o.x)) return x < o.x;
    return y < o.y;
  }
  bool operator==(const point &o) const { return eq(x, o.x) and eq(y, o.y); }
};
long double norm(point a) { return sqrt(a * a); }
int ccw(point a, point b, point e) {
  long double tmp = (b - a) ^ (e - a);
  return (tmp > EPS) - (tmp < -EPS);
}
bool insideT(vector<point> &vet, point e) {
  int x = ccw(vet[0], vet[1], e);
  int y = ccw(vet[1], vet[2], e);
  int z = ccw(vet[2], vet[0], e);
  if (!x or !y or !z) return false;
  return !((x == 1 or y == 1 or z == 1) and (x == -1 or y == -1 or z == -1));
}
struct line {
  point p1, p2;
  long double a, b, c;
  line();
  line(point p1 = 0, point p2 = 0) : p1(p1), p2(p2) {
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = -(a * p1.x + b * p1.y);
  }
  line(long double a = 0, long double b = 0, long double c = 0)
      : a(a), b(b), c(c) {}
  long double eval(point p) { return a * p.x + b * p.y + c; }
  bool inside(point p) { return eq(eval(p), 0); }
  point normal() { return point(a, b); }
  point mid() { return point((p1 + p2) / 2); }
  long double len() { return norm(p2 - p1); }
  bool inside_seg(point p) {
    return (inside(p) and min(p1.x, p2.x) <= p.x and p.x <= max(p1.x, p2.x) and
            min(p1.y, p2.y) <= p.y and p.y <= max(p1.y, p2.y));
  }
};
point inter(line l1, line l2) {
  long double det = l1.a * l2.b - l1.b * l2.a;
  if (det == 0) return point(INF, INF);
  long double x = (l1.b * l2.c - l1.c * l2.b) / det;
  long double y = (l1.c * l2.a - l1.a * l2.c) / det;
  point ans = point(x, y);
  if (!l1.inside_seg(ans) or !l2.inside_seg(ans)) return point(INF, INF);
  return point(x, y);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  vector<vector<point> > tri;
  point a, b, c;
  vector<line> edges;
  vector<vector<point> > intt(3 * n);
  for (int i = 0; i < n; i++) {
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    edges.push_back({a, b});
    edges.push_back({b, c});
    edges.push_back({c, a});
    tri.push_back({a, b, c});
  }
  for (int i = 0; i < 3 * n; i++) {
    for (int j = i + 1; j < 3 * n; j++) {
      point ans = inter(edges[i], edges[j]);
      if (ans.x == INF) continue;
      intt[i].push_back(ans);
      intt[j].push_back(ans);
    }
  }
  vector<line> cut;
  for (int i = 0; i < 3 * n; i++) {
    sort(intt[i].begin(), intt[i].end());
    for (int j = 1; j < (int)intt[i].size(); j++)
      cut.push_back({intt[i][j - 1], intt[i][j]});
  }
  long double per = 0;
  for (auto c : cut) {
    bool k = true;
    for (auto t : tri)
      if (insideT(t, c.mid())) {
        k = false;
        break;
      }
    if (k) per += c.len();
  }
  cout << fixed << setprecision(12) << per << '\n';
  return 0;
}
