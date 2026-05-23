#include<cmath>
#include<queue>
#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-7;
const double INF=1e77;

struct point{
	double x,y;
	point():x(0),y(0){}
	point(double x,double y):x(x),y(y){}
	point operator+(const point &a)const{ return point(x+a.x,y+a.y); }
	point operator-(const point &a)const{ return point(x-a.x,y-a.y); }
	bool operator< (const point &a)const{ return x+EPS<a.x || abs(x-a.x)<EPS && y+EPS<a.y; }
};

point operator*(double c,const point &a){ return point(c*a.x,c*a.y); }

double dot(const point &a,const point &b){ return a.x*b.x+a.y*b.y; }

double cross(const point &a,const point &b){ return a.x*b.y-a.y*b.x; }

double abs(const point &a){ return sqrt(a.x*a.x+a.y*a.y); }

struct line{
	point a,b;
	line(const point &a,const point &b):a(a),b(b){}
};

struct segment{
	point a,b;
	segment(const point &a,const point &b):a(a),b(b){}
};

bool cover(const segment &S,const point &p){
	return abs(cross(S.a-p,S.b-p))<EPS && dot(S.a-p,S.b-p)<EPS;
}

point get_intersect(const line &L1,const line &L2){
	double a1=cross(L1.b-L1.a,L2.b-L2.a);
	double a2=cross(L1.b-L1.a,L1.b-L2.a);
	if(abs(a1)<EPS) return L1.a;
	return L2.a+a2/a1*(L2.b-L2.a);
}

struct edge{ int v; double cost; };

int main(){
	for(int n;scanf("%d",&n),n;){
		double v1,v2; scanf("%lf%lf",&v1,&v2);
		point p[2000];
		rep(i,n) scanf("%lf%lf",&p[i].x,&p[i].y);

		vector<edge> G[2000];
		int n2=0;
		rep(i,n){
			// dig right
			if(i<n-1 && p[i].y<p[i+1].y){
				int j=i+1;
				while(j<n && p[i].y<p[j].y) j++;
				if(j<n){
					p[n+n2]=get_intersect(line(p[j-1],p[j]),line(p[i],p[i]+point(1,0)));
					G[i].push_back((edge){n+n2,abs(p[i]-p[n+n2])/v2});
					n2++;
				}
			}
			// dig left
			if(i>0 && p[i].y<p[i-1].y){
				int j=i-1;
				while(j>=0 && p[i].y<p[j].y) j--;
				if(j>=0){
					p[n+n2]=get_intersect(line(p[j+1],p[j]),line(p[i],p[i]+point(1,0)));
					G[n+n2].push_back((edge){i,abs(p[i]-p[n+n2])/v2});
					n2++;
				}
			}
		}

		rep(i,n-1){
			vector< pair<point,int> > Q;
			rep(j,n+n2){
				if(cover(segment(p[i],p[i+1]),p[j])) Q.push_back(make_pair(p[j],j));
			}
			sort(Q.begin(),Q.end());
			rep(j,(int)Q.size()-1){
				int u=Q[j].second,v=Q[j+1].second;
				G[u].push_back((edge){v,abs(Q[j+1].first-Q[j].first)/v1});
			}
		}

		double d[2000];
		rep(u,n+n2) d[u]=(u==0?0:INF);

		priority_queue< pair<double,int> > Q;
		Q.push(make_pair(0,0));
		while(!Q.empty()){
			double d_now=-Q.top().first;
			int u=Q.top().second; Q.pop();

			if(d[u]<d_now-EPS) continue;

			rep(i,G[u].size()){
				int v=G[u][i].v;
				double cost=G[u][i].cost;
				if(d[v]>d[u]+cost+EPS){
					d[v]=d[u]+cost;
					Q.push(make_pair(-d[v],v));
				}
			}
		}
		printf("%.9f\n",d[n-1]);
	}

	return 0;
}