#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define INTERVAL 2097152
#define EPS 1e-9

int W,H,N;
int yama[101][3];
double xint[101][2];
double quad(double x,int nyama)
{
  double a=yama[nyama][0];
  double p=yama[nyama][1];
  double q=yama[nyama][2];
  return a*(x-p)*(x-p)+q;
}
double x_int(int nyama,int left)
{
  double a=yama[nyama][0];
  double p=yama[nyama][1];
  double q=yama[nyama][2];
  return p+1.0*left*sqrt(-q/a);
}
double q_int(int nyama1, int nyama2, int left)
{
  int a1=yama[nyama1][0];
  int p1=yama[nyama1][1];
  int q1=yama[nyama1][2];
  int a2=yama[nyama2][0];
  int p2=yama[nyama2][1];
  int q2=yama[nyama2][2];
  if (a1==a2)
  {
    if(p1==p2)
      return -1.0;
    else
    {
        double ans=0.5*(p1+p2+(q2-q1)*1.0/(a1*(p2-p1)));
        if (quad(ans,nyama1)>0-EPS)
          return ans;
        else
          return -1.0;
    }

  }
  else
  {
    double A=a1-a2;
    double B=2*(p2*a2-p1*a1);
    double C=a1*p1*p1-a2*p2*p2+q1-q2;
    double delta=B*B-4*A*C;
    if (delta>0-EPS)
    {
      double ans=(-B+1.0*left*sqrt(delta))/(2.0*A);
      if (quad(ans,nyama1)>0-EPS)
        return ans;
      else
        return -1.0;
    }
    else
      return -1.0;
  }
}

double dquad_dx(double x,int nyama)
{
  double a=yama[nyama][0];
  double p=yama[nyama][1];
  return 2.0*a*(x-p);
}

double cir(double x,int nyama)
{
  double fpx=dquad_dx(x,nyama);
  return sqrt(1+fpx*fpx);
}


/*数値計算積分、ずっとTLEかWA（誤差は約1e-5~1e-4）
double integrates(int s, int nyama)
{
  double a=1.0*s/INTERVAL;
  double b=1.0*(s+1)/INTERVAL;
  //return 1.0/6.0/INTERVAL*(cir(a,nyama)+cir(b,nyama)+4*cir((a+b)/2.0,nyama));
  return 1.0/2.0/INTERVAL*(cir(a,nyama)+cir(b,nyama));
}

double integrate(double b,double e,int nyama)
{

  int begin=b*INTERVAL;
  int end=e*INTERVAL;
  double ans=0.0;
  for(int i=begin;i<end;i++)
  {
    ans+=integrates(i,nyama);
  }
  return ans;
}
*/
//解析積分
double integrated(double x, int nyama)
{
  double a=yama[nyama][0];
  double fpx=dquad_dx(x,nyama);
  return (fpx*cir(x,nyama)+log(abs(fpx+cir(x,nyama))))/4.0/a;
}

double integrate(double b,double e,int nyama)
{
  return integrated(e,nyama)-integrated(b,nyama);
}
//

vector<double> sec;
int main()
{
  scanf("%d%d%d",&W,&H,&N);
  for(int i=0;i<N;i++)
  {
    scanf("%d%d%d",&yama[i][0],&yama[i][1],&yama[i][2]);
    xint[i][0]=x_int(i,-1);
    xint[i][1]=x_int(i,1);
    double tmp1=x_int(i,-1);
    double tmp2=x_int(i,1);
    if (-EPS< tmp1 && tmp1<W+EPS)
      sec.push_back(tmp1);
    if (-EPS< tmp2 && tmp2<W+EPS && fabs(tmp1-tmp2)>EPS)
      sec.push_back(tmp2);
  }
  for(int i=0;i<N;i++)
    for(int j=i+1;j<N;j++)
    {
      double tmp1=q_int(i,j,-1);
      double tmp2=q_int(i,j,1);
      if (-EPS< tmp1 && tmp1<W+EPS)
        sec.push_back(tmp1);
      if (-EPS< tmp2 && tmp2<W+EPS && fabs(tmp1-tmp2)>EPS)
        sec.push_back(tmp2);
    }
  sort(sec.begin(),sec.end());
  sec.erase(unique(sec.begin(),sec.end()), sec.end() );

  double ans=0;
  double mae=0.0;
  vector<double>::iterator it=sec.begin();
  while(1)
  {
    int nyama=-1;
    double max=0.0;
    double now_p;
    if (it==sec.end())
      now_p=1.0*W;
    else
      now_p=(*it);
    //printf("%lf\n",now_p);
    for(int j=0;j<N;j++)
    {
      double x=(mae+now_p)/2.0;
      if (x<xint[j][0]-EPS||x>xint[j][1]+EPS) continue;
      double y=quad(x,j);
      if(y>max+EPS)
      {
        max=y;
        nyama=j;
      }
    }
    if (nyama!=-1)
      ans+=integrate(mae,now_p,nyama);
    if (it==sec.end()) break;
    mae=now_p;
    ++it;
  }

  printf("%lf\n",ans);
}

