#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1);
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
inline double ABS(double a){return max(a,-a);}
struct Pt {
	double x, y;
	Pt() {}
	Pt(double x, double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const double &k) const { return Pt(x / k, y / k); }
	double ABS() const { return sqrt(x * x + y * y); }
	double abs2() const { return x * x + y * y; }
	double arg() const { return atan2(y, x); }
	double dot(const Pt &a) const { return x * a.x + y * a.y; }
	double det(const Pt &a) const { return x * a.y - y * a.x; }
};
double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }
pair<Pt,Pt> tCP(Pt a, double r, Pt b) {
	double d2 = (b - a).abs2();
	double x = sqrt(max(d2 - r * r, 0.0));
	Pt h = a + (b - a) * (r * r / d2);
	Pt w = (b - a) * Pt(0, 1) * (x * r / d2);
	return make_pair(h - w, h + w);
}
double dLP(Pt a, Pt b, Pt c) {
	return ABS(tri(a, b, c)) / (b - a).ABS();
}
double x[60];
double y[60];
double r[60];
double m[60];
vector<pair<Pt,Pt> > p;
void add(Pt a,double ar,Pt b,double br){
	Pt p1=(a*br+b*ar)/(ar+br);
	pair<Pt,Pt> q1=tCP(a,ar,p1);
	p.push_back(make_pair(p1,q1.first));
	p.push_back(make_pair(p1,q1.second));
	if(sig(ar-br)){
		Pt p2=(b*ar-a*br)/(ar-br);
		pair<Pt,Pt> q2=tCP(a,ar,p2);
		p.push_back(make_pair(p2,q2.first));
		p.push_back(make_pair(p2,q2.second));
	}else{
		Pt v=(b-a)*Pt(0,1);
		double ks=v.ABS();
		v=v/ks*ar;
		p.push_back(make_pair(a+v,b+v));
		p.push_back(make_pair(a-v,b-v));
	}
}
int main(){
	int a;
	while(scanf("%d",&a),a){
		for(int i=0;i<a;i++){
			scanf("%lf%lf%lf%lf",x+i,y+i,r+i,m+i);
		}
		if(a==1){
			printf("1\n");continue;
		}
		p.clear();
		for(int i=0;i<a;i++){
			for(int j=i+1;j<a;j++){
				add(Pt(x[i],y[i]),r[i],Pt(x[j],y[j]),r[j]);
				add(Pt(x[i],y[i]),r[i]+m[i],Pt(x[j],y[j]),r[j]);
				add(Pt(x[i],y[i]),r[i],Pt(x[j],y[j]),r[j]+m[j]);
				add(Pt(x[i],y[i]),r[i]+m[i],Pt(x[j],y[j]),r[j]+m[j]);
			}
		}
		int ret=0;
		for(int i=0;i<p.size();i++){
			int val=0;
			for(int j=0;j<a;j++){
				double d=dLP(p[i].first,p[i].second,Pt(x[j],y[j]));
				if(d+EPS>r[j]&&d-EPS<r[j]+m[j])val++;
			}
			ret=max(ret,val);
		}
		printf("%d\n",ret);
	}
}