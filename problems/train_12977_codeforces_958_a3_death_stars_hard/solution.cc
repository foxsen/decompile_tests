#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100005;
const double PI = acos(-1.0);
const double eps = 0.5;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
int rnd() {
  int ret = 0;
  for (int i = (1); i <= (3); ++i) ret = ret * 1000 + rand() % 1000;
  return ret;
}
inline bool iszero(double x) { return x > -eps && x < eps; }
struct Point {
  double x, y;
  friend Point operator+(const Point &a, const Point &b) {
    return Point{a.x + b.x, a.y + b.y};
  }
  friend Point operator-(const Point &a, const Point &b) {
    return Point{a.x - b.x, a.y - b.y};
  }
  friend Point operator*(const Point &a, const Point &b) {
    return Point{a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
  }
  friend Point operator/(const Point &a, const double &b) {
    return Point{a.x / b, a.y / b};
  }
  friend Point operator/(const Point &a, const Point &b) {
    return Point{a.x * b.x + a.y * b.y, b.x * a.y - a.x * b.y} / b.len() /
           b.len();
  }
  inline double len() const { return sqrt(x * x + y * y); }
  inline double Len() const { return x * x + y * y; }
  inline friend bool operator<(const Point &a, const Point &b) {
    if (iszero(a.x - b.x)) {
      if (iszero(a.y - b.y)) return 0;
      return a.y < b.y;
    }
    return a.x < b.x;
  }
};
pair<double, int> A[N], B[N];
vector<pair<int, int> > V;
bool oka[N], okb[N];
Point a[N], b[N];
int n, n1, n2, x, y, t, c0, c1, k;
map<Point, int> M;
void check(int x1, int x2, int y1, int y2) {
  Point r = (a[x1] - a[x2]) / (b[y1] - b[y2]);
  Point c = a[x1] - b[y1] * r;
  c0 = c1 = 0;
  for (int i = (1); i <= (n2); ++i) {
    Point t = b[i] * r + c;
    if (M.find(t) != M.end())
      c1++;
    else
      c0++;
    if (c0 + 0.9 * n > n2) break;
    if ((double)c1 / (c0 + c1) < 0.1 && c0 + c1 > 25) break;
  }
  if (c1 < 0.9 * n) return;
  for (int i = (1); i <= (n2); ++i) {
    Point t = b[i] * r + c;
    if (M.find(t) != M.end()) {
      if (V.size() >= n) break;
      k = M[t];
      if (oka[k] || okb[i]) continue;
      V.push_back(make_pair(k, i)), oka[k] = okb[i] = 1;
    }
  }
  c0 = c1 = 1;
  while (1) {
    if (V.size() >= n) break;
    while (oka[c0]) c0++;
    while (okb[c1]) c1++;
    V.push_back(make_pair(c0, c1)), oka[c0++] = okb[c1++] = 1;
  }
  for (__typeof((V).begin()) it = (V).begin(); it != (V).end(); it++)
    printf("%d %d\n", it->first, it->second);
  exit(0);
}
void solve(int x, int y) {
  for (int i = (1); i <= (n1); ++i)
    A[i] = pair<double, int>{(a[i] - a[x]).Len(), i};
  for (int i = (1); i <= (n2); ++i)
    B[i] = pair<double, int>{(b[i] - b[y]).Len(), i};
  sort(A + 1, A + n1 + 1), sort(B + 1, B + n2 + 1), t = 2;
  for (int i = (2); i <= (n1); ++i) {
    while (t <= n2 && B[t].first + 1 < A[i].first) t++;
    for (int j = t; j <= n2 && B[j].first < A[i].first + 2; j++)
      check(x, A[i].second, y, B[j].second),
          check(x, A[i].second, B[j].second, y);
  }
}
int main() {
  srand(time(0));
  scanf("%d%d", &n, &n1);
  for (int i = (1); i <= (n1); ++i)
    scanf("%lf%lf", &a[i].x, &a[i].y), M[a[i]] = i;
  scanf("%d", &n2);
  for (int i = (1); i <= (n2); ++i) scanf("%lf%lf", &b[i].x, &b[i].y);
  while (1) solve(rnd() % n1 + 1, rnd() % n2 + 1);
  return 0;
}
