#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




#define SIZE 105

struct Point{
	Point(double arg_x,double arg_y){
		x = arg_x;
		y = arg_y;
	}

	Point(){
		x = y = 0.0;
	}

	Point operator + (Point p){ return Point(x+p.x,y+p.y); }
	Point operator - (Point p){ return Point(x-p.x,y-p.y);}
	Point operator * (double a){ return Point(a*x,a*y); }
	Point operator / (double a){ return Point(x/a,y/a); }

	double abs(){ return sqrt(norm()); }
	double norm(){ return x*x + y*y; }

	bool operator<(const Point &p) const{
		return x != p.x? x < p.x: y < p.y;
	}

	bool operator == (const Point &p) const{
		return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
	}

	double x,y;
};

typedef Point Vector;
typedef vector<Point> Polygon;

int N,M;
Point C[SIZE];


double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

double dot(Vector a,Vector b){
    return a.x*b.x + a.y*b.y;
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -1;
static const int ON_SEGMENT = 0;

int ccw(Point p0,Point p1,Point p2){

	Vector a = p1 - p0;
	Vector b = p2 - p0;

	if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;
	if(cross(a,b) < -EPS)return CLOCKWISE;
	if(dot(a,b) < -EPS)return ONLINE_BACK;
	if(a.norm() < b.norm())return ONLINE_FRONT;

	return ON_SEGMENT;
}

Point calc_Cross_Point(double x1,double x2,double x3,double x4,double y1,double y2,double y3,double y4){
	Point ret;
	ret.x = ((x2-x1)*(y3*(x4-x3)+x3*(y3-y4))-(x4-x3)*(y1*(x2-x1)+x1*(y1-y2)))/((y2-y1)*(x4-x3)-(y4-y3)*(x2-x1));
	if(x1 != x2){
		ret.y = ((y2-y1)*ret.x+y1*(x2-x1)+x1*(y1-y2))/(x2-x1);
	}else{
		ret.y = ((y4-y3)*ret.x+y3*(x4-x3)+x3*(y3-y4))/(x4-x3);
	}
	return ret;
}

Point calc_Cross_Point(Point a,Point b,Point c,Point d){
	return calc_Cross_Point(a.x,b.x,c.x,d.x,a.y,b.y,c.y,d.y);
}

Polygon ConvexCut(Polygon g,Point a,Point b){

	Polygon ret;
	int N = g.size();

	for(int i = 0; i < g.size(); i++){
		Point A = g[i], B = g[(i+1)%N];
		if(ccw(a,b,A) != -1)ret.push_back(A);
		if(ccw(a,b,A)*ccw(a,b,B) == -1)ret.push_back(calc_Cross_Point(a,b,A,B));
	}

	return ret;
}

double calc_S(Polygon g){

	int N = g.size();
	double ret = 0;

	for(int i = 0; i < g.size(); i++){
		ret += cross(g[i],g[(i+1)%N]);
	}
	return ret/2.0;
}

Point roll(Point a,double angle){

	return Point(a.x*cos(angle)-a.y*sin(angle),a.x*sin(angle)+a.y*cos(angle));
}

double norm(Vector a){
	return a.x*a.x+a.y*a.y;
}

double abs(Vector a){
	return sqrt(norm(a));
}


double calc(Point base,Point a,Point b){

	a = a-base;
	b = b-base;

	Vector vec = b-a;

	double angle;

	if(fabs(vec.x) < EPS){

		angle = 0;
	}else{

		angle = (M_PI/2)-atan(vec.y/vec.x);
	}

	a = roll(a,angle);
	b = roll(b,angle);

	double x = fabs(a.x);
	double A = max(a.y,b.y);
	double B = min(a.y,b.y);

	return (A*x*x*x)/4+(A*A*A*x)/12-((B*x*x*x)/4+(B*B*B*x)/12);
}

int main(){

	scanf("%d %d",&M,&N);

	Polygon L;

	double tmp_x,tmp_y;

	for(int i = 0; i < M; i++){
		scanf("%lf %lf",&tmp_x,&tmp_y);
		L.push_back(Point(tmp_x,tmp_y));
	}

	for(int i = 0; i < N; i++){
		scanf("%lf %lf",&C[i].x,&C[i].y);
	}

	double ans = 0;

	for(int i = 0; i < N; i++){
		Polygon p = L;
		for(int k = 0; k < N; k++){
			if(k == i)continue;

			Point from = (C[i]+C[k])/2; //中点
			Vector v1 = C[k]-C[i];
			Vector v2 = Vector(-v1.y,v1.x); //v1の法線ベクトル
			Point to = from+v2;
			p = ConvexCut(p,from,to);
		}

		for(int k = 0; k < p.size(); k++){

			ans += calc(C[i],p[k],p[(k+1)%p.size()]);
		}
	}

	printf("%.10lf\n",ans/calc_S(L));

	return 0;
}

