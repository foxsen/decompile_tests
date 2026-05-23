#include<bits/stdc++.h>
#define MAX 1024
#define inf 1<<29
#define linf 1e16
#define eps (1e-6)
#define mod 1000000007
#define pi acos(-1)
#define phi (1.0+sqrt(5))/2.0
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10f\n",(double)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a)-1;(b)<=i;i--)
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef vector<int> vi;
typedef vector<pii> vpi;
const int dx[8]={1,0,-1,0,1,1,-1,-1};
const int dy[8]={0,1,0,-1,1,-1,1,-1};

class Point{
public:
  double x,y;
  Point(double x=0,double y=0):x(x),y(y){}

  Point operator+(Point p){ return Point(x+p.x,y+p.y);}
  Point operator-(Point p){ return Point(x-p.x,y-p.y);}
  Point operator*(double k){ return Point(x*k,y*k);}
  Point operator/(double k){ return Point(x/k,y/k);}
  bool operator<(Point p)const{ return equals(x,p.x) ? y-p.y<-eps : x-p.x<-eps; }
  bool operator==(Point p)const{ return fabs(x-p.x)<eps && fabs(y-p.y)<eps;}

  double abs(){ return sqrt(norm());}
  double norm(){ return (x*x+y*y);}
};
typedef Point Vector;
typedef vector<Point> Polygon;

class Segment{
public:
  Point p1,p2;
  Segment(Point p1=Point(),Point p2=Point()):p1(p1),p2(p2){}
};
typedef Segment Line;

double norm(Vector a){ return (a.x*a.x+a.y*a.y);}
double abs(Vector a){ return sqrt(norm(a));}
double dot(Vector a,Vector b){ return (a.x*b.x+a.y*b.y);}
double cross(Vector a,Vector b){ return (a.x*b.y-a.y*b.x);}

Point project(Segment s,Point p){
  Vector base=(s.p2-s.p1);
  double r=(dot(p-s.p1,base)/base.norm());
  return (s.p1+base*r);
}

bool isParallel(Vector a,Vector b){
  return equals(cross(a,b),0.0);
}

bool isParallel(Segment s,Segment t){
  return equals(cross(s.p1-s.p2,t.p1-t.p2),0.0);
}

bool intersect(Segment a,Segment b){
  if(cross(a.p2-a.p1,b.p1-a.p1)*cross(a.p2-a.p1,b.p2-a.p1)<-eps &&
     cross(b.p2-b.p1,a.p1-b.p1)*cross(b.p2-b.p1,a.p2-b.p1)<-eps)
    return true;
  return false;
}

bool intersectLS(Line L,Segment s){
  return cross(L.p2-L.p1,s.p1-L.p1)*cross(L.p2-L.p1,s.p2-L.p1)<-eps;
}

int ccw(Point p0,Point p1,Point p2){
  Vector a=p1-p0;
  Vector b=p2-p0;
  if(cross(a,b)>eps)return 1;
  if(cross(a,b)<-eps)return -1;
  if(dot(a,b)<-eps)return 2;
  if(a.norm()<b.norm())return -2;
  return 0;
}

Point getCrossPointLL(Line a,Line b){
  double A=cross(a.p2-a.p1,b.p2-b.p1);
  double B=cross(a.p2-a.p1,a.p2-b.p1);
  if(abs(A)<eps || abs(B)<eps)return b.p1;
  return b.p1+(b.p2-b.p1)*(B/A);
}

int contains(Polygon g,Point p){
  int n=g.size();
  bool x=false;
  for(int i=0;i<n;i++){
    Vector a=g[i]-p,b=g[(i+1)%n]-p;
    if(abs(cross(a,b))<eps && dot(a,b)<eps)return 1;
    if(a.y>b.y)swap(a,b);
    if(a.y<eps && eps<b.y && cross(a,b)>eps)x=!x;
  }
  if(x)return 2;
  return 0;
}

int n,m;
Point s,ori(0,0);
vector<Point> g;
vector<Polygon> buildings;
vector<Point> vp;
vector<pid> e[MAX];

void init(){
  buildings.clear();
  vp.clear();
  FOR(i,0,MAX)e[i].clear();
  g.clear();
}

void add_edge(int to,int from,double cost){
  e[to].pb(mp(from,cost));
  e[from].pb(mp(to,cost));
}

bool check(Point a){
  FOR(i,0,n)if(contains(buildings[i],a)==2)return false;
  return true;
}

bool check(Segment s){
  FOR(i,0,n){
    Polygon p=buildings[i];
    m=p.size();
    FOR(j,0,m){
      Point a=p[j],b=p[(j+1)%m],c=p[(j-1+m)%m];
      if(isParallel(Segment(a,b),s))continue;
      if(intersect(Segment(a,b),s))return false;
    }
  }
  return true;
}

double getdis(Point a,Point b){
  Line L(s,b);
  Point c=project(L,a);
  if(ccw(s,b,c)==-2 && check(a+(c-a)/2.0) &&
     check(Segment(a,c)))return abs(c-a);
  c=Point(inf,inf);
  FOR(i,0,n){
    Polygon p=buildings[i];
    m=p.size();
    FOR(j,0,m){
      Segment seg(p[j],p[(j+1)%m]);
      if(isParallel(L,seg))continue;
      if(!intersectLS(L,seg))continue;
      Point cp=getCrossPointLL(L,seg);
      if(ccw(s,b,cp)==-2 && abs(s-cp)<abs(s-c))c=cp;
    }
  }
  if(ccw(s,b,c)==-2 && check(a+(c-a)/2.0) &&
     check(Segment(a,c)))return abs(c-a);
  return inf;
}

double dijkstra(){
  double d[MAX];
  priority_queue<pdi,vector<pdi>,greater<pdi> > pq;
  fill(d,d+MAX,inf);
  d[0]=0;
  pq.push(mp(0,0));

  while(pq.size()){
    pdi u=pq.top();
    pq.pop();

    if(d[u.s]<u.f)continue;
    if(u.s==vp.size())return u.f;

    FOR(i,0,e[u.s].size()){
      int next=e[u.s][i].f;
      double cost=e[u.s][i].s+d[u.s];
      if(cost<d[next]){
        d[next]=cost;
        pq.push(mp(cost,next));
      }
    }
  }
  return inf;
}

double solve(){
  if(!check(Segment(ori,s)))return 0;
  vp.pb(ori);
  FOR(i,0,n){
    Polygon p=buildings[i];
    m=p.size();
    FOR(j,0,m){
      if(!check(Segment(s,p[j])))continue;
      vp.pb(p[j]);
      if(ccw(s,p[j],p[(j-1+m)%m])*
         ccw(s,p[j],p[(j+1)%m])==1)g.pb(p[j]);
    }
  }
  
  FOR(i,0,vp.size()){
    FOR(j,i+1,vp.size()){
      if(check(vp[i]+(vp[j]-vp[i])/2.0) && 
         check(Segment(vp[i],vp[j])))add_edge(i,j,abs(vp[i]-vp[j]));
    }
  }
  FOR(i,0,vp.size()){
    double cost=inf;
    FOR(j,0,g.size()){
      if(vp[i]==g[j]){ cost=0;break; }
      else cost=min(cost,getdis(vp[i],g[j]));
    }
    add_edge(vp.size(),i,cost);
  }
  return dijkstra();
}

int main()
{
  while(cin>>n && n){
    init();
    cin>>s.x>>s.y;
    FOR(i,0,n){
      cin>>m;
      Polygon p;
      FOR(j,0,m){
        int x,y;
        cin>>x>>y;
        p.pb(Point(x,y));
      }
      buildings.pb(p);
    }
    pd(solve());
  }
  return 0;
}