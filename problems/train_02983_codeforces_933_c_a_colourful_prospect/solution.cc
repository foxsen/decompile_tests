#include <bits/stdc++.h>
using namespace std;
const int maxn = 3;
const long double eps = 1e-12;
int n, ted;
bool bad;
long double x[maxn], y[maxn], r[maxn], dis, tmp, a, b, A, B, C;
vector<pair<long double, long double> > t[maxn], fin[maxn], v;
long double gdis(long double x1, long double y1, long double x2,
                 long double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool eq(long double x1, long double y1, long double x2, long double y2) {
  if (abs(x1 - x2) < eps && abs(y1 - y2) < eps) return 1;
  return 0;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> r[i];
    for (int j = 0; j < i; j++) {
      dis = gdis(x[i], y[i], x[j], y[j]);
      if (abs(dis - r[i] - r[j]) < eps ||
          abs(max(r[i], r[j]) - min(r[i], r[j]) - dis) < eps) {
        if (abs(y[i] - y[j]) < eps) {
          a = ((r[j] * r[j] - r[i] * r[i]) - (x[j] * x[j] - x[i] * x[i])) /
              ((x[i] - x[j]) * 2);
          t[i].push_back({a, y[i]});
          t[j].push_back({a, y[i]});
          continue;
        }
        a = (x[j] - x[i]) / (y[i] - y[j]);
        b = ((x[i] * x[i] - x[j] * x[j]) + (y[i] * y[i] - y[j] * y[j]) -
             (r[i] * r[i] - r[j] * r[j])) /
            ((y[i] - y[j]) * 2);
        A = a * a + 1;
        B = a * b * 2 - x[i] * 2 - a * y[i] * 2;
        C = x[i] * x[i] + b * b + y[i] * y[i] - b * y[i] * 2 - r[i] * r[i];
        t[i].push_back({-B / (A * 2), a * (-B / (A * 2)) + b});
        t[j].push_back({-B / (A * 2), a * (-B / (A * 2)) + b});
      } else if (r[i] + r[j] > dis && dis > max(r[i], r[j]) - min(r[i], r[j])) {
        if (abs(y[i] - y[j]) < eps) {
          a = ((r[j] * r[j] - r[i] * r[i]) - (x[j] * x[j] - x[i] * x[i])) /
              ((x[i] - x[j]) * 2);
          b = sqrt((r[i] * r[i]) - (a - x[i]) * (a - x[i]));
          t[i].push_back({a, y[i] - b});
          t[j].push_back({a, y[i] - b});
          t[i].push_back({a, y[i] + b});
          t[j].push_back({a, y[i] + b});
          continue;
        }
        a = (x[j] - x[i]) / (y[i] - y[j]);
        b = ((x[i] * x[i] - x[j] * x[j]) + (y[i] * y[i] - y[j] * y[j]) -
             (r[i] * r[i] - r[j] * r[j])) /
            ((y[i] - y[j]) * 2);
        A = a * a + 1;
        B = a * b * 2 - x[i] * 2 - a * y[i] * 2;
        C = x[i] * x[i] + b * b + y[i] * y[i] - b * y[i] * 2 - r[i] * r[i];
        t[i].push_back({(-B - sqrt(B * B - A * C * 4)) / (A * 2),
                        a * ((-B - sqrt(B * B - A * C * 4)) / (A * 2)) + b});
        t[j].push_back({(-B - sqrt(B * B - A * C * 4)) / (A * 2),
                        a * ((-B - sqrt(B * B - A * C * 4)) / (A * 2)) + b});
        t[i].push_back({(-B + sqrt(B * B - A * C * 4)) / (A * 2),
                        a * ((-B + sqrt(B * B - A * C * 4)) / (A * 2)) + b});
        t[j].push_back({(-B + sqrt(B * B - A * C * 4)) / (A * 2),
                        a * ((-B + sqrt(B * B - A * C * 4)) / (A * 2)) + b});
      } else
        continue;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < ((int(t[i].size()))); j++) {
      bad = 0;
      for (int k = 0; k < ((int(fin[i].size()))); k++) {
        if (eq(t[i][j].first, t[i][j].second, fin[i][k].first,
               fin[i][k].second)) {
          bad = 1;
          break;
        }
      }
      if (!bad) fin[i].push_back(t[i][j]);
      bad = 0;
      for (int k = 0; k < ((int(v.size()))); k++) {
        if (eq(t[i][j].first, t[i][j].second, v[k].first, v[k].second)) {
          bad = 1;
          break;
        }
      }
      if (!bad) v.push_back(t[i][j]);
    }
  }
  bad = 0;
  for (int i = 0; i < n; i++) {
    if (((int(fin[i].size()))) > 0) {
      bad = 1;
      break;
    }
  }
  if (!bad) {
    cout << n + 1;
    return 0;
  }
  bad = 0;
  for (int i = 0; i < n; i++) {
    if (((int(fin[i].size()))) == 0) {
      bad = 1;
      break;
    }
  }
  for (int i = 0; i < n; i++) ted += ((int(fin[i].size())));
  if (bad) {
    cout << ted - ((int(v.size()))) + 3;
    return 0;
  }
  cout << ted - ((int(v.size()))) + 2;
  return 0;
}
