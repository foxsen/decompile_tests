#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef complex<double> Point;
typedef vector<Point> VP;
#define X real()
#define Y imag()
const double EPS = 1e-9; // ?¨±?????????^2
#define LE(n,m) ((n) < (m) + EPS)
#define EQ(n,m) (abs((n)-(m)) < EPS)

namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

// ???p?????????a????????\????????\???
VP tangentPoints(Point a, double ar, Point p) {
  VP ps;
  double sin = ar / abs(p-a);
  if (!LE(sin, 1)) assert(false);  // ????????§NaN???????????????
  double t = M_PI_2 - asin(min(sin, 1.0));
  ps.push_back(a + (p-a)*polar(sin, t));
  assert(!EQ(sin, 1));
  ps.push_back(a + (p-a)*polar(sin, -t));
  return ps;
}

int main(void){
    double px,py,cx,cy,r;
    cin>>px>>py>>cx>>cy>>r;
    VP ps = tangentPoints(Point(cx,cy),r,Point(px,py));
    sort(all(ps));
    rep(k,2)printf("%.9f %.9f\n", ps[k].X,ps[k].Y);
    return 0;
}