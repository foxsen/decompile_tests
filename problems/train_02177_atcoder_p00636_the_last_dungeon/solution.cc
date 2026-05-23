#include <bits/stdc++.h>
using namespace std;

#define dump(...) cout<<"# "<<#__VA_ARGS__<<'='<<(__VA_ARGS__)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}

template<typename Tuple>
void print_tuple(ostream&,const Tuple&){}
template<typename Car,typename... Cdr,typename Tuple>
void print_tuple(ostream& os,const Tuple& t){
	print_tuple<Cdr...>(os,t);
	os<<(sizeof...(Cdr)?",":"")<<get<sizeof...(Cdr)>(t);
}
template<typename... Args>
ostream& operator<<(ostream& os,const tuple<Args...>& t){
	print_tuple<Args...>(os<<'(',t);
	return os<<')';
}

template<typename Ch,typename Tr,typename C,typename=decltype(begin(C()))>
basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>& os,const C& c){
	os<<'[';
	for(auto i=begin(c);i!=end(c);++i)
		os<<(i==begin(c)?"":" ")<<*i;
	return os<<']';
}

constexpr int INF=1e9;
constexpr int MOD=1e9+7;
constexpr double EPS=1e-9;
constexpr double PI=3.141592653589793;

struct Point{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
	Point& operator+=(Point p){x+=p.x,y+=p.y; return *this;}
	Point& operator-=(Point p){x-=p.x,y-=p.y; return *this;}
	Point& operator*=(double c){x*=c,y*=c; return *this;}
	Point& operator/=(double c){x/=c,y/=c; return *this;}
};
Point operator+(Point a,Point b){return a+=b;}
Point operator-(Point a,Point b){return a-=b;}
Point operator*(Point a,double c){return a*=c;}
Point operator*(double c,Point a){return a*=c;}
Point operator/(Point a,double c){return a/=c;}
bool operator==(Point a,Point b){return abs(a.x-b.x)<EPS && abs(a.y-b.y)<EPS;}
bool operator!=(Point a,Point b){return !(a==b);}
bool operator<(const Point& a,const Point& b){
	return abs(a.x-b.x)>EPS?a.x<b.x:abs(a.y-b.y)>EPS?a.y<b.y:false;
}


struct Line{
	Point pos,dir;
	Line(){}
	Line(Point p,Point d):pos(p),dir(d){}
	Line(double x,double y,double u,double v):pos(x,y),dir(u,v){}
};
struct Segment{
	Point pos,dir;
	Segment(){}
	Segment(Point p,Point d):pos(p),dir(d){}
	Segment(double x,double y,double u,double v):pos(x,y),dir(u,v){}
	explicit Segment(Line l):pos(l.pos),dir(l.dir){}
	explicit operator Line()const{return Line(pos,dir);}
};

ostream& operator<<(ostream& os,const Point& p){
	return os<<'('<<p.x<<','<<p.y<<')';
}
ostream& operator<<(ostream& os,const Line& l){
	return os<<'('<<l.pos<<','<<l.dir<<')';
}
ostream& operator<<(ostream& os,const Segment& s){
	return os<<'('<<s.pos<<','<<s.dir<<')';
}

int Signum(double x){
	return x<-EPS?-1:x>EPS?1:0;
}
double Abs(Point p){
	return sqrt(p.x*p.x+p.y*p.y);
}
double Abs2(Point p){
	return p.x*p.x+p.y*p.y;
}
double Dot(Point a,Point b){
	return a.x*b.x+a.y*b.y;
}
double Cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}
Point Rot(Point p,double t){
	return Point(cos(t)*p.x-sin(t)*p.y,sin(t)*p.x+cos(t)*p.y);
}

int CCW(Point a,Point b,Point c){
	b-=a,c-=a;
	if(int sign=Signum(Cross(b,c)))
		return sign; // 1:ccw,-1:cw
	if(Dot(b,c)<-EPS)
		return -2;   // c-a-b
	if(Abs2(b)<Abs2(c)-EPS)
		return 2;    // a-b-c
	return 0;        // a-c-b (inclusive)
}

bool IntersectSP(Segment s,Point p){
	return CCW(s.pos,s.pos+s.dir,p)==0;
}
bool IntersectSS(Segment a,Segment b){
	int c1=CCW(a.pos,a.pos+a.dir,b.pos),c2=CCW(a.pos,a.pos+a.dir,b.pos+b.dir);
	int c3=CCW(b.pos,b.pos+b.dir,a.pos),c4=CCW(b.pos,b.pos+b.dir,a.pos+a.dir);
	return c1*c2<=0 && c3*c4<=0;
}
Point InterPointLL(Line a,Line b){
	if(abs(Cross(a.dir,b.dir))<EPS) return a.pos;
	return a.pos+Cross(b.pos-a.pos,b.dir)/Cross(a.dir,b.dir)*a.dir;
}
Point InterPointLS(Line l,Segment s){
	return InterPointLL(Line(s),l);
}
Point InterPointSS(Segment a,Segment b){
	if(abs(Cross(a.dir,b.dir))<EPS){
		if(IntersectSP(b,a.pos)) return a.pos;
		if(IntersectSP(b,a.pos+a.dir)) return a.pos+a.dir;
		if(IntersectSP(a,b.pos)) return b.pos;
		if(IntersectSP(a,b.pos+b.dir)) return b.pos+b.dir;
	}
	return InterPointLL(Line(a),Line(b));
}

vector<Point> ConvexCut(const vector<Point>& ps,Line l){
	int n=ps.size();
	vector<Point> res;
	rep(i,n){
		int c1=CCW(l.pos,l.pos+l.dir,ps[i]);
		int c2=CCW(l.pos,l.pos+l.dir,ps[(i+1)%n]);
		if(c1!=-1)
			res.push_back(ps[i]);
		if(c1*c2==-1)
			res.push_back(InterPointLS(l,Segment(ps[i],ps[(i+1)%n]-ps[i])));
	}
	return res;
}

struct Edge{
	int src,dst;
	double weight;
	Edge(){}
	Edge(int s,int d,double w):src(s),dst(d),weight(w){}
	bool operator<(const Edge& e)const{return Signum(weight-e.weight)<0;}
	bool operator>(const Edge& e)const{return Signum(weight-e.weight)>0;}
};
typedef vector<vector<Edge>> Graph;

void SegmentArrangement(const vector<Segment>& ss,Graph& g,vector<Point>& ps){
	rep(i,ss.size()){
		ps.push_back(ss[i].pos);
		ps.push_back(ss[i].pos+ss[i].dir);
		repi(j,i+1,ss.size()) if(IntersectSS(ss[i],ss[j]))
			ps.push_back(InterPointSS(ss[i],ss[j]));
	}
	sort(all(ps));
		
	ps.erase(unique(all(ps)),ps.end());
	
	g.resize(ps.size());
	rep(i,ss.size()){
		vector<pair<double,int> > ds;
		rep(j,ps.size()) if(IntersectSP(ss[i],ps[j]))
			ds.push_back(mp(Abs(ps[j]-ss[i].pos),j));
		sort(all(ds));
		rep(j,ds.size()-1){
			int u=ds[j].second,v=ds[j+1].second;
			double w=ds[j+1].first-ds[j].first;
			g[u].push_back(Edge(u,v,w));
			g[v].push_back(Edge(v,u,w));
		}
	}
}

void Dijkstra(const Graph& g,int v,vd& dist)
{
	priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
	pq.emplace(-1,v,0);
	while(pq.size()){
		Edge cur=pq.top(); pq.pop();
		if(dist[cur.dst]!=INF) continue;
		dist[cur.dst]=cur.weight;
		for(Edge e:g[cur.dst])
			pq.emplace(e.src,e.dst,cur.weight+e.weight);
	}
}

int main()
{
	for(int n;cin>>n && n;){
		vector<Point> ps(n);
		for(auto& p:ps) cin>>p.x>>p.y;
		
		vector<Segment> ss;
		{
			set<pair<Point,Point>> tmp;
			rep(i,n){
				vector<Point> cs={Point(0,0),Point(4,0),Point(4,4),Point(0,4)};
				rep(j,n) if(j!=i){
					Line l((ps[j]+ps[i])/2,Rot(ps[j]-ps[i],PI/2));
					cs=ConvexCut(cs,l);
				}
				rep(i,cs.size()){
					Point p1=cs[i],p2=cs[(i+1)%cs.size()];
					if((abs(p1.y)<EPS || abs(p1.y-4)<EPS) && abs(p2.y-p1.y)<EPS)
						continue;
					tmp.insert(mp(min(p1,p2),max(p1,p2)));
				}
			}
			for(auto p:tmp) ss.emplace_back(p.first,p.second-p.first);
		}
		
		Graph g;
		vector<Point> qs;
		SegmentArrangement(ss,g,qs);
		
		vd dist(qs.size(),INF);
		priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
		rep(i,qs.size()) if(abs(qs[i].x)<EPS) pq.emplace(-1,i,0);
		while(pq.size()){
			Edge cur=pq.top(); pq.pop();
			if(dist[cur.dst]!=INF) continue;
			dist[cur.dst]=cur.weight;
			for(Edge e:g[cur.dst])
				pq.emplace(e.src,e.dst,cur.weight+e.weight);
		}
		
		double res=INF;
		rep(i,qs.size()) if(abs(qs[i].x-4)<EPS) res=min(res,dist[i]);
		if(res==INF) puts("impossible");
		else         printf("%.12f\n",res);
	}
}