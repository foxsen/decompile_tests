#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-11;
const double INF=1e77;
const double PI=acos(-1);

struct point{
	double x,y;
	point():x(0),y(0){}
	point(double x,double y):x(x),y(y){}
	point operator+(const point &a)const{ return point(x+a.x,y+a.y); }
	point operator-(const point &a)const{ return point(x-a.x,y-a.y); }
};

point operator*(double c,const point &a){ return point(c*a.x,c*a.y); }

double abs(const point &a){ return sqrt(a.x*a.x+a.y*a.y); }

point rot(const point &a,double theta){ return point(a.x*cos(theta)-a.y*sin(theta),a.x*sin(theta)+a.y*cos(theta)); }

double arg(const point &a){
	double t=atan2(a.y,a.x);
	return t<0?t+2*PI:t;
}

struct line{
	point a,b;
	line(){}
	line(const point &a,const point &b):a(a),b(b){}
};

struct circle{
	point c;
	double r;
	circle():c(point(0,0)),r(0){}
	circle(const point &c,double r):c(c),r(r){}
};

int tangent(const circle &C1,const circle &C2,vector<line> &res){
	double d=abs(C1.c-C2.c);
	if(d<EPS) return 0;

	int c=0;
	// 内接線
	if(C1.r+C2.r<d-EPS){
		double t=acos((C1.r+C2.r)/d);
		res.push_back(line(C1.c+rot(C1.r/d*(C2.c-C1.c), t),C2.c+rot(C2.r/d*(C1.c-C2.c), t)));
		res.push_back(line(C1.c+rot(C1.r/d*(C2.c-C1.c),-t),C2.c+rot(C2.r/d*(C1.c-C2.c),-t)));
		c+=2;
	}
	else if(C1.r+C2.r<d+EPS){
		point p=C1.c+C1.r/d*(C2.c-C1.c);
		res.push_back(line(p,p+rot(C2.c-C1.c,PI/2)));
		c++;
	}

	// 外接線
	if(abs(C1.r-C2.r)<d-EPS){
		double t1=acos((C1.r-C2.r)/d),t2=PI-t1;
		res.push_back(line(C1.c+rot(C1.r/d*(C2.c-C1.c), t1),C2.c+rot(C2.r/d*(C1.c-C2.c),-t2)));
		res.push_back(line(C1.c+rot(C1.r/d*(C2.c-C1.c),-t1),C2.c+rot(C2.r/d*(C1.c-C2.c), t2)));
		c+=2;
	}
	else if(abs(C1.r-C2.r)<d+EPS){
		point p=C1.c+C1.r/d*(C2.c-C1.c);
		res.push_back(line(p,p+rot(C2.c-C1.c,PI/2)));
		c++;
	}

	return c;
}

int n;
circle C[100];

// 影たちの位置関係は θ=φ の状態から変わらないとして, dw/dθ = 0 を達成する θ を求める. ( w : 影の長さ )
double calc_peak(double phi){
	pair<double,int> pos[100];
	rep(i,n){
		pos[i]=make_pair(rot(C[i].c,phi).y,i);
	}
	sort(pos,pos+n);

	double a=0,b=0; // dw/dθ = 0 <=> a*cos(θ) + b*sin(θ) = 0
	int pre=0;
	for(int i=1;i<=n;i++){
		if(i==n || pos[i-1].first+1<pos[i].first-1){
			// 今見ている影の連結成分は長さは d*sin(t-θ)+2
			double d=abs(C[pos[i-1].second].c-C[pos[pre].second].c);
			double t=arg(C[pos[i-1].second].c-C[pos[pre].second].c);
			// d*cos(t-θ) = d*cos(t)*cos(θ) + d*sin(t)*sin(θ)
			a+=d*cos(t);
			b+=d*sin(t);

			pre=i;
		}
	}

	double res=PI-atan2(-a,b);
	if(res>PI) res-=PI;
	return res;
}

double calc_width(double phi){
	double pos[100];
	rep(j,n){
		pos[j]=rot(C[j].c,phi).y;
	}
	sort(pos,pos+n);

	double res=0,x=-INF;
	rep(i,n){
		x=max(x,pos[i]-1);
		res+=max(pos[i]+1-x,(double)0);
		x=max(x,pos[i]+1);
	}
	return res;
}

int main(){
	while(scanf("%d",&n),n){
		rep(i,n) scanf("%lf%lf",&C[i].c.x,&C[i].c.y), C[i].r=1;

		vector<line> L;
		rep(i,n) rep(j,i) tangent(C[i],C[j],L);

		vector<double> T; // 二円の共通接線の角度
		rep(i,L.size()){
			double phi=PI-arg(L[i].b-L[i].a);
			if(phi<0) phi+=PI;
			T.push_back(phi);
		}
		T.push_back(0);
		T.push_back(PI);
		sort(T.begin(),T.end());
		// unique
		rep(i,(int)T.size()-1) if(T[i+1]-T[i]<EPS) T.erase(T.begin()+i--);

		double mini=INF,phi_mini;
		double maxi= 0 ,phi_maxi;
		rep(i,T.size()){
			double w=calc_width(T[i]);
			if(w<mini) mini=w, phi_mini=T[i];
			if(w>maxi) maxi=w, phi_maxi=T[i];

			if(i+1<T.size()){
				double phi0=(T[i]+T[i+1])/2;
				double phi1=calc_peak(phi0);

				w=calc_width(phi1);
				if(w<mini) mini=w, phi_mini=phi1;
				if(w>maxi) maxi=w, phi_maxi=phi1;
			}
		}
		printf("%.15f\n",phi_mini);
		printf("%.15f\n",phi_maxi);
	}

	return 0;
}