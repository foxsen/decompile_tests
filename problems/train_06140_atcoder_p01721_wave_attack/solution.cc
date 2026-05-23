#include<bits/stdc++.h>
#define inf 1<<29
#define linf 1e16
#define eps (1e-3)
#define mod 1000000007
#define pi acos(-1)
#define phi (1.0+sqrt(5))/2.0
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10f\n",(double)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a)-1;(b)<=i;i--)
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef vector<int> vi;
typedef vector<pii> vpi;
const int dx[8]={1,0,-1,0,1,1,-1,-1};
const int dy[8]={0,1,0,-1,1,-1,1,-1};

double w,h,v,t,x,y,p,q,r;

ull count(double W){
  if(r-(W-x)<-eps)return 0;
  double H=sqrt(r*r-(W-x)*(W-x));
  ull res=0;
  res+=(int)((y+H-q)/h)-(int)((y-H-q)/h);
  res+=(int)((y+H+q)/h)-(int)((y-H+q)/h);
  if(y-H<=q && q<=y+H)res++;
  if(y-H<=-q && -q<=y+H)res++;

  return res;
}

ull solve(){
  ull res=0;
  r=v*t;w*=2.0;h*=2.0;
  for(double i=p;i-x-r<eps;i+=w)res+=count(i);
  for(double i=-p;i-x-r<eps;i+=w)res+=count(i);
  for(double i=p-w;x-r-i<eps;i-=w)res+=count(i);
  for(double i=-p-w;x-r-i<eps;i-=w)res+=count(i);
  return res;
}

int main()
{
  cin>>w>>h>>v>>t>>x>>y>>p>>q;
  cout<<solve()<<endl;
  return 0;
}