#include <bits/stdc++.h>
#define double long double
using namespace std;

const double INF = 1e9;
const double EPS = 1e-11;

// ????¬????
struct P3{
  double x,y,z;
  double vx,vy,vz;
  double r,vr;
  P3(double x=0, double y=0, double z=0):x(x),y(y),z(z){}
  P3 operator + (const P3 &a) const{ return P3(x+a.x, y+a.y, z+a.z); }
  P3 operator - (const P3 &a) const{ return P3(x-a.x, y-a.y, z-a.z); }
  P3 operator * (const double &c) const{ return P3(x*c, y*c, z*c); }
  void input(){cin>>x>>y>>z>>vx>>vy>>vz>>r>>vr;}
  P3 v ()const{return P3(vx,vy,vz);}
};
P3 operator * (double c, const P3 &a){ return P3(c * a.x, c * a.y, c * a.z); }


double norm(P3 a){ return a.x*a.x + a.y*a.y + a.z*a.z; }
double abs(P3 a){ return sqrt(norm(a)); }

typedef pair<int,int> P;
typedef pair<double,P> PP;

double calc(P3 A,P3 B,double t){
  if((A.r-t*A.vr)<0|| (B.r-t*B.vr)<0) return -1;
  return abs((A+t*A.v())-(B+t*B.v())) - ((A.r-t*A.vr) + (B.r-t*B.vr));
}

double calc(P3 A,P3 B){
  double L=0,R=INF,cnt = 64;
  while(cnt--){
    double M = (L+R)/2;
    double y1 = calc(A,B,M);
    double y2 = calc(A,B,M+EPS);
    if(y1<0||y1-y2<0) R = M;
    else L = M+EPS;
  }
  return L;
}

int main(){
  int n;
  while(cin>>n,n){
    vector<P3>A(n);
    for(int i=0;i<n;i++) A[i].input();

    priority_queue<PP,vector<PP>,greater<PP> >Q;
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
	double t = calc(A[i],A[j]);
	if(abs(calc(A[i],A[j],t))<2e-8)Q.push(PP(t,P(i,j)));
      }

    vector<double> ans(n,-1);
    while(!Q.empty()){
      PP t = Q.top();Q.pop();
      double c = t.first;
      int a = t.second.first;
      int b = t.second.second;
      if(ans[a]>=0||ans[b]>=0)continue;
      ans[a] = ans[b] = c;
    }

    for(int i=0;i<n;i++){
      if(ans[i]<0) ans[i] = A[i].r / A[i].vr;
      ans[i] = min(ans[i],A[i].r / A[i].vr);
      printf("%.10Lf\n",ans[i]);
    }    
    
  }
  return 0;    
}