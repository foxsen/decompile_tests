#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define reps(i,j,k) for(int i=(j);i<=(k);++i)
#define in(i,j,k) ((i)>=(j)&&(i)<=(k))
#define sz size()


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

const double EPS=1e-8,INF=1e12;
typedef complex<double> P;
typedef P point;
namespace std{
  bool operator<(const P &a,const P &b){
    return real(a)!=real(b)?real(a)<real(b):imag(a)<imag(b);}
}
double cross(const P &a,const P &b){
  return imag(conj(a)*b);
}
double dot(const P &a,const P &b){
  return real(conj(a)*b);
}

struct L :public vector<P>{
  L(const P &a,const P &b){
    pb(a); pb(b);
  }
};

typedef pair<point,point> ppp;

int ccw(P a,P b,P c){
  b-=a; c-=a;
  if(cross(b,c)>EPS) return 1;
  if(cross(b,c)<-EPS) return -1;
  if(dot(b,c)<-EPS) return +2;
  if(norm(b)+EPS<norm(c)) return -2;
  return 0;
}

ppp c_c_inter(const point &c1,const double &r1,
	      const point &c2,const double &r2){
  point A=conj(c2-c1), B=(r2*r2-r1*r1-(c2-c1)*conj(c2-c1)),C=r1*r1*(c2-c1);
  point D=B*B-4.*A*C;
  point z1=(-B+sqrt(D))/(2.0*A)+c1, z2=(-B-sqrt(D))/(2.0*A)+c1;
  return ppp(z1,z2);
}

bool interLS(const L &l,const L s){
  return cross(l[1]-l[0], s[0]-l[0])*
    cross(l[1]-l[0],s[1]-l[0])<EPS;
}

double len(const L &l){
  return abs(l[0]-l[1]);
}
double d[212][212];

int main(){
  cout<<fixed<<setprecision(10);
  int n;
  while(cin>>n,n){
    vector<P> c(n);
    vector<double> r(n);
    double x,y;
    rep(i,n){
      cin>>x>>y>>r[i];
      c[i]=P(x,y);
    }
    vector<ppp> ps(n-1);
    rep(i,n-1)
      ps[i]=c_c_inter(c[i],r[i],c[i+1],r[i+1]);

    fill(d[0],d[0]+212*212,INF);
    rep(i,n-1){
      L lx(c[0],ps[i].X),ly(c[0],ps[i].Y);
      int fx=1,fy=1;
      rep(j,i){
	fx&=interLS(lx,L(ps[j].X,ps[j].Y));
	fy&=interLS(ly,L(ps[j].X,ps[j].Y));
      }
      if(fx)d[2*n-2][2*i]=d[2*i][2*n-2]=len(lx);
      if(fy)d[2*n-2][2*i+1]=d[2*i+1][2*n-2]=len(ly);
    }
    rep(i,n-1){
      L lx(c[n-1],ps[i].X),ly(c[n-1],ps[i].Y);
      int fx=1,fy=1;
      for(int j=i;j<n-1;++j){
	fx&=interLS(lx,L(ps[j].X,ps[j].Y));
	fy&=interLS(ly,L(ps[j].X,ps[j].Y));
      }
      if(fx)d[2*n-1][2*i]=d[2*i][2*n-1]=len(lx);
      if(fy)d[2*n-1][2*i+1]=d[2*i+1][2*n-1]=len(ly);
    }
    L l(c[0],c[n-1]);
    int f=1;
    rep(i,n-1)
      f&=interLS(l,L(ps[i].X,ps[i].Y));
    if(f) d[2*n-1][2*n-2]=d[2*n-2][2*n-1]=len(l);
    rep(i,n-1)rep(j,i)rep(a,2)rep(b,2){
      L l(a?ps[i].Y:ps[i].X,b?ps[j].Y:ps[j].X);
      int f=1;
      for(int k=j+1;k<i;++k)
	f&=interLS(l,L(ps[k].X,ps[k].Y));
      if(f)
	d[2*i+a][2*j+b]=d[2*j+b][2*i+a]=len(l);
    }
    rep(k,2*n)rep(i,2*n)rep(j,2*n)
      d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    cout<<d[2*n-1][2*n-2]<<endl;
  }
  return 0;
}