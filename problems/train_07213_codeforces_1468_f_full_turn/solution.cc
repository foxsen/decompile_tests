#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "bib/debug.h"
#else
#define debug
#define cerr if (false) cerr 
#endif
#define double long double
const double EPS = 1e-18;
const double PI = 2 * acos(0.0L);
template <typename T = double> 
struct point {
  T x = 0;
  T y = 0;
  
  bool operator < (point<T> const &other) const {
    if (x == other.x) {
      return y < other.y;
    }
    return x < other.x; 
  }
 
  template <typename U = double>
  point<double> operator + (point<U> const &other) { 
    point<double> res;
    res.x = x + other.x;
    res.y = y + other.y;
    return res; 
  }
 
  template <typename U = double>
  point<double> operator - (point<U> const &other) { 
    point<double> res;
    res.x = x - other.x;
    res.y = y - other.y;
    return res; 
  }     
  template <typename U = double> 
  point<double> operator / (U const &other) { 
    point<double> res;
    res.x = x / other;
    res.y = y / other;
    return res; 
  }  
};
 
template <typename T = double> 
int ccw(point<T> const &p1, point<T> const &p2, point<T> const &p3) { 
  // 1 if ccw (Counter Clockwise) Left turn
  // 0 if collinear
  // -1 if cw (Clockwise) Right turn
  auto val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
  if (val == 0) {
    return 0;  
  }
  return (val < 0) ? 1: -1; 
} 
 
template <typename T = double> 
T angleRad(point<T> const &p) {
  // return [0, 2PI[
  auto v = atan2(p.y, p.x);
  if (v < -EPS) {
    v += 2 * PI;
  }
  return v;
}
 
struct classcomp {
  bool operator() (const double& lhs, const double& rhs) const
  {return lhs < -EPS +rhs;}
};


int32_t main(int32_t argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  double pr = 1e6;
  int tt, qq = 0;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<point<double>> A(n), B(n);
    vector<pair<double, double>> C(n);
    vector<double> AN(n), AN2(n);
    map<double, int, classcomp> mp;
    for (int i = 0; i < n; i++) {
      cin >> A[i].x >> A[i].y;
      cin >> B[i].x >> B[i].y;
      auto a = angleRad(B[i] - A[i]);
      debug(a);
      C[i].first = a;
      a += PI;
      if (a > -EPS + 2 * PI) {
        a -= 2 * PI;
      }
      C[i].second = a;
      mp[C[i].first]++;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (mp.count(C[i].second)) {
        ans += mp[C[i].second];
      }
    }
    cout << ans / 2 << '\n';
  }
 
  return 0;
}
