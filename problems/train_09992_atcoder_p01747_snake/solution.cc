#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


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

double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

bool calcGaiseki(Point left,Point base, Point right){
	double gaiseki = (left.x-base.x)*(right.y - base.y)-(left.y-base.y)*(right.x-base.x);
	if(gaiseki < -0.00000001)return false;
	else{
		return true;
	}
}

double calc_S(Polygon g){

	int N = g.size();
	double ret = 0;

	for(int i = 0; i < g.size(); i++){
		ret += cross(g[i],g[(i+1)%N]);
	}
	return ret/2.0;
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

//http://www.prefield.com/algorithm/geometry/convex_hull.html
Polygon ConvexHull(Polygon V)
{
  int N = V.size(), k = 0;

  sort(V.begin(), V.end());

  Polygon ret(2*N);
  for (int i = 0; i < N; ret[k++] = V[i++]) // lower-hull
  while (k >= 2 && ccw(ret[k-2], ret[k-1], V[i]) <= 0) --k;
  for (int i = N-2, t = k+1; i >= 0; ret[k++] = V[i--]) // upper-hull
    while (k >= t && ccw(ret[k-2], ret[k-1], V[i]) <= 0) --k;

  ret.resize(k-1);

  return ret;
}

bool is_ok(Polygon p){

	double pre_S = -1.0,tmp_S;

	for(int i = 0; i < p.size(); i++){
		if(i < 2)continue;

		Polygon p2;
		for(int k = 0; k <= i; k++){
			p2.push_back(p[k]);
		}

		p2 = ConvexHull(p2);

		tmp_S = calc_S(p2);

		if(fabs(tmp_S-pre_S) < EPS){
			return false;
		}
		pre_S = tmp_S;
	}
	return true;
}


int main(){

	int N;
	scanf("%d",&N);

	Polygon p;
	double tmp_x,tmp_y;

	for(int loop = 0; loop < N; loop++){
		scanf("%lf %lf",&tmp_x,&tmp_y);
		p.push_back(Point(tmp_x,tmp_y));
	}

	if(!is_ok(p)){
		printf("Impossible\n");
		return 0;
	}

	reverse(p.begin(),p.end());

	if(!is_ok(p)){
		printf("Impossible\n");
		return 0;
	}

	printf("Possible\n");

	return 0;
}

