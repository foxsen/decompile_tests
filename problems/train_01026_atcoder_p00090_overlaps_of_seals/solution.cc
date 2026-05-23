#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <complex>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

typedef complex<double> Point;

int n;
Point point[200];
pair<double, int> radian[1000];
bool used[1000];

int calc(int index) {
  int m = 0;
  REP(i, n) {
    double d = abs(point[index] - point[i]) / 2.0;
    if (i == index || d - 1.0 > EPS) { continue; }
    Point center = (point[index] + point[i]) / 2.0;
    Point vect = (point[i] - point[index]) * Point(0, -1);
    vect /= abs(vect);
    double l = sqrt(1 - d * d);
    if (isnan(l)) { l = EPS; }
    Point c1 = center + vect * l;
    Point c2 = center - vect * l;
    double arg1 = arg(c1 - point[index]) - EPS;
    double arg2 = arg(c2 - point[index]) + EPS;
    radian[m++] = make_pair(arg1, (i + 1));
    radian[m++] = make_pair(arg2, -(i + 1));
  }
  sort(radian, radian + m);
  MEMSET(used, false);
  int lsum = 1;
  int ret = 1;
  REP(iter, 2) {
    REP(i, m) {
      int p = abs(radian[i].second) - 1;
      bool start = radian[i].second > 0 ? true : false;
      if (start) {
        used[p] = true;
        lsum++;
      } else if (used[p]) {
        used[p] = false;
        lsum--;
      }
      ret = max(ret, lsum);
    }
  }
  return ret;
}

int main() {
  while (scanf("%d", &n), n) {
    REP(i, n) {
      double x, y;
      scanf("%lf,%lf", &x, &y);
      point[i] = Point(x, y);
    }
    int ans = 1;
    REP(i, n) {
      ans = max(ans, calc(i));
    }
    printf("%d\n", ans);
  }
}