#include <bits/stdc++.h>
using namespace std;
const double eps = 0.00000001;
struct punct {
  double x, y;
  punct() {}
  punct(double x1, double y1) {
    x = x1;
    y = y1;
  }
  bool operator<(const punct &aux) const {
    if (abs(x - aux.x) > eps) return x < aux.x;
    if (abs(y - aux.y) > eps) return y < aux.y;
    return false;
  }
  bool operator==(const punct &aux) const {
    return (abs(x - aux.x) < eps && abs(y - aux.y) < eps);
  }
} point[10010], centru;
struct cerc {
  double x, y, r;
  bool operator<(const cerc &aux) const {
    if (abs(x - aux.x) > eps) return x < aux.x;
    if (abs(y - aux.y) > eps) return y < aux.y;
    if (abs(r - aux.r) > eps) return r < aux.r;
    return false;
  }
  bool operator==(const cerc &aux) const {
    return (abs(x - aux.x) < eps && abs(y - aux.y) < eps &&
            abs(r - aux.r) < eps);
  }
} circle[210];
set<int> v[10010];
int noduri, muchii;
char vaz[10010];
vector<punct> intersectcircles(cerc c1, cerc c2) {
  vector<punct> sol;
  double d =
      sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
  if (d < abs(c1.r - c2.r) || c1.r + c2.r < d || abs(d) < eps) return sol;
  double a = (c1.r * c1.r - c2.r * c2.r + d * d) / (2 * d);
  double h = sqrt(c1.r * c1.r - a * a);
  punct p = punct(c1.x + a * (c2.x - c1.x) / d, c1.y + a * (c2.y - c1.y) / d);
  sol.push_back(
      punct(p.x + h * (c2.y - c1.y) / d, p.y - h * (c2.x - c1.x) / d));
  sol.push_back(
      punct(p.x - h * (c2.y - c1.y) / d, p.y + h * (c2.x - c1.x) / d));
  return sol;
}
int pecerc(cerc c, punct p) {
  return abs((p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y) -
             c.r * c.r) < eps;
}
int compare(int a, int b) {
  return atan2(point[a].y - centru.y, point[a].x - centru.x) <
         atan2(point[b].y - centru.y, point[b].x - centru.x);
}
void dfs(int nod) {
  vaz[nod] = 1;
  noduri++;
  muchii += v[nod].size();
  for (set<int>::iterator it = v[nod].begin(); it != v[nod].end(); it++)
    if (!vaz[*it]) dfs(*it);
}
int main() {
  int n, nr = 0, nregiuni = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lf%lf%lf", &circle[i].x, &circle[i].y, &circle[i].r);
  sort(circle + 1, circle + 1 + n);
  int x = 1;
  for (int i = 2; i <= n; i++)
    if (!(circle[i] == circle[i - 1])) circle[++x] = circle[i];
  n = x;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      vector<punct> intpoints = intersectcircles(circle[i], circle[j]);
      for (int q = 0; q < intpoints.size(); q++) point[++nr] = intpoints[q];
    }
  sort(point + 1, point + 1 + nr);
  x = 1;
  for (int i = 2; i <= nr; i++)
    if (!(point[i] == point[i - 1])) point[++x] = point[i];
  nr = x;
  for (int i = 1; i <= n; i++) {
    vector<int> oncircle;
    for (int j = 1; j <= nr; j++)
      if (pecerc(circle[i], point[j])) oncircle.push_back(j);
    if (oncircle.size() < 2)
      nregiuni++;
    else {
      centru = punct(circle[i].x, circle[i].y);
      sort(oncircle.begin(), oncircle.end(), compare);
      oncircle.push_back(oncircle[0]);
      for (int j = 0; j < oncircle.size() - 1; j++) {
        int a = oncircle[j], b = oncircle[j + 1];
        if (v[a].find(b) != v[a].end() || v[b].find(a) != v[b].end())
          nregiuni++;
        v[a].insert(b);
        v[b].insert(a);
      }
    }
  }
  for (int i = 1; i <= nr; i++)
    if (!vaz[i]) {
      noduri = muchii = 0;
      dfs(i);
      muchii /= 2;
      nregiuni += 2 - noduri + muchii - 1;
    }
  printf("%d", nregiuni + 1);
  return 0;
}
