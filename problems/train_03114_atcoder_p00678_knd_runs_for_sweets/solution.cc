#include<cmath>
#include<cstdio>
#include<vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;

template<class T>
struct point{
	T x,y;
	point operator+(const point &a)const{ return (point){x+a.x,y+a.y}; }
	point operator-(const point &a)const{ return (point){x-a.x,y-a.y}; }
};

template<class T>
point<T> operator*(T c,const point<T> &a){ return (point<T>){c*a.x,c*a.y}; }

template<class T>
double abs(const point<T> &a){ return sqrt(a.x*a.x+a.y*a.y); }

template<class T>
struct circle{
	point<T> c;
	T r;
};

template<class T>
double dist(const point<T> &a,const point<T> &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cover(const circle<double> &C,const point<double> &p){
	return dist(C.c,p)<C.r+EPS;
}

int get_intersect(const circle<double> &C1,const circle<double> &C2,vector< point<double> > &res){
	double r1=C1.r,r2=C2.r;
	point<double> p1=C1.c,p2=C2.c;

	double d=abs(p1-p2);
	if(d<EPS && abs(r1-r2)<EPS){ // C1==C2
		return -1;
	}
	else if(r1+r2<d-EPS || d+EPS<abs(r1-r2)){
		return 0;
	}
	else{
		double a=(r1*r1-r2*r2+d*d)/(2*d);
		double h=sqrt(max(r1*r1-a*a,0.0));
		point<double> tmp1=p1+a/d*(p2-p1);
		point<double> tmp2=h/d*(p2-p1);
		if(abs(tmp2)<EPS){
			res.push_back(tmp1);
			return 1;
		}
		else{
			res.push_back((point<double>){tmp1.x-tmp2.y,tmp1.y+tmp2.x});
			res.push_back((point<double>){tmp1.x+tmp2.y,tmp1.y-tmp2.x});
			return 2;
		}
	}
}

int main(){
	for(int n;scanf("%d",&n),n;){
		circle<double> C[100];
		int v[100];
		rep(i,n) scanf("%lf%lf%d",&C[i].c.x,&C[i].c.y,v+i);

		double lo=0,hi=1e7;
		while(hi-lo>1e-6){
			double mi=(lo+hi)/2;
			rep(i,n) C[i].r=v[i]*mi;

			vector< point<double> > cand;
			rep(i,n) cand.push_back(C[i].c);
			rep(i,n) rep(j,i) get_intersect(C[i],C[j],cand);

			bool ok=false;
			rep(i,cand.size()){
				int j;
				for(j=0;j<n;j++) if(!cover(C[j],cand[i])) break;
				if(j==n){ ok=true; break; }
			}
			if(ok) hi=mi; else lo=mi;
		}

		printf("%.9f\n",(lo+hi)/2);
	}

	return 0;
}