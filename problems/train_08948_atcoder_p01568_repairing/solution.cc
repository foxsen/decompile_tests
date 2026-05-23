#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-12)
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

  bool operator == (const Point& p)const{  return equals(x,p.x) && equals(y,p.y); }

};

struct Segment{
  Point p1,p2;
  Segment(Point p1 = Point(),Point p2 = Point()):p1(p1),p2(p2){}
  bool operator <  (const Segment& s) const { return ( p2 == s.p2 ) ? p1 < s.p1 : p2 < s.p2; }
  bool operator == (const Segment& s) const { return ( s.p1 == p1 && s.p2 == p2 ) || ( s.p1 == p2 && s.p2 == p1 ); }

};

typedef Point Vector;
typedef Segment Line;

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

bool intersectSP(Line s, Point p) { return abs(s.p1-p)+abs(s.p2-p)-abs(s.p2-s.p1) < EPS; }

Point projection(Line l,Point p) {
  double t = dot(p-l.p1, l.p1-l.p2) / norm(l.p1-l.p2);
  return l.p1 + (l.p1-l.p2)*t;
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
    return vec[1];
  }
  if(abs(A) < EPS)assert(false);
  return m.p1 + (m.p2-m.p1)*(B/A);
}

struct Edge {
  int from,to;
  double cost;
  Edge(int from=0,int to=0,double cost=0):from(from),to(to),cost(cost){}
  bool operator < (const Edge& a)const { return !equals(cost,a.cost) && cost < a.cost; }
};

vector<vector<Edge> > segmentArrangement(vector<Segment> vs,vector<Point> &ps) {
  rep(i,vs.size()) REP(j,i+1,vs.size()) if(intersectSS(vs[i],vs[j])) ps.push_back(Point(crosspoint(vs[i],vs[j])));

  sort(ps.begin(),ps.end());  
  ps.erase(unique(ps.begin(),ps.end()),ps.end());

  vector<vector<Edge> > ret(ps.size());

  for(int i=0;i<vs.size();i++){
    vector<pair<double,int> > list;
    rep(j,ps.size()) if(intersectSP(vs[i],ps[j]))list.push_back(pair<double,int>(norm(vs[i].p1-ps[j]),j));
    sort(list.begin(),list.end());
    for(int j=0;j+1<list.size();++j) {
      int from = list[j].second, to = list[j+1].second;
      double cost = abs(ps[from]-ps[to]);
      ret[from].push_back(Edge(from,to,cost));
      ret[to].push_back(Edge(to,from,cost));
    }
  }  
  return ret;
}

int N,M;
vector<Segment> segs;
vector<Point> stop;
Point source,repairing;

void compute(){
  double total = 0;
  vector<Point> ps = stop;
  ps.push_back(source);
  ps.push_back(repairing);
  rep(i,(int)segs.size()) ps.push_back(segs[i].p1), ps.push_back(segs[i].p2),
    total += abs(segs[i].p1-segs[i].p2);
  vector<vector<Edge> > G = segmentArrangement(segs,ps);

  int sp = -1, rp = -1;
  rep(i,ps.size()) {
    if( source == ps[i] ) sp = i;
    if( repairing == ps[i] ) rp = i;
  }
  
  sort(stop.begin(),stop.end());
  vector<bool> stopper(ps.size(),false);
  rep(i,stop.size()) {
    int position = lower_bound(ps.begin(),ps.end(),stop[i]) - ps.begin();
    assert( position < ps.size() );
    stopper[position] = true;
  }

  deque<int> deq;
  vector<bool> out(ps.size(),false);
  deq.push_back(rp);
  out[rp] = true;
  while( !deq.empty() ){
    int cur = deq.front(); deq.pop_front();
    rep(i,(int)G[cur].size()) {
      int to = G[cur][i].to;
      if( out[to] ) continue;
      out[to] = true;
      if( stopper[to] ) continue;
      deq.push_back(to);
    }
  }

  if( out[sp] ) { puts("-1"); return; }
  
  double reach = 0;

  typedef pair<int,int> ii;
  set<ii> added,used;
  assert( deq.empty() );
  deq.push_back(sp);
  while( !deq.empty() ){
    int cur = deq.front(); deq.pop_front();
    rep(i,(int)G[cur].size()){
      int to = G[cur][i].to;
      ii data = ii(min(cur,to),max(cur,to));
      if( !added.count(data) ) {
        added.insert(data);
        reach += abs(ps[cur]-ps[to]);
      }   
      if( out[to] ) continue;
      if( used.count( ii(cur,to) ) ) continue;
      used.insert(ii(cur,to));
      deq.push_back(to);
    }
  }
  printf("%.10f\n",total-reach);
}

int main(){
  scanf("%d %d",&N,&M);
  segs.clear(), stop.clear();
  segs.resize(N), stop.resize(M);
  rep(i,N) cin >> segs[i].p1.x >> segs[i].p1.y >> segs[i].p2.x >> segs[i].p2.y;
  rep(i,M) cin >> stop[i].x >> stop[i].y;
  cin >> source.x >> source.y;
  cin >> repairing.x >> repairing.y;
  compute();
  return 0;
}