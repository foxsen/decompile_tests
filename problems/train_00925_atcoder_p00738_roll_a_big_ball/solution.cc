#include<bits/stdc++.h>
using namespace std;

/////////////////
// 2D geometry //
/////////////////
 
// 2D geometry basic //
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
#define X real
#define Y imag
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
struct L : public vector<P> {
  L(){};
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};
typedef vector<P> G;
struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
  double R(double h){
    return sqrt(max(r*r-h*h,0.0));
  }
};

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}
///////////////////
// 線と点の距離　//
///////////////////

// 点に最も近い線上の点 //
P projection(const L &l, const P &p){
  double t = dot(p-l[0],l[0]-l[1])/norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
//　直線と点の距離
double distanceLP(const L &l,const P &p){
  return abs(p-projection(l,p));
}

// 線分と点の内包判定
bool intersectSP(const L &s, const P &p) {
  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}
// 線分と点の距離 //
double distanceSP(const L &s, const P &p) {
  const P r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
// 線分同士の交差判定 //
bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
//
// solve
//

struct B{
  double x1,y1,x2,y2;
  int h;
  bool inter(L l){
    return ((x1<=l[0].X()&&l[0].X()<=x2)&&(y1<=l[0].Y()&&l[0].Y()<=y2))
            ||((x1<=l[1].X()&&l[1].X()<=x2)&&(y1<=l[1].Y()&&l[1].Y()<=y2));
  }
};

L line;
vector<B> b;
void init(){
  line.clear();
  b.clear();
}
bool input(){
  int n;
  cin>>n;
  if(n==0)return false;
  double tmp[4];
  cin>>tmp[0]>>tmp[1]>>tmp[2]>>tmp[3];
  line = L(P(tmp[0],tmp[1]),P(tmp[2],tmp[3]));
  for(int i=0;i<n;i++){
    int h;
    cin>>tmp[0]>>tmp[1]>>tmp[2]>>tmp[3]>>h;
    b.push_back(B{tmp[0],tmp[1],tmp[2],tmp[3],h});
  }
  return true;
}

double getR(double dist,double h){
  if(dist<h)return dist;
  double res = (dist*dist-h*h)/(2*h) + h;
  return res;
}
double notouchR(B b){
  const vector<L> bl = {
    L(P(b.x1,b.y1),P(b.x1,b.y2)),
    L(P(b.x1,b.y2),P(b.x2,b.y2)),
    L(P(b.x2,b.y2),P(b.x2,b.y1)),
    L(P(b.x2,b.y1),P(b.x1,b.y1))
  };
  const vector<P> bp ={
    P(b.x1,b.y1),
    P(b.x1,b.y2),
    P(b.x2,b.y1),
    P(b.x2,b.y2),
  };
  if(b.inter(line))return 0;
  for(auto i:bl)if(intersectSS(line,i))return 0;


  double dist = 1000000;
  for(auto i:bl){
    dist = min(dist,distanceSP(i,line[0]));
    dist = min(dist,distanceSP(i,line[1]));
  }
  for(auto i:bp){
    dist = min(dist,distanceSP(line,i));
  }
  return getR(dist,b.h);
}


double solve(){
  double ans = 10000;
  for(int i=0;i<b.size();i++){
    ans = min(notouchR(b[i]),ans);
  }
  return ans;
}


int main(){
  while(init(),input()){
    cout<<fixed<<setprecision(20)<<solve()<<endl;
  }
}