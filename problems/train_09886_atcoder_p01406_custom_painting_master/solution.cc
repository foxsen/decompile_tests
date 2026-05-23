#include<cstdio>
#include<vector>
#include<complex>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef complex<double> Point;

const double EPS=1e-9;
const double PI=acos(-1);

class Line:public vector<Point>{
public:
	Line(){}
	Line(const Point &a,const Point &b){ push_back(a), push_back(b); }
};

class Segment:public Line{
public:
	Segment(const Point &a,const Point &b):Line(a,b){}
};

class Circle{
public:
	Point c;
	double r;
	Circle(){}
	Circle(const Point &C,double R):c(C),r(R){}
};

class Sector:public Circle{
public:
	double t1,t2;
};

inline double dot(const Point &a,const Point &b){
	return a.real()*b.real()+a.imag()*b.imag();
}

inline double cross(const Point &a,const Point &b){
	return a.real()*b.imag()-a.imag()*b.real();
}

inline void calc_abc(const Line &l,double &a,double &b,double &c){
	a=l[0].imag()-l[1].imag();
	b=l[1].real()-l[0].real();
	c=cross(l[0],l[1]);
}

Point PerpFoot(const Point &p,const Line &l){
	double a,b,c;
	calc_abc(l,a,b,c);
	Point v(a,b);
	return p-(dot(p,v)+c)*v/norm(v);
}

bool cover(const Segment &s,const Point &p){
	return dot(s[0]-p,s[1]-p)<EPS;
}

bool intersect(const Line &l,const Line &m,Point &p){
	if(abs(cross(l[1]-l[0],m[1]-m[0]))>EPS
	|| abs(cross(l[1]-l[0],m[0]-l[0]))<EPS){
		double a1,b1,c1,a2,b2,c2;
		calc_abc(l,a1,b1,c1);
		calc_abc(m,a2,b2,c2);
		double det=a1*b2-a2*b1;
		if(abs(det)<EPS) p=l[0]; // l==m
		else             p=Point(b1*c2-b2*c1,a2*c1-a1*c2)/det;
		return true;
	}
	return false;
}

int intersect(const Circle &c,const Line &l,Point &p,Point &q){
	Point m=PerpFoot(c.c,l);
	double d=abs(c.c-m);
	if(c.r+EPS<d) return 0;
	else if(abs(c.r-d)<EPS){
		p=q=m;
		return 1;
	}
	else{
		Point v;
		double n0=norm(l[0]-m),n1=norm(l[1]-m);
		if(n0<n1) v=l[1]-m, n0=n1;
		else      v=l[0]-m;
		v*=sqrt((c.r*c.r-d*d)/n0);
		p=m+v, q=m-v;
		return 2;
	}
}

int intersect(const Circle &c,const Segment &s,Point &p,Point &q){
	Point pp,qq;
	int n=intersect(c,Line(s),pp,qq);
	if(n==0) return 0;
	else if(n==1){
		if(cover(s,pp)){
			p=q=pp;
			return 1;
		}
		return 0;
	}
	else{
		bool bp=cover(s,pp),bq=cover(s,qq);
		if(bp&&bq){
			p=pp, q=qq;
			return 2;
		}
		if(bp||bq){
			p=q=(bp?pp:qq);
			return 1;
		}
		return 0;
	}
}

int intersect(const Circle &c1,const Circle &c2,Point &p,Point &q){
	double d=abs(c1.c-c2.c);
	if(d<EPS && abs(c1.r-c2.r)<EPS) return -1; // c1==c2
	if(c1.r+c2.r<d-EPS || d+EPS<abs(c1.r-c2.r)) return 0;

	if(abs(c1.r+c2.r-d)<EPS){
		intersect(c1,Segment(c1.c,c2.c),p,q);
		return 1;
	}

	double a=(c1.r*c1.r-c2.r*c2.r+d*d)/(2*d);
	double h=sqrt(c1.r*c1.r-a*a);
	p=q=c1.c+a/d*(c2.c-c1.c);
	Point tmp=h*(c2.c-c1.c)/d;
	p+=tmp*Point(0,-1);
	q+=tmp*Point(0,+1);
	return 2;
}

void intersect(const Sector &S1,const Sector &S2,vector<Point> &P){
	Point Q,R;
	Line L1(S1.c,S1.c+polar(1.0,S1.t1));
	Line M1(S1.c,S1.c+polar(1.0,S1.t2));
	Line L2(S2.c,S2.c+polar(1.0,S2.t1));
	Line M2(S2.c,S2.c+polar(1.0,S2.t2));
	Circle C1(S1),C2(S2);

	if(intersect(C1,C2,Q,R)>0) P.push_back(Q), P.push_back(R);
	if(intersect(C1,L2,Q,R)>0) P.push_back(Q), P.push_back(R);
	if(intersect(C1,M2,Q,R)>0) P.push_back(Q), P.push_back(R);
	if(intersect(C2,L1,Q,R)>0) P.push_back(Q), P.push_back(R);
	if(intersect(C2,M1,Q,R)>0) P.push_back(Q), P.push_back(R);
	if(intersect(L1,L2,Q)>0)   P.push_back(Q);
	if(intersect(L1,M2,Q)>0)   P.push_back(Q);
	if(intersect(M1,L2,Q)>0)   P.push_back(Q);
	if(intersect(M1,M2,Q)>0)   P.push_back(Q);
}

bool cover(const Circle &c,const Point &p){
	return abs(p-c.c)<c.r+EPS;
}

bool cover(const Sector &S,const Point &P){
	if(abs(S.c-P)<EPS)      return true;
	if(!cover(Circle(S),P)) return false;

	double a1=arg(polar(1.0,S.t1));
	double a2=arg(polar(1.0,S.t2));
	double ap=arg(P-S.c);
	if(a2<a1-EPS) a2+=2*PI;
	if(ap<a1-EPS) ap+=2*PI;
	return a1-EPS<ap && ap<a2+EPS;
}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		Sector S[16];
		rep(i,n){
			int x,y,t1,t2; scanf("%d%d%lf%d%d",&x,&y,&S[i].r,&t1,&t2);
			S[i].c=Point(x,y);
			S[i].t1=PI*t1/180;
			S[i].t2=PI*t2/180;
		}

		vector<Point> P;
		rep(i,n){
			P.push_back(S[i].c);
			for(int j=i+1;j<n;j++) intersect(S[i],S[j],P);
		}

		int ans=0;
		rep(i,P.size()){
			int cnt=0;
			rep(j,n) if(cover(S[j],P[i])) cnt++;
			ans=max(ans,cnt);
		}
		printf("%d\n",ans);
	}

	return 0;
}