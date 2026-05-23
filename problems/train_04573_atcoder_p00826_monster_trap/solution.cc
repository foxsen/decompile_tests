#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <set>
//#define LOCAL
#define maxv 205
#define maxn 105
#define EPS 1e-10
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct Point{
	double x,y;
	Point(double x = 0.0,double y = 0.0): x(x),y(y) {}
	Point operator + (Point p){
		return Point(x + p.x,y + p.y);
	}
	Point operator - (Point p){
		return Point(x - p.x,y - p.y);
	}
	Point operator * (double lambda){
		return Point(x * lambda,y * lambda);
	}
	Point operator / (double lambda){
		return Point(x / lambda,y / lambda);
	}
	double norm(){
		return x * x + y * y;
	}
	double abs_(){
		return sqrt(norm());
	}
	double pol(){
		return atan2(y,x);
	}
	bool operator == (const Point &p)const
	{
		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
	}
	bool operator < (const Point &p)const
	{
		if(abs(x - p.x) < EPS) return y < p.y;
		else return x < p.x;
	}
};
typedef Point Vector;
struct Segment{
	Point p1,p2;
	Segment(Point p1 = Point(),Point p2 = Point()): p1(p1),p2(p2) {}
};
Point front(Segment s){
	Vector a = s.p2 - s.p1;
	a = a / a.abs_() * 5e-4;
	return s.p2 + a;
}
Point back(Segment s){
	Vector a = s.p2 - s.p1;
	a = a / a.abs_() * 5e-4;
	return s.p1 - a;
}
typedef Segment Line;
typedef vector<Point> Polygon;
double dot(Vector a,Vector b){ return a.x * b.x + a.y * b.y; }
double det(Vector a,Vector b){ return a.x * b.y - a.y * b.x; }
vector <int> adj[maxv];
Point p[maxv]; int pk;
Segment s[maxn]; int n;
int ccw(Point p,Segment l){
	if(det(l.p2 - l.p1,p - l.p1) > EPS) return 1;
	if(det(l.p2 - l.p1,p - l.p1) < -EPS) return -1;
	if(dot(l.p2 - l.p1,p - l.p1) < -EPS) return 2;
	if((l.p2 - l.p1).norm() < (p - l.p1).norm()) return -2;
	return 0;
}
bool cross(Segment s1,Segment s2){
	return ccw(s1.p1,s2) * ccw(s1.p2,s2) <= 0 && ccw(s2.p1,s1) * ccw(s2.p2,s1) <= 0;
}
bool check(Point p1,Point p2){
	for(int i=1;i<=n;i++){
		if(cross(Segment(p1,p2),s[i])) return false;
	}
	return true;
}
bool vis[maxv];
void dfs(int u){
	vis[u] = true;
	for(int i=0;i<(int)adj[u].size();i++){
		int v = adj[u][i];
		if(!vis[v]) dfs(v);
	}
}
int main(){
	#ifdef LOCAL
	freopen("sample.in","r",stdin);
	freopen("sample.out","w",stdout);
	#endif
	while(~scanf("%d",&n) && n){
		for(int i=1;i<=n;i++) scanf("%lf%lf%lf%lf",&s[i].p1.x,&s[i].p1.y,&s[i].p2.x,&s[i].p2.y);
		pk = 0;
		p[++pk] = Point(0,0);
		p[++pk] = Point(100,100);
		for(int i=1;i<=n;i++){
			p[++pk] = front(s[i]);
			p[++pk] = back(s[i]);
		}
		for(int i=1;i<=pk;i++) adj[i].clear();
		for(int i=1;i<=pk;i++){
			for(int j=i+1;j<=pk;j++){
				if(check(p[i],p[j])){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		memset(vis,0,sizeof(vis));
		dfs(1);
		if(vis[2]) puts("no");
		else puts("yes");
	}
	return 0;
}

