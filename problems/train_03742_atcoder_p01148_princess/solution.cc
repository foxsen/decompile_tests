#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-9)
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

bool intersectSS(Line s, Line t) {
  return ccw(s.p1,s.p2,t.p1)*ccw(s.p1,s.p2,t.p2) <= 0 &&
         ccw(t.p1,t.p2,s.p1)*ccw(t.p1,t.p2,s.p2) <= 0;
}

Point crosspoint(Line l,Line m){
  double A = cross(l.p2-l.p1,m.p2-m.p1);
  double B = cross(l.p2-l.p1,l.p2-m.p1);
  if(abs(A) < EPS && abs(B) < EPS){
    vector<Point> vec;
    vec.push_back(l.p1),vec.push_back(l.p2),vec.push_back(m.p1),vec.push_back(m.p2);
    sort(vec.begin(),vec.end());
    return vec[1];
  }
  return m.p1 + (m.p2-m.p1)*(B/A);
}

double cross3p(Point p,Point q,Point r) { return (r.x-q.x) * (p.y -q.y) - (r.y - q.y) * (p.x - q.x); }
bool collinear(Point p,Point q,Point r) { return fabs(cross3p(p,q,r)) < EPS; }
bool onSegment(Point p,Point q,Point r){
  return collinear(p,q,r) && equals(sqrt(pow(p.x-r.x,2)+pow(p.y-r.y,2)) + sqrt(pow(r.x-q.x,2) + pow(r.y-q.y,2) ),sqrt(pow(p.x-q.x,2)+pow(p.y-q.y,2)) ) ;
}

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

int N,M,B;
Polygon poly;
vector<double> pT,pVX,pVY;
vector<double> T,X,VX,VY,L;

const int IINF = INT_MAX;

Point vir;
bool comp_dist(const Point& p1,const Point& p2){ return LT(abs(vir-p2),abs(vir-p2)); }

double inner_function(Segment seg,Point p,double vx,double vy){
  const double TIME = 10000000; // pからTIME秒間だけ(vx,vy)に移動する
  Segment arrow = Segment(p,p+Point(vx*TIME,vy*TIME));  
  if( !intersectSS(seg,arrow) ) return IINF;
  if( equals(cross(seg.p1-seg.p2,arrow.p1-arrow.p2),0.0) ) {
    if( onSegment(seg.p1,seg.p2,p) ) return 0;
    vector<Point> ps;
    ps.push_back(arrow.p2);
    ps.push_back(seg.p1);
    ps.push_back(seg.p2);
    vir = p;
    sort(ps.begin(),ps.end(),comp_dist);
    return TIME * abs(ps[0]-arrow.p1) / abs(arrow.p2-arrow.p1);
  } else {
    Point cp = crosspoint(seg,arrow);
    return TIME * abs(cp-arrow.p1) / abs(arrow.p2-arrow.p1);
  }
}

// 線分seg1 と線分seg2 が交差しなければ -1 を返す
double crossTimeSS(Segment seg1,double vx1,double vy1,
                   Segment seg2,double vx2,double vy2){
  double ret = IINF, temp;

  temp = inner_function(seg1,seg2.p1,vx2-vx1,vy2-vy1);
  if( LT(temp,ret) ) ret = temp;

  temp = inner_function(seg1,seg2.p2,vx2-vx1,vy2-vy1);
  if( LT(temp,ret) ) ret = temp;

  temp = inner_function(seg2,seg1.p1,vx1-vx2,vy1-vy2);
  if( LT(temp,ret) ) ret = temp;

  temp = inner_function(seg2,seg1.p2,vx1-vx2,vy1-vy2);
  if( LT(temp,ret) ) ret = temp;
  
  return equals(ret,IINF) ? -1 : ret;
}

Point move(Point p,double vx,double vy,double t){ return Point(p.x+vx*t,p.y+vy*t); }

void compute(){
  vector<double> answer;
  rep(i,B){
    vector<Point> hit;
    rep(j,N){

      Segment bullet = Segment(Point(X[i],0),Point(X[i]-((L[i]*VX[i])/sqrt(VX[i]*VX[i]+VY[i]*VY[i])),
                                                0-((L[i]*VY[i])/sqrt(VX[i]*VX[i]+VY[i]*VY[i]))));

      Segment vline = Segment(poly[j],poly[(j+1)%N]);

      bool First = true;
      double cur = -1;
      rep(k,(int)pT.size()-1){
        if( !( First && !( LTE(pT[k],T[i]) && LTE(T[i],pT[k+1]) ) ) ) {
          Segment seg = vline;
          if( First ) {
            cur = T[i];
            seg = Segment(move(seg.p1,pVX[k],pVY[k],T[i]-pT[k]),
                          move(seg.p2,pVX[k],pVY[k],T[i]-pT[k]));
          }
          First = false;
        
          double hit_time = crossTimeSS(bullet,VX[i],VY[i],
                                        seg,pVX[k],pVY[k]);
          if( !equals(hit_time,-1) ) {
            if( LTE(pT[k],cur+hit_time) && LTE(cur+hit_time,pT[k+1]) ) {
              hit.push_back(Point(cur+hit_time,0));
              break;
            }
          }
          assert( !equals(cur,-1) );
          bullet = Segment(move(bullet.p1,VX[i],VY[i],pT[k+1]-cur),
                           move(bullet.p2,VX[i],VY[i],pT[k+1]-cur));
          cur = pT[k+1];
        }
        vline = Segment(move(vline.p1,pVX[k],pVY[k],pT[k+1]-pT[k]),
                        move(vline.p2,pVX[k],pVY[k],pT[k+1]-pT[k]));
      }
    }
    if( !hit.empty() ) {
      sort(hit.begin(),hit.end());
      hit.erase(unique(hit.begin(),hit.end()),hit.end());
      answer.push_back(hit[0].x);
    }
  }
  sort(answer.begin(),answer.end());
  printf("%d\n",(int)answer.size());
  rep(i,(int)answer.size()) printf("%.10f\n",answer[i]);
}

int main(){
  while( cin >> N >> M >> B, N|M|B ){
    poly.clear();
    poly.resize(N);
    rep(i,N) cin >> poly[i].x >> poly[i].y;
    pT.clear(), pVX.clear(), pVY.clear();
    
    pT.push_back(0);
    rep(i,M) {
      double a,b,c;
      cin >> a >> b >> c;
      pT.push_back(a), pVX.push_back(b), pVY.push_back(c);
    }
    pT.push_back(10000000), pVX.push_back(0), pVY.push_back(0);

    T.clear(), X.clear(), VX.clear(), VY.clear(), L.clear();
    T.resize(B), X.resize(B), VX.resize(B), VY.resize(B), L.resize(B);
    rep(i,B) cin >> T[i] >> X[i] >> VX[i] >> VY[i] >> L[i];
    compute();
  }
  return 0;
}