#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-6)
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1 
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

using namespace std;

class Point{
public:
  double x,y;
  Point(double x = 0,double y = 0): x(x),y(y){}
  Point operator + (Point p){return Point(x+p.x,y+p.y);}
  Point operator - (Point p){return Point(x-p.x,y-p.y);}
  Point operator * (double a){return Point(a*x,a*y);}
  Point operator / (double a){return Point(x/a,y/a);}
  Point operator * (Point a){ return Point(x * a.x - y * a.y, x * a.y + y * a.x); }
  bool operator < (const Point& p) const{ return !equals(x,p.x)?x<p.x:(!equals(y,p.y)&&y<p.y); }
  bool operator == (const Point& p)const{ return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS; }
};

struct Segment{
  Point p1,p2;
  Segment(Point p1 = Point(),Point p2 = Point()):p1(p1),p2(p2){}
  bool operator <  (const Segment& s) const { return ( p2 == s.p2 ) ? p1 < s.p1 : p2 < s.p2; }
  bool operator == (const Segment& s) const { return ( s.p1 == p1 && s.p2 == p2 ) || ( s.p1 == p2 && s.p2 == p1 ); }

};

typedef Point Vector;
typedef Segment Line;
typedef vector<Point> Polygon;

ostream& operator << (ostream& os,const Point& a){ os << "(" << a.x << "," << a.y << ")"; }

ostream& operator << (ostream& os,const Segment& a){ os << "( " << a.p1 << " , " << a.p2 << " )"; }

double dot(Point a,Point b){ return a.x*b.x + a.y*b.y; }

double cross(Point a,Point b){ return a.x*b.y - a.y*b.x; }

double norm(Point a){ return a.x*a.x+a.y*a.y; }

double abs(Point a){ return sqrt(norm(a)); }

int ccw(Point p0,Point p1,Point p2){
  Point a = p1-p0;
  Point b = p2-p0;
  if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS)return CLOCKWISE;
  if(dot(a,b) < -EPS)return ONLINE_BACK;
  if(norm(a) < norm(b))return ONLINE_FRONT;
  return ON_SEGMENT;
}

Polygon andrewScan(Polygon s) {
  Polygon u,l;
  if(s.size() < 3)return s;

  sort(s.begin(),s.end());

  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size()-1]);
  l.push_back(s[s.size()-2]);

  for(int i=2;i<s.size();i++) {
      for(int n=u.size();n >= 2 && ccw(u[n-2],u[n-1],s[i]) != CLOCKWISE; n--)
        u.pop_back();
      u.push_back(s[i]);
    }

  for(int i=s.size()-3; i>=0 ; i--) {
      for(int n=l.size(); n >= 2 && ccw(l[n-2],l[n-1],s[i]) != CLOCKWISE; n--)
        l.pop_back();
      l.push_back(s[i]);
    }

  reverse(l.begin(),l.end());

  for(int i = u.size()-2; i >= 1; i--) l.push_back(u[i]);

  return l;
}

inline double heron(Point A,Point B,Point C){
  double a = abs(B-C);
  double b = abs(A-C);
  double c = abs(A-B);
  double s = ( a + b + c ) / 2;
  return sqrt( s * ( s - a ) * ( s - b ) * ( s - c ) );
}

// -----------------------------------------------------------

const int MAX_V = 1510;
int V,nV;
vector<Point> ps,nps;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

static const double RATIO = ( 1 + sqrt(5.0) ) * 0.5;
double ternarySearch(int a,int b){
  int L = 1, R = ( a > b ) ? ( ( a - b - 1 + nV ) % nV ) : ( ( ( a + nV ) - b - 1  ) % nV );
  int sp = b;
  int pL = L, pR = R;


  rep(_,120){
    if( LT(heron(nps[((L+R*2)/3+sp)%nV],nps[a],nps[b]),heron(nps[((L*2+R)/3+sp)%nV],nps[a],nps[b])) ) {
      R = ( L + R * 2 ) / 3;
    } else {
      L = ( L * 2 + R ) / 3;
    }
    if( R == pR && L == pL ) break;
    pR = R, pL = L;
  }

  /*
  double Lv = heron(nps[a],nps[b],nps[((int)((L*RATIO+R)/(1+RATIO))+sp)%nV]);
  double Rv = heron(nps[a],nps[b],nps[((int)((L+R*RATIO)/(1+RATIO))+sp)%nV]);
  rep(_,120){
    if( LT(Rv,Lv) ) {
      R = ( L + R * RATIO ) / ( 1 + RATIO );
      Rv = Lv;
      Lv = heron(nps[a],nps[b],nps[((int)((L*RATIO+R)/(1+RATIO))+sp)%nV]);
    } else {
      L = ( L * RATIO + R ) / ( 1 + RATIO );
      Lv = Rv;
      Rv = heron(nps[a],nps[b],nps[((int)((L+R*RATIO)/(1+RATIO))+sp)%nV]);
    }
    if( R == pR && L == pL ) break;
    pR = R, pL = L;
  }
  
  if( LT(Rv,Lv) ) R = ( L + R * RATIO ) / ( 1 + RATIO );
  else            L = ( L * RATIO + R ) / ( 1 + RATIO );
  */
  return heron(nps[(int)(((L+R)*0.5)+sp)%nV],nps[a],nps[b]);
}

void compute(){
  nps = andrewScan(ps);
  nV = nps.size();  
  double maxi = 0;
  if( nV == 3 ) {
    rep(i,V) {
      if( nps[0] == ps[i] || nps[1] == ps[i] || nps[2] == ps[i] ) continue;
      double area1 = heron(nps[0],nps[1],ps[i]);
      double area2 = heron(nps[1],nps[2],ps[i]);
      double area3 = heron(nps[2],nps[0],ps[i]);
      double area4 = heron(nps[0],nps[1],nps[2]);
      maxi = max(maxi,area4-min(area1,min(area2,area3)));
    }
  } else {
    rep(i,nV) REP(j,i+2,nV) maxi = max(maxi,ternarySearch(i,j)+ternarySearch(j,i));
  }
  printf("%.1f\n",maxi);
}

int main(){
  scanf("%d",&V);
  ps.resize(V);
  rep(i,V) scanf("%lf %lf",&ps[i].x,&ps[i].y);
  compute();
  return 0;
}