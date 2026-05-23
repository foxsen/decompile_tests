#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  point(long long x, long long y) { this->x = x, this->y = y; }
  point() { this->x = 0, this->y = 0; }
  point operator-(point b) { return {this->x - b.x, this->y - b.y}; }
  point operator+(point b) { return {this->x + b.x, this->y + b.y}; }
};
long long dist(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
istream& operator>>(istream& in, point& a) {
  in >> a.x >> a.y;
  return in;
}
ostream& operator<<(ostream& out, point& a) {
  out << a.x << " " << a.y;
  return out;
}
bool operator<(point a, point b) {
  if (a.x < b.x) return true;
  if (a.x == b.x && a.y < b.y) return true;
  return false;
}
bool operator<=(point a, point b) {
  if (a.x < b.x) return true;
  if (a.x == b.x && a.y <= b.y) return true;
  return false;
}
struct line {
  long long a, b, c;
  line(point p1, point p2) {
    this->a = p1.y - p2.y;
    this->b = p2.x - p1.x;
    this->c = -1 * (a * p1.x + b * p1.y);
  }
  line(long long a, long long b, long long c) {
    this->a = a;
    this->b = b;
    this->c = c;
  }
  line() {
    this->a = 0;
    this->b = 0;
    this->c = 0;
  }
  long long sz(point p) { return this->a * p.x + this->b * p.y + this->c; }
};
istream& operator>>(istream& in, line& a) {
  in >> a.a >> a.b >> a.c;
  return in;
}
point f;
bool cmp(point a, point b) {
  line e(f, a);
  if (e.sz(b) < 0)
    return true;
  else if (e.sz(b) == 0 && dist(f, a) < dist(f, b))
    return true;
  return false;
}
long long area(vector<point> a) {
  long long w = 0;
  for (int i = 0; i < a.size(); i++)
    w +=
        (a[i].x + a[(i + 1) % a.size()].x) * (a[i].y - a[(i + 1) % a.size()].y);
  return w;
}
vector<point> convex_hull(vector<point> a) {
  sort(a.begin(), a.end());
  f = a[0];
  sort(a.begin() + 1, a.end(), cmp);
  vector<point> ans;
  ans.push_back(f);
  for (int i = 0; i < a.size(); i++) {
    while (ans.size() >= 2 &&
           area({ans[ans.size() - 2], ans[ans.size() - 1], a[i]}) <= 0)
      ans.pop_back();
    ans.push_back(a[i]);
  }
  return ans;
}
bool pr(point a, point b, point c) {
  if (c < b) swap(b, c);
  if (b <= a && a <= c) return true;
  return false;
}
bool polypoint(point a, vector<point>& poly) {
  int l = 0, r = poly.size();
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (area({poly[m], poly[0], a}) == 0) {
      if (pr(a, poly[m], poly[0])) return true;
      return false;
    }
    if (area({poly[m], poly[0], a}) > 0)
      r = m;
    else
      l = m;
  }
  if (l == 0 || r == poly.size()) return false;
  if (convex_hull({poly[0], poly[l], poly[r], a}).size() < 4)
    return true;
  else
    return false;
}
map<point, point> we;
vector<point> mincovmn(vector<vector<point>> s, point start) {
  vector<point> ans;
  ans.push_back(start);
  int sumsize = 0;
  for (int i = 0; i < s.size(); i++)
    reverse(s[i].begin(), s[i].end()), sumsize += s[i].size();
  for (int i = 0; i < sumsize; i++) {
    int vi = -1;
    point maxp;
    for (int j = 0; j < s.size(); j++) {
      if (s[j].size()) {
        if (vi == -1 || area({s[j].back(), {0, 0}, maxp}) >= 0) {
          vi = j;
          maxp = s[j].back();
        }
      }
    }
    s[vi].pop_back();
    ans.push_back(ans.back() + maxp);
  }
  ans.pop_back();
  return ans;
}
vector<point> mincov(vector<point> s1, vector<point> s2) {
  vector<point> ans;
  ans.push_back({0, 0});
  int l1 = 0, l2 = 0;
  while (l1 < s1.size() || l2 < s2.size()) {
    if (l1 == s1.size())
      ans.push_back(ans.back() + s2[l2++]);
    else if (l2 == s2.size())
      ans.push_back(ans.back() + s1[l1++]);
    else if (area({s1[l1], {0, 0}, s2[l2]}) >= 0)
      ans.push_back(ans.back() + s1[l1++]);
    else
      ans.push_back(ans.back() + s2[l2++]);
  }
  ans.pop_back();
  return ans;
}
vector<point> polyvector(vector<point>& poly) {
  vector<point> poly2;
  for (int i = 0; i < poly.size(); i++) {
    poly2.push_back(poly[i] - poly[(i + 1) % poly.size()]);
    we[poly2.back()] = poly[(i + 1) % poly.size()];
  }
  reverse(poly2.begin(), poly2.end());
  return poly2;
}
int main() {
  vector<point> poly[3];
  vector<point> zp;
  point v[3];
  for (int i = 0; i < 3; i++) {
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      point a;
      scanf("%lld%lld", &a.x, &a.y);
      poly[i].push_back(a);
    }
    poly[i] = convex_hull(poly[i]);
    poly[i] = polyvector(poly[i]);
    v[i] = we[poly[i][0]];
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    point a;
    scanf("%lld%lld", &a.x, &a.y);
    zp.push_back(a + a + a);
  }
  vector<point> mincovski =
      convex_hull(mincovmn({poly[0], poly[1], poly[2]}, v[0] + v[1] + v[2]));
  for (int i = 0; i < m; i++) {
    if (polypoint(zp[i], mincovski))
      printf("YES\n");
    else
      printf("NO\n");
  }
}
