#include <bits/stdc++.h>
using namespace std;
int k, n;
const double ep = 1e-8;
const double pi = 3.14159265358979323846264338327950288L;
struct pnt {
  double x, y;
  pnt(double x = 0, double y = 0) : x(x), y(y) {}
  pnt operator+(const pnt &b) { return pnt(x + b.x, y + b.y); }
  pnt operator-(const pnt &b) { return pnt(x - b.x, y - b.y); }
  pnt operator*(const double &b) { return pnt(x * b, y * b); }
  pnt operator/(const double &b) { return pnt(x / b, y / b); }
  double operator&(const pnt &b) { return x * b.x + y * b.y; }
  double operator^(const pnt &b) { return x * b.y - b.x * y; }
  pnt rot() { return pnt(-y, x); }
  friend double dist(pnt a) { return sqrt(a.x * a.x + a.y * a.y); };
  void input() { scanf("%lf %lf", &x, &y); }
  void print() { printf("%.12lf %.12lf ", x, y); }
} p[10010];
pnt outc(pnt a, pnt b, pnt c) {
  return (a + b + (b - a).rot() * (a - c & b - c) / (a - c ^ b - c)) / 2;
}
bool vis[10010];
double del;
bool check(pnt O, double r, vector<int> &rlt) {
  if (dist(O) > 1000100 || r < 240000 || r > 760000) return 0;
  int cnt = 0;
  vector<int> cur;
  for (int i = 0; i < n * k; i++) {
    if (vis[i]) continue;
    double d = dist(O - p[i]);
    if (0.9 * r <= d && d <= 1.1 * r) cnt++, cur.push_back(i);
  }
  if (cnt < del * n) return 0;
  random_shuffle(cur.begin(), cur.end());
  rlt.clear();
  for (int i = 0; i < cnt && i < n; i++) vis[cur[i]] = 1, rlt.push_back(cur[i]);
  return 1;
}
vector<pnt> ans;
vector<double> ans_r;
bool good(pnt a, pnt b, pnt c) {
  if ((b - a & c - a) < 0) return 0;
  if ((c - b & a - b) < 0) return 0;
  if ((a - c & b - c) < 0) return 0;
  return 1;
}
bool solve(int cc) {
  if (cc == k) return 1;
  vector<int> vec;
  for (int j = 0; j < n * k; j++)
    if (!vis[j]) vec.push_back(j);
  int sz = vec.size(), cnt = 0;
  while (cnt < 100) {
    int a = rand() % sz, b = rand() % sz, c = rand() % sz;
    while (b == a) b = rand() % sz;
    while (c == b || c == a) c = rand() % sz;
    pnt O = outc(p[vec[a]], p[vec[b]], p[vec[c]]);
    double r = dist(O - p[vec[a]]);
    vector<int> vec;
    if (check(O, r, vec)) {
      ans[cc] = O, ans_r[cc] = r;
      if (solve(cc + 1)) return 1;
      int sz = vec.size();
      for (int j = 0; j < sz; j++) vis[vec[j]] = 0;
    }
    cnt++;
  }
  return 0;
}
int main() {
  scanf("%d %d", &k, &n);
  for (int i = 0; i < n * k; i++) p[i].input();
  random_shuffle(p, p + n * k);
  ans.resize(k), ans_r.resize(k);
  for (del = 1.0; !solve(0); del -= 0.03)
    ;
  for (int i = 0; i < k; i++) ans[i].print(), printf("%.12lf\n", ans_r[i]);
  return 0;
}
