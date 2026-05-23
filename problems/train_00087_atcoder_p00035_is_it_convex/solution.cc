#include<cstdio>

#define	EPS		1e-9
#define	pb(a)	push_back(a);

#define	ID_CCW	0
#define	ID_CW	1
#define	ID_GO	2
#define	ID_BACK	3

using namespace std;

class Point{
public:
	double x,y;
	Point(){}
	Point(double xx,double yy) : x(xx),y(yy){}
};

Point &operator -=(Point &a,const Point &b)
{
	a.x-=b.x;
	a.y-=b.y;
	return a;
}

double dot(const Point &a,const Point &b)
{
	return a.x*b.x+a.y*b.y;
}

double cross(const Point &a,const Point &b)
{
	return a.x*b.y-a.y*b.x;
}

int ccw(const Point &a,Point b,Point c)
{
	b-=a;
	c-=a;
	double rotdir=cross(b,c);
	if(rotdir>EPS)		return ID_CCW;
	if(rotdir<-EPS)		return ID_CW;
	if(dot(b,c)>EPS)	return ID_GO;
	return ID_BACK;
}

int main()
{
	Point p[4];
	while(1){
		if(scanf("%lf,%lf",&p[0].x,&p[0].y)==EOF)	break;
		for(int i=1;i<4;i++)	scanf(",%lf,%lf",&p[i].x,&p[i].y);
		bool b1=true;
		for(int i=0;i<4;i++)	if(ccw(p[i],p[(i+1)%4],p[(i+2)%4])!=ID_CCW)	b1=false;
		bool b2=true;
		for(int i=0;i<4;i++)	if(ccw(p[i],p[(i+1)%4],p[(i+2)%4])!=ID_CW)	b2=false;
		puts(b1||b2?"YES":"NO");
	}
	return 0;
}