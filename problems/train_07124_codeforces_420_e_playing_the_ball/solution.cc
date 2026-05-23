#include <bits/stdc++.h>
using namespace std;
struct Fenwick {
  vector<int> t;
  int n;
  void init(int nn) {
    n = nn;
    t.assign(n, 0);
  }
  int sum(int r) {
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r];
    return result;
  }
  void inc(int i, int delta) {
    for (; i < n; i = (i | (i + 1))) t[i] += delta;
  }
  int sum(int l, int r) { return sum(r) - sum(l - 1); }
};
const int N = 20000;
const long double PI = acosl(-1.0);
double dist[N];
const double eps = 1e-8;
int x[N];
int y[N];
int r[N];
bool intersect(int i, int R, pair<long double, long double> &ret) {
  if (R < dist[i] - r[i] - eps) {
    return false;
  }
  if (R > dist[i] + r[i] + eps) {
    return false;
  }
  double a = -2.0 * x[i];
  double b = -2.0 * y[i];
  double c = x[i] * x[i] + y[i] * y[i] + R * R - r[i] * r[i];
  double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
  if (abs(c * c - R * R * (a * a + b * b)) < eps) {
    double alp = atan2(y0, x0);
    ret = make_pair(alp, alp);
  } else {
    double d = R * R - c * c / (a * a + b * b);
    double mult = sqrt(d / (a * a + b * b));
    double ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;
    double alp1 = atan2(ay, ax);
    double alp2 = atan2(by, bx);
    if (alp1 > alp2) {
      swap(alp1, alp2);
    }
    if (alp2 - alp1 > PI) {
      swap(alp1, alp2);
    }
    ret = make_pair(alp1, alp2);
  }
  return true;
}
struct event {
  long double pos;
  int add;
  event() {}
  event(long double p, int a) : pos(p), add(a) {}
  bool operator<(const event &r) const {
    if (fabs(pos - r.pos) < eps) {
      if (add == 1 && r.add == -1) {
        return true;
      }
      return false;
    }
    return pos < r.pos;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int d;
  cin >> d;
  double di = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> r[i];
    double cur = sqrt(x[i] * x[i] + y[i] * y[i]);
    dist[i] = cur;
  }
  di = *max_element(dist, dist + n) + 100;
  vector<event> e;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j * d < di; ++j) {
      pair<long double, long double> tmp;
      if (intersect(i, j * d, tmp)) {
        if (tmp.first > tmp.second + eps) {
          e.push_back(event(tmp.first, 1));
          e.push_back(event(PI, -1));
          e.push_back(event(-PI, 1));
          e.push_back(event(tmp.second, -1));
        } else {
          e.push_back(event(tmp.first, 1));
          e.push_back(event(tmp.second, -1));
        }
      }
    }
  }
  stable_sort(e.begin(), e.end());
  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < (int)e.size(); ++i) {
    cnt += e[i].add;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
