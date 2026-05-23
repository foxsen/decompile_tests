#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

struct P {
  int x,y;
  P(int x, int y) : x(x),y(y) {}
  P() {}
};
bool operator==(const P &a, const P &b) {
  return a.x==b.x&&a.y==b.y;
}
bool ok1(const P &a, const P &b) {
  return a.x==b.x||a.y==b.y;
}
bool ok2(const P &a, const P &b) {
  return abs(a.x-b.x) == abs(a.y-b.y);
}
bool ok3(const P &a, const P &b) {
  return ok1(a,b)||ok2(a,b);
}
vector<P> candidate(const P &a, const P &b) {
  vector<P> v;
  v.push_back(P(a.x,b.y));
  v.push_back(P(b.x,a.y));
  int dx = abs(a.x-b.x);
  int dy = abs(a.y-b.y);
  v.push_back(P(a.x+dy,b.y));
  v.push_back(P(a.x-dy,b.y));
  v.push_back(P(b.x+dy,a.y));
  v.push_back(P(b.x-dy,a.y));
  v.push_back(P(a.x,b.y+dx));
  v.push_back(P(a.x,b.y-dx));
  v.push_back(P(b.x,a.y+dx));
  v.push_back(P(b.x,a.y-dx));
  int t = a.x-a.y+b.x+b.y;
  //if (t%2 == 0)
    v.push_back(P(t/2,(-a.x+a.y+b.x+b.y)/2));
  t = b.x-b.y+a.x+a.y;
  //if (t%2 == 0)
    v.push_back(P(t/2,(-b.x+b.y+a.x+a.y)/2));
  return v;
}
vector<P> base;
P p1,p2,p;
bool canBuild(const P &a) {
  int cnt = 0;
  FOR(it, base) if (ok3(*it, a)) cnt++;
  return cnt>=2;
}
bool same(const P &a) {
  FOR(it, base) if (*it==a) return 1;
  return 0;
}

bool solve2() {
  vector<P> v;
  REP(i, base.size()) {
    REP(j, i) {
      vector<P> tmp = candidate(base[i], base[j]);
      FOR(jt, tmp) v.push_back(*jt);
    }
  }
  FOR(it, v) {
    //cout << it->x << ", " << it->y << endl;
    if (!same(*it) && canBuild(*it)) {
      base.push_back(*it);
      if (canBuild(p)) return 1;
      base.pop_back();
    }
  }
  return 0;
}
bool solve3() {
  vector<P> v = candidate(p1,p2);
  FOR(it, v) {
    if (!same(*it) && canBuild(*it)) {
      base.push_back(*it);
      if (solve2()) return 1;
      base.pop_back();
    }
  }
  return 0;
}

int main() {
  int T;cin>>T;
  REP(t,T) {
    cin>>p1.x>>p1.y>>p2.x>>p2.y>>p.x>>p.y;
    base.clear();
    base.push_back(p1); base.push_back(p2);
    bool f1 = ok3(p1,p);
    bool f2 = ok3(p2,p);
    if (p1==p||p2==p) cout << 0 << endl;
    else if (f1 && f2) cout << 1 << endl;
    else if (solve2()) cout << 2 << endl;
    else if (ok3(p1,p2)||solve3()) cout << 3 << endl;
    else cout << 4 << endl;
  }
}