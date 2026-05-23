#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define EQ(a,b) (abs((a)-(b))<EPS)
using namespace std;
typedef double D;
const D EPS = 1e-8;

inline D getTime(D dx, D dy, D v, D fpx, D fpy, D fvx, D fvy){
  D px = fpx-dx, py = fpy-dy;
  D a = fvx*fvx + fvy*fvy - v*v;
  D b = 2*fvx*px + 2*fvy*py;
  D c = px*px + py*py;

  if(EQ(a,0)){
    if(EQ(b,0))return EQ(c,0)?0:-1;
    else return (-c/b<-EPS)?-1:-c/b;
  }else{
    D d = b*b - 4*a*c;
    if(d < -EPS)return -1;
    if(EQ(d,0))return (-b/2/a<-EPS)?-1:-b/2/a;
    D t1 = (-b-sqrt(d))/2/a, t2 = (-b+sqrt(d))/2/a;
    if(t1<-EPS)return (t2<-EPS)?-1:t2;
    return t1;
  }
}

int main(){
  int n,m;
  D dx[10], dy[10], v[10], t[10];
  int cnt[10];
  while(scanf("%d%d",&n,&m),n){
    rep(i,n)scanf("%lf%lf%lf",dx+i,dy+i,v+i);

    memset(cnt,0,sizeof(cnt));
    rep(i,m){
      D fpx, fpy, fvx, fvy;
      scanf("%lf%lf%lf%lf",&fpx,&fpy,&fvx,&fvy);
      
      D minT = 1e10;
      int minID = -1;
      rep(i,n){
	t[i] = getTime(dx[i],dy[i],v[i], fpx,fpy,fvx,fvy);
	if(t[i]>-EPS && minT > t[i] + EPS){
	  minT = t[i]; minID = i;
	}
      }

      cnt[minID]++;
      rep(i,n){
	if(t[i]>-EPS){
	  D sx = fpx+fvx*t[i] - dx[i], sy = fpy+fvy*t[i] - dy[i];
	  D absS = sqrt(sx*sx + sy*sy);
	  if(EQ(absS,0))continue;
	  sx /= absS; sy /= absS;
	  dx[i] += sx * v[i] * minT; dy[i] += sy * v[i] * minT;
	}
      }
    }
    rep(i,n)printf("%d%c",cnt[i],i==n-1?'\n':' ');
  }
}