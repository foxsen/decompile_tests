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

struct Line{
	Point p[2];
	Line(Point p1,Point p2){
		p[0] = p1;
		p[1] = p2;
	}
	Line(){

	}
};

int H,W;
double num_A,num_B,num_X;
double m_A1,m_A2,m_B1,m_B2,m_X;
char table[55][55];


double norm(Vector a){
	return a.x*a.x+a.y*a.y;
}

double abs(Vector a){
	return sqrt(norm(a));
}

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

//交点を求める関数
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

//インタフェース関数
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

double calc_slope(Line A){

	if(fabs(A.p[0].x-A.p[1].x) < EPS){

		return DBL_MAX;

	}else if(fabs(A.p[0].y-A.p[1].y) < EPS){

		return 0;

	}else{

		return (A.p[0].y-A.p[1].y)/(A.p[0].x-A.p[1].x);
	}
}

//★★直線の交差判定★★
bool is_Cross(Line A,Line B){

	return fabs(calc_slope(A)-calc_slope(B)) > EPS;
}

int main(){

	scanf("%d %d",&H,&W);

	scanf("%lf %lf %lf %lf %lf",&m_A1,&m_A2,&m_B1,&m_B2,&m_X);

	num_A = num_B = num_X = 0.0;
	Vector vec_A = Vector(0,0),vec_B = Vector(0,0),vec_X = Vector(0,0);

	double d_H,d_row,d_col;

	for(int row = 0; row < H; row++){

		scanf("%s",table[row]);
		for(int col = 0; col < W; col++){
			if(table[row][col] == '.')continue;

			d_H = H;
			d_row = row;
			d_col = col;

			switch(table[row][col]){
			case 'A':
				num_A += 1.0;

				vec_A.x += d_col+0.5;
				vec_A.y += d_H-d_row-0.5;

				break;
			case 'B':
				num_B += 1.0;

				vec_B.x += d_col+0.5;
				vec_B.y += d_H-d_row-0.5;

				break;
			case 'X':
				num_X += 1.0;

				vec_X.x += d_col+0.5;
				vec_X.y += d_H-d_row-0.5;

				break;
			}
		}
	}

	double ans = 0;
	bool FLG;

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++){
			if(table[row][col] == '.')continue;

			FLG = true;

			double x = col;
			double y = H-1-row;

			Polygon polygon;
			polygon.push_back(Point(m_A2,m_B2));
			polygon.push_back(Point(m_A2,m_B1));
			polygon.push_back(Point(m_A1,m_B1));
			polygon.push_back(Point(m_A1,m_B2));

			//x < 重心.x
			if(fabs(num_A*x-vec_A.x) < EPS && fabs(num_B*x-vec_B.x) < EPS){

				if((num_X*x-vec_X.x)*m_X >= 0){

					FLG = false;
				}

			}else{

				if(fabs(num_B*x-vec_B.x) > EPS){

					double a = (vec_A.x-num_A*x)/(num_B*x-vec_B.x);
					double b = ((vec_X.x-num_X*x)*m_X)/(num_B*x-vec_B.x);

					Point p2 = Point(0,b);
					Point p1 = Point(1,a+b);

					if(num_B*x-vec_B.x < 0){

						swap(p1,p2);
					}

					polygon = ConvexCut(polygon,p1,p2);

				}else{

					double a = ((num_X*x-vec_X.x)*m_X)/(vec_A.x-num_A*x);

					Point p2 = Point(a,0);
					Point p1 = Point(a,1);

					if(vec_A.x-num_A*x > 0){

						swap(p1,p2);
					}

					polygon = ConvexCut(polygon,p1,p2);
				}
			}


			if(!FLG)continue;

			//重心.x < x+1
			if(fabs(num_A*(x+1)-vec_A.x) < EPS && fabs(num_B*(x+1)-vec_B.x) < EPS){

				if((num_X*(x+1)-vec_X.x)*m_X <= 0){

					FLG = false;
				}

			}else{

				if(fabs(num_B*(x+1)-vec_B.x) > EPS){

					double a = (vec_A.x-num_A*(x+1))/(num_B*(x+1)-vec_B.x);
					double b = ((vec_X.x-num_X*(x+1))*m_X)/(num_B*(x+1)-vec_B.x);

					Point p2 = Point(0,b);
					Point p1 = Point(1,a+b);

					if(num_B*(x+1)-vec_B.x > 0){

						swap(p1,p2);
					}

					polygon = ConvexCut(polygon,p1,p2);

				}else{

					double a = ((num_X*(x+1)-vec_X.x)*m_X)/(vec_A.x-num_A*(x+1));

					Point p2 = Point(a,0);
					Point p1 = Point(a,1);

					if(vec_A.x-num_A*(x+1) < 0){

						swap(p1,p2);
					}

					polygon = ConvexCut(polygon,p1,p2);
				}
			}


			if(!FLG)continue;

			//y < 重心.y
			if(fabs(num_A*y-vec_A.y) < EPS && fabs(num_B*y-vec_B.y) < EPS){

				if((num_X*y-vec_X.y)*m_X >= 0){

					FLG = false;
				}

			}else{

				if(fabs(num_B*y-vec_B.y) > EPS){

					double a = (vec_A.y-num_A*y)/(num_B*y-vec_B.y);
					double b = ((vec_X.y-num_X*y)*m_X)/(num_B*y-vec_B.y);

					Point p2 = Point(0,b);
					Point p1 = Point(1,a+b);

					if(num_B*y-vec_B.y < 0){

						swap(p1,p2);
					}

					polygon = ConvexCut(polygon,p1,p2);

				}else{

					double a = ((num_X*y-vec_X.y)*m_X)/(vec_A.y-num_A*y);

					Point p2 = Point(a,0);
					Point p1 = Point(a,1);

					if(vec_A.y-num_A*y > 0){

						swap(p1,p2);
					}

					polygon = ConvexCut(polygon,p1,p2);
				}
			}

			if(!FLG)continue;

			//重心.y < y+1
			if(fabs(num_A*(y+1)-vec_A.y) < EPS && fabs(num_B*(y+1)-vec_B.y) < EPS){

				if((num_X*(y+1)-vec_X.y)*m_X <= 0){

					FLG = false;
				}

			}else{

				if(fabs(num_B*(y+1)-vec_B.y) > EPS){

					double a = (vec_A.y-num_A*(y+1))/(num_B*(y+1)-vec_B.y);
					double b = ((vec_X.y-num_X*(y+1))*m_X)/(num_B*(y+1)-vec_B.y);

					Point p2 = Point(0,b);
					Point p1 = Point(1,a+b);

					if(num_B*(y+1)-vec_B.y > 0){

						swap(p1,p2);
					}

					polygon = ConvexCut(polygon,p1,p2);

				}else{

					double a = ((num_X*(y+1)-vec_X.y)*m_X)/(vec_A.y-num_A*(y+1));

					Point p2 = Point(a,0);
					Point p1 = Point(a,1);

					if(vec_A.y-num_A*(y+1) < 0){

						swap(p1,p2);
					}

					polygon = ConvexCut(polygon,p1,p2);
				}
			}

			if(!FLG)continue;

			ans += calc_S(polygon)/((m_A2-m_A1)*(m_B2-m_B1));

		}
	}

	printf("%.10lf\n",fabs(ans));

	return 0;
}

