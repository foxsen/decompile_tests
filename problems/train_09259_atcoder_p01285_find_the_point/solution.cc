#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
//#define EPS 0.000000001
using namespace std;


#define EPS 0.000001

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

struct Line{
	Point p[2];
	Line(Point p1,Point p2){
		p[0] = p1;
		p[1] = p2;
	}
	Line(){

	}
};

typedef Point Vector;

int N;
Point point[3];
vector<Line> LINE;
double slope[3];



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

Point calc_Cross_Point(Line A,Line B){

	return calc_Cross_Point(A.p[0],A.p[1],B.p[0],B.p[1]);
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

double calc_dist1(Line line,Point point){
    return abs(cross(line.p[1]-line.p[0],point-line.p[0]))/abs(line.p[1]-line.p[0]);
}

vector<Line> calc_Equal_Line(Line A,Line B){

	vector<Line> ret;

	if(is_Cross(A,B)){

		Point cross_point = calc_Cross_Point(A,B);

		Vector dir_A = A.p[1]-A.p[0];
		Vector dir_B = B.p[1]-B.p[0];

		dir_A = dir_A/abs(dir_A);
		dir_B = dir_B/abs(dir_B);

		ret.push_back(Line(cross_point,cross_point+dir_A+dir_B));
		ret.push_back(Line(cross_point,cross_point+dir_A-dir_B));

	}else{

		ret.push_back(Line((A.p[0]+B.p[0])/2,(A.p[0]+B.p[0])/2+(A.p[1]-A.p[0])));
	}

	return ret;
}


void func(){

	LINE.clear();

	for(int i = 0; i < N; i++){

		Point A,B;

		scanf("%lf %lf %lf %lf",&A.x,&A.y,&B.x,&B.y);

		if(A.x > B.x){

			swap(A,B);
		}
		LINE.push_back(Line(A,B));
	}

	if(N <= 2){

		printf("Many\n");
		return;
	}

	vector<Line> LINE_01 = calc_Equal_Line(LINE[0],LINE[1]);
	vector<Line> LINE_02 = calc_Equal_Line(LINE[0],LINE[2]);

	vector<Point> CANDIDATE,ANS;

	for(int i = 0; i < LINE_01.size(); i++){
		for(int k = 0; k < LINE_02.size(); k++){

			if(!is_Cross(LINE_01[i],LINE_02[k]))continue;

			CANDIDATE.push_back(calc_Cross_Point(LINE_01[i],LINE_02[k]));
		}
	}

	sort(CANDIDATE.begin(),CANDIDATE.end());
	CANDIDATE.erase(unique(CANDIDATE.begin(),CANDIDATE.end()),CANDIDATE.end());

	int count = 0;

	for(int i = 0; i < CANDIDATE.size(); i++){

		double base_dist =  calc_dist1(LINE[0],CANDIDATE[i]);

		bool FLG = true;

		for(int k = 1; k < N; k++){

			if(fabs(base_dist-calc_dist1(LINE[k],CANDIDATE[i])) > EPS){

				FLG = false;
				break;
			}

		}

		if(FLG){
			count++;
			ANS.push_back(CANDIDATE[i]);
		}
	}

	if(count == 0){

		printf("None\n");
	}else if(count >= 2){

		printf("Many\n");

	}else{

		printf("%.10lf %.10lf\n",ANS[0].x,ANS[0].y);
	}
}

int main(){

	while(true){

		scanf("%d",&N);
		if(N == 0)break;

		func();
	}

	return 0;
}

