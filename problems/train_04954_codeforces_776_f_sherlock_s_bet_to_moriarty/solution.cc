#include <bits/stdc++.h>
using namespace std;
const int N = 100500;
const double PI = acos(-1);
const double EPS = 1e-9;
bool eq(double a, double b) { return abs(a - b) < EPS; }
bool ls(double a, double b) { return a < b && !eq(a, b); }
bool ls_eq(double a, double b) { return a < b || eq(a, b); }
bool gr(double a, double b) { return a > b && !eq(a, b); }
bool gr_eq(double a, double b) { return a > b || eq(a, b); }
struct Point {
  double x, y;
  Point() : x(), y() {}
  Point(double _x, double _y) : x(_x), y(_y) {}
  void scan() { scanf("%lf%lf", &x, &y); }
  Point operator+(Point p) const { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double k) const { return Point(x * k, y * k); }
  Point ort() const { return Point(-y, x); }
  Point rotate(double a) const { return *this * cos(a) + ort() * sin(a); }
  double operator*(Point p) const { return x * p.y - y * p.x; }
  int q() {
    if (gr(x, 0) && gr_eq(y, 0)) return 0;
    if (ls_eq(x, 0) && gr(y, 0)) return 1;
    if (ls(x, 0) && ls_eq(y, 0)) return 2;
    return 3;
  }
};
struct Edge {
  int to;
  bool used;
  Edge() : to(), used() {}
  Edge(int _to) : to(_to), used() {}
};
struct Triple {
  vector<int> a;
  Triple(int x, int y, int z) {
    a.push_back(x);
    a.push_back(y);
    a.push_back(z);
  }
  bool operator<(const Triple &o) const { return a < o.a; }
};
int n, m;
Point pts[N];
vector<Edge> go[N];
vector<Triple> triples;
map<pair<int, int>, vector<Triple>> incident;
int tsz;
vector<int> tree[N];
bool blocked[N];
int tsize[N];
int color[N];
struct CmpAround {
  Point O;
  CmpAround(Point _O) : O(_O) {}
  bool operator()(const Edge &p1, const Edge &p2) {
    Point a = pts[p1.to] - O;
    Point b = pts[p2.to] - O;
    if (a.q() != b.q()) return a.q() < b.q();
    return gr(a * b, 0);
  }
};
pair<int, int> mp(int x, int y) {
  if (x > y) swap(x, y);
  return {x, y};
}
void collect(int v, int sv) {
  pts[n] = pts[sv];
  vector<int> facet;
  vector<pair<int, int>> facet_edges;
  facet.push_back(sv);
  facet_edges.push_back(mp(sv, v));
  while (v != sv) {
    facet.push_back(v);
    int id = upper_bound(go[v].begin(), go[v].end(), n, CmpAround(pts[v])) -
             go[v].begin();
    if (id == (int)go[v].size()) id = 0;
    pts[n] = pts[v];
    go[v][id].used = true;
    facet_edges.push_back(mp(v, go[v][id].to));
    v = go[v][id].to;
  }
  if ((int)facet.size() == n) return;
  sort(facet.begin(), facet.end());
  int fsz = (int)facet.size();
  if (fsz < 3) throw;
  triples.emplace_back(facet[fsz - 1], facet[fsz - 2], facet[fsz - 3]);
  for (auto e : facet_edges) incident[e].push_back(triples.back());
}
int get_trip(Triple x) {
  return lower_bound(triples.begin(), triples.end(), x) - triples.begin();
}
void calc_size(int v, int p) {
  tsize[v] = 1;
  for (int to : tree[v]) {
    if (to == p || blocked[to]) continue;
    calc_size(to, v);
    tsize[v] += tsize[to];
  }
}
int get_centroid(int v, int p, int full_sz) {
  for (int to : tree[v]) {
    if (to == p || blocked[to]) continue;
    if (2 * tsize[to] > full_sz) return get_centroid(to, v, full_sz);
  }
  return v;
}
void centroid(int v, int depth) {
  calc_size(v, -1);
  int root = get_centroid(v, -1, tsize[v]);
  color[root] = depth;
  blocked[root] = true;
  for (int to : tree[root]) {
    if (blocked[to]) continue;
    centroid(to, depth + 1);
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  if (m == 0) {
    puts("1");
    return;
  }
  double angle = 2 * PI / n;
  for (int i = 0; i < n; i++) {
    pts[i] = Point(1e3, 0).rotate(angle * i);
    int j = (i + 1) % n;
    go[i].emplace_back(j);
    go[j].emplace_back(i);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    go[a].emplace_back(b);
    go[b].emplace_back(a);
  }
  for (int i = 0; i < n; i++)
    sort(go[i].begin(), go[i].end(), CmpAround(pts[i]));
  for (int i = 0; i < n; i++)
    for (auto &e : go[i])
      if (!e.used) {
        e.used = true;
        collect(e.to, i);
      }
  sort(triples.begin(), triples.end());
  for (auto e : incident) {
    const auto &vec = e.second;
    if ((int)vec.size() > 2) throw;
    if ((int)vec.size() == 1) continue;
    int a = get_trip(vec[0]);
    int b = get_trip(vec[1]);
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  tsz = (int)triples.size();
  centroid(0, 0);
  for (int i = 0; i < tsz; i++) printf("%d ", color[i] + 1);
  printf("\n");
}
int main() {
  solve();
  (void)0;
}
