#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// Can't use x and y for first and second
#define x real()
#define y imag()
#define X first
#define Y second
#define cpt const Pt&
//#define Pt Pt//const Pt&

//#define double long double
const double EPS = 1e-9;
const double pi=acos(-1);
bool deq(double a,double b) {return abs(a-b)<EPS;}
enum Orientation {CCW, CW, CNEITHER};

typedef complex<double> cpx;

struct Pt : public cpx {
    Pt() = default;
	using cpx::cpx;
	Pt(cpx a) : cpx(a) {}
    double& x const {
        return (double&)*this;
    }
    double& y const {
        return ((double*)this)[1];
    }

	bool operator ==(cpt b) const {return abs(*this-b) < EPS; }
	//by x first then break ties with y
	bool operator <(cpt b) const {return x<b.x || (x==b.x && y<b.y); }

	// Compare by arg then by norm (approximate)
	// arg is in range (-pi,pi].
	// Compare by arg then by norm (exact)
};

//Allow points to be read in by input streams
istream& operator >>(istream& is, Pt& p) {
	return is >> p.x >> p.y;
}

double dot(cpt a, cpt b) {return (conj(a) * b).x;}// Dot product
double det(cpt a, cpt b) {return (conj(a) * b).y;}//Determinant/"Cross Product"
double angle(cpt a, cpt b) {return arg(b - a);}// [-pi,pi] a to b with x axis
double angle (cpt a, cpt b, cpt c) {return arg((a-b)/(c-b));}//[-pi,pi]
//double slope(cpt a, cpt b) {return tan(arg(b - a));}// m for line segment (a,b)
double slope(cpt a, cpt b) {return (b.y-a.y)/(b.x-a.x);}

Pt rotate(cpt a, double theta) {return a * polar((double)1.0, theta);}//anticlockwise
//around p by theta anticlockwise
Pt rotate(cpt a, cpt p, double theta) {return rotate(a - p,theta) + p;}
Pt project(cpt p, cpt v) {return v * dot(p, v) / norm(v);}// p onto v
Pt project(cpt p, cpt a, cpt b) {return a+project(p-a,b-a);}//p onto line (a,b)
//reflect p across the line (a,b)
Pt reflect(cpt p, cpt a, cpt b) {return a + conj((p - a) / (b - a)) * (b - a);}



struct Circle {
	Pt c;double r;
	bool operator==(const Circle& b) const {return c==b.c && deq(r,b.r);}
};


//untested
//Area of polygon and circle intersection
double areapolygoncircle(vector<Pt> p,Circle c) {
	int n=p.size();
	double r=0;
	for (int i=n-1,j=0;j<n;i=j++) {
		Pt v=abs(p[j]-p[i])/(p[j]-p[i]);
		if (p[j]==p[i]) continue;
		assert(p[j]!=p[i]);
		Pt a=(p[i]-c.c)*v,b=(p[j]-c.c)*v;
		double d=norm(c.r)-norm(a.y);
		//cerr << a << ' ' << b << ' ' << sqrt(d) << endl;
		if (abs(a.y)<EPS/*deq(a.y,0)*/) continue;
		if (d<0) d=0;//r+=norm(c.r)*(arg(b)-arg(a));
		//else {
			d=sqrt(d);
			//cerr << d << endl;
			double l,m;
			r+=norm(c.r)*((l=atan2(b.y,min(b.x,-d))-atan2(a.y,min(a.x,-d)))
					+(m=atan2(b.y,max(b.x,d))-atan2(a.y,max(a.x,d))))
				+a.y*(min(d,max(a.x,-d))-max(-d,min(b.x,d)));
			assert(-pi < l && -pi<m && l<pi && m<pi);
			//cerr << "r: " << r << endl;
		//}
	}
	return r/2;
}



namespace AIZU_CGL_7_H {
	void solve() {
		int n,r;
		cin >> n >> r;
		vector<Pt> p(n);
		for (Pt &a:p) cin >> a;
		cout << fixed << setprecision(10) << areapolygoncircle(p,{0,(double)r}) << endl;
	}
}



int main() {
	
	//Test::solve();
	//UVA_920::solve();
	//UVA_10263::solve();
	//UVA_10927::solve(); // Use EPS=1e-10
	//UVA_378::solve();
	//UVA_191::solve();
	//AIZU_CGL_3_C::solve();
	//UVA_634::solve();
	//UVA_453::solve(); // Use EPS=1e-4
	AIZU_CGL_7_H::solve();
	//CirclePolyTest::solve();
	//cerr << distfinitelinept({10,-6},{-8,9},0) << endl;
}