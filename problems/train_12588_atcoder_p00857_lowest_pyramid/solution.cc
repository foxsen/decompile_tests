#include<bits/stdc++.h>

#define EPS (1e-7)
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1 
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

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

//rad ????§???????????????¢?????§?????????????????¨
Point rotate(Point a,double rad){ return Point(cos(rad)*a.x - sin(rad)*a.y,sin(rad)*a.x + cos(rad)*a.y); }

// ??????????????¢????????????
double toRad(double agl){ return agl*M_PI/180.0; }


int ccw(Point p0,Point p1,Point p2){
  Point a = p1-p0;
  Point b = p2-p0;
  if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS)return CLOCKWISE;
  if(dot(a,b) < -EPS)return ONLINE_BACK;
  if(norm(a) < norm(b))return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool intersectLL(Line l, Line m) {
  return abs(cross(l.p2-l.p1, m.p2-m.p1)) > EPS || // non-parallel
         abs(cross(l.p2-l.p1, m.p1-l.p1)) < EPS;   // same line
}
bool intersectLS(Line l, Line s) {
  return cross(l.p2-l.p1, s.p1-l.p1)*       // s[0] is left of l
         cross(l.p2-l.p1, s.p2-l.p1) < EPS; // s[1] is right of l
}
bool intersectLP(Line l,Point p) {
  return abs(cross(l.p2-p, l.p1-p)) < EPS;
}
bool intersectSS(Line s, Line t) {
  return ccw(s.p1,s.p2,t.p1)*ccw(s.p1,s.p2,t.p2) <= 0 &&
         ccw(t.p1,t.p2,s.p1)*ccw(t.p1,t.p2,s.p2) <= 0;
}
bool intersectSP(Line s, Point p) {
  return abs(s.p1-p)+abs(s.p2-p)-abs(s.p2-s.p1) < EPS; // triangle inequality
}

Point projection(Line l,Point p) {
  double t = dot(p-l.p1, l.p1-l.p2) / norm(l.p1-l.p2);
  return l.p1 + (l.p1-l.p2)*t;
}
Point reflection(Line l,Point p) {
  return p + (projection(l, p) - p) * 2;
}
double distanceLP(Line l, Point p) {
  return abs(p - projection(l, p));
}
double distanceLL(Line l, Line m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m.p1);
}

double distanceLS(Line l, Line s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s.p1), distanceLP(l, s.p2));
}
double distanceSP(Line s, Point p) {
  Point r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s.p1 - p), abs(s.p2 - p));
}

double distanceSS(Line s, Line t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t.p1), distanceSP(s, t.p2)),
             min(distanceSP(t, s.p1), distanceSP(t, s.p2)));
}

Point crosspoint(Line l,Line m){
  double A = cross(l.p2-l.p1,m.p2-m.p1);
  double B = cross(l.p2-l.p1,l.p2-m.p1);
  if(abs(A) < EPS && abs(B) < EPS){
    vector<Point> vec;
    vec.push_back(l.p1),vec.push_back(l.p2),vec.push_back(m.p1),vec.push_back(m.p2);
    sort(vec.begin(),vec.end());
    assert(vec[1] == vec[2]); //???????????°??????????????????
    return vec[1];
    //return m.p1;
  }
  if(abs(A) < EPS)assert(false);
  return m.p1 + (m.p2-m.p1)*(B/A);
}


//cross product of pq and pr
double cross3p(Point p,Point q,Point r) { return (r.x-q.x) * (p.y -q.y) - (r.y - q.y) * (p.x - q.x); }
  
//returns true if point r is on the same line as the line pq
bool collinear(Point p,Point q,Point r) { return fabs(cross3p(p,q,r)) < EPS; }
  
//returns true if point t is on the left side of line pq
bool ccwtest(Point p,Point q,Point r){
  return cross3p(p,q,r) > 0; //can be modified to accept collinear points
}
 
bool onSegment(Point p,Point q,Point r){
  return collinear(p,q,r) && equals(sqrt(pow(p.x-r.x,2)+pow(p.y-r.y,2)) + sqrt(pow(r.x-q.x,2) + pow(r.y-q.y,2) ),sqrt(pow(p.x-q.x,2)+pow(p.y-q.y,2)) ) ;
}


double angle(Point a,Point b,Point c) {
  double ux = b.x - a.x, uy = b.y - a.y;
  double vx = c.x - a.x, vy = c.y - a.y;
  return acos((ux*vx + uy*vy)/sqrt((ux*ux + uy*uy) * (vx*vx + vy*vy)));
}  
  
//????§???¢poly?????????????????????????????????p????????¨??????????????????????????????  
bool inPolygon(Polygon &poly,Point p,bool onseg = true){
  if((int)poly.size() == 0)return false;
  if( onseg ) rep(i,(int)poly.size()) if(onSegment(poly[i],poly[(i+1)%(int)poly.size()],p))return true;
  double sum = 0;
  for(int i=0; i < (int)poly.size() ;i++) {
    if( equals(cross(poly[i]-p,poly[(i+1)%poly.size()]-p),0.0) ) continue; // ????????????????????¨angle???nan?????????sum???nan??????????????¬
    if( cross3p(p,poly[i],poly[(i+1)%poly.size()]) < 0 ) sum -= angle(p,poly[i],poly[(i+1)%poly.size()]);
    else                                                 sum += angle(p,poly[i],poly[(i+1)%poly.size()]);
  }
  // ?????????????????????????????????????????¨?????????????????§??\????????????????????? 
  const double eps = 1e-5;
  return (fabs(sum - 2*M_PI) < eps || fabs(sum + 2*M_PI) < eps);
}  

pair<Point, Point> crosspointCC( Point C1, double r1, Point C2, double r2) {
  complex<double> c1(C1.x,C1.y);
  complex<double> c2(C2.x,C2.y);
  complex<double> A = conj(c2-c1), B = (r2*r2-r1*r1-(c2-c1)*conj(c2-c1)), C = r1*r1*(c2-c1);
  complex<double> D = B*B-4.0*A*C;
  complex<double> z1 = (-B+sqrt(D))/(2.0*A)+c1, z2 = (-B-sqrt(D))/(2.0*A)+c1;
  return pair<Point, Point>(Point(z1.real(),z1.imag()),Point(z2.real(),z2.imag()));
}


// ------

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

bool isValid(Point p) { return LTE(-100.0,p.x) && LTE(p.x,100.0) && LTE(-100.0,p.y) && LTE(p.y,100.0); }

vector<Point> base(3),ps(3);

Point vir;
bool cmp_dist(const Point &p1,const Point &p2) {
  return LT(abs(vir-p1),abs(vir-p2));
}

// seg.p1 ??? base ?????????????????§???????????¨
// * 6
bool checkIntersect(Point p,Segment seg1,Segment seg2){

  // baseSeg ??¨ seg1 ????????? seg2 ??????????????¨?????°???????????????????§???¢???????????????
  rep(i,3) {
    Segment baseSeg = Segment(base[i],base[(i+1)%3]);
    if( equals(cross(baseSeg.p1-baseSeg.p2,seg1.p1-seg1.p2),0) &&
	equals(cross(baseSeg.p1-baseSeg.p2,seg2.p1-seg2.p2),0) ) return false;
  }

  // ?????§???????????´???????????§?????????????????§???????????§????????????????????????????§???¢??¨??????????????????????????§????????????
  Segment segs[2] = {seg1,seg2};
  rep(i,2){
    Segment seg = segs[i];
    rep(j,3){
      Segment baseSeg = Segment(base[j],base[(j+1)%3]);
      if( intersectSS(seg,baseSeg) ) {
	if( equals(cross(seg.p1-seg.p2,baseSeg.p1-baseSeg.p2),0) ) {
	//if( equals(cross(seg.p1-seg.p2,baseSeg.p1-baseSeg.p2),0) && seg.p1 == baseSeg.p1 ) {
	//int res = ccw(seg.p1,seg.p2,baseSeg.p2);
	//if( res == ONLINE_FRONT || res == ON_SEGMENT ) return false;

	  vector<Point> vec;
	  vec.push_back(seg.p1);
	  vec.push_back(seg.p2);
	  vec.push_back(baseSeg.p1);
	  vec.push_back(baseSeg.p2);
	  sort(vec.begin(),vec.end());
	  //vir = vec[0];
	  //sort(vec.begin(),vec.end(),cmp_dist);
	  vec.erase(unique(vec.begin(),vec.end()),vec.end());
	  rep(i,(int)vec.size()-1) {
	    Point mp = ( vec[i] + vec[i+1] ) / 2.0;
	    if( onSegment(seg.p1,seg.p2,mp) && onSegment(baseSeg.p1,baseSeg.p2,mp) ) return false;
	  }


	  continue;
	}
	Point cp = crosspoint(seg,baseSeg);
	if( !( cp == seg.p1 ) ) return false;
      }
    }
  }

  return true;
}

inline bool check(Point p,int j){
  // ??????????????????????????????p????????¨?????????
  if( !isValid(p) ) return false;

  // ????????????????§???¢??¨?????????????????????????§?????????°????????????



  // ????????????????§???¢???????????\?§????????????????????????????
  //if( inPolygon(base,p,true) ) return false;
  //return !inPolygon(base,p,true);
  double cs[3];

  rep(i,3) {
    if( onSegment(base[i],base[(i+1)%3],p) ) return false;
    Point a = base[(i+1)%3] - base[i];
    Point b = p - base[i];
    cs[i] = cross(a,b);
  }
  if( LT(cs[0],0) && LT(cs[1],0) && LT(cs[2],0) ) return false;
  if( LT(0,cs[0]) && LT(0,cs[1]) && LT(0,cs[2]) ) return false;

  if(!checkIntersect(p,Segment(base[j],p),Segment(base[(j+1)%3],p))) return false;

  return true;
  //return checkIntersect(p,Segment(base[i],p),Segment(base[(i+1)%3],p));
}

//???????????????????????????????????????????????????????????????????????§??????
bool FinalCheck(int limit = 3){
  Line lines[3][2];
  rep(i,limit) lines[i][0] = Line(base[i],ps[i]), lines[i][1] = Line(base[(i+1)%3],ps[i]);
  rep(i,limit) {
    REP(j,i+1,limit) {
      if( ps[i] == ps[j] ) return false;
      rep(k,2) {
	Segment ururu_beam1 = lines[i][k];
	rep(l,2){
	  Segment ururu_beam2 = lines[j][l];
	  if( intersectSS(ururu_beam1,ururu_beam2) ) {
	    Point cp = crosspoint(ururu_beam1,ururu_beam2);
	    if( cp == ururu_beam1.p1 && cp == ururu_beam2.p1 ) continue;
	    return false;
	  }
	}
      }
    }
  }
  return true;
}

double getH(){

  Line lines[3];
  rep(i,3){
    Vector e = ( base[i] - base[(i+1)%3] ) / abs( base[i] - base[(i+1)%3] );
    e = rotate(e,toRad(90.0));
    lines[i] = Line(ps[i],ps[i]+e*1000);
  }

  Point cp = crosspoint(lines[0],lines[1]);
  rep(i,3) if( cp == ps[i] ) return 1e30;
  
  Point onBaseP0 = crosspoint(lines[0],Line(base[0],base[1]));

  double a = abs(cp-onBaseP0);
  double b = abs(onBaseP0-ps[0]);
  if( equals(a,b) ) return 1e30;
  if( LTE(b,a) ) return 1e30;

  return sqrt(b*b-a*a);
}

void compute() {
  double mini = 1e30;
    REP(x1,-100,101){
  REP(y1,-100,101){
if(y1==-21||y1==66)continue;
      if( !check(Point(x1,y1),0) ) continue;
      ps[0] = Point(x1,y1);
      double lengthOfPs0ToBase1 = abs(ps[0]-base[1]);      
      //REP(x2,-100,101){
      for(int x2 = max(-100,(int)(base[1].x-lengthOfPs0ToBase1)); x2<=min(100,(int)(base[1].x+lengthOfPs0ToBase1));x2++ ) {
	double diff_x = abs(x2-base[1].x);
	if( LT(lengthOfPs0ToBase1,diff_x) ) continue;
	double diff_y = sqrt( lengthOfPs0ToBase1*lengthOfPs0ToBase1 - diff_x*diff_x );

	if( !equals(diff_y,(int)(diff_y+EPS)) ) continue;
	for(int coef=-1;coef<=1;coef+=2){ // ????£????????????????
	  double y2 = base[1].y + diff_y * (double)coef;
	  if( !( equals(y2,(int)(y2+EPS)) || equals(y2,(int)(y2-EPS)) ) ) continue;
	  if( !check(Point(x2,y2),1) ) continue;
	  ps[1] = Point(x2,y2);
	  if( !FinalCheck(2) ) continue;
	  pair<Point,Point> tmp = crosspointCC(base[0],abs(ps[0]-base[0]),base[2],abs(ps[1]-base[2]));
	  Point tps[2] = {tmp.first,tmp.second};
	  bool succ = false;
	  rep(i,2){
	    if( !check(tps[i],2) ) continue;
	    ps[2] = tps[i];

	    if( !( equals(ps[2].x,(int)(ps[2].x+EPS)) || equals(ps[2].x,(int)(ps[2].x-EPS)) ) || !( equals(ps[2].y,(int)(ps[2].y+EPS)) || equals(ps[2].y,(int)(ps[2].y-EPS)) ) ) continue;
	    if( !FinalCheck() ) continue;
	    double h = getH();
	    if( LT(h,mini) ) mini = h;
	    if( !equals(h,1e30) ) { succ = true; break; }
	  }
	  if( succ ) break;
	}
      }
    }
  }
  if( equals(mini,1e30) ) puts("-1");
  else printf("%.10f\n",mini);
}

int main() {
  while( 1 ){
    bool fin = true;
    rep(i,3) {
      scanf("%lf %lf",&base[i].x,&base[i].y);
      if( !( base[i] == Point(0,0) ) ) fin = false;
    }
    if( fin ) break;
    compute();
  }
  return 0;
}