#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define eps 1.0e-8
#define INF 1e50
#define g 4.9
using namespace std;
double X,Y;
int n;
struct G{
    double x;
    double y;
};
G d[1010];
double calc(double x)
{
    double ans=0;
    for(int i=0;i<n;i++){
        double t=(x*d[i].x/g+d[i].y/g)/2.0;
        if(t>0) ans+=t*d[i].x;
    }
    return ans;
}
double calcy(double x)
{
    double ans=0;
    for(int i=0;i<n;i++){
        double t=(x*d[i].x/g+d[i].y/g)/2.0;
        if(t>0) ans+=t*d[i].y-g*t*t;
    }
    return ans;
}
double cnt()
{
    double left=-1e4, right=1e4, mid;
    while(left+eps<right){
        mid=left+(right-left)/2.0;
        if(calc(mid)>=X) right=mid;
        else left=mid;
    }
    return calcy(left);
}
int main()
{
    int i,j;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++) scanf("%lf%lf",&d[i].x,&d[i].y);
        scanf("%lf%lf",&X,&Y);
        //for(i=0;i<n;i++) printf("%lf %lf\n",d[i].x,d[i].y);
        double ymin=INF, ymax=-INF;
        for(i=0;i<n;i++){
            double t1=X/d[i].x, y=d[i].y*t1-g*t1*t1;
            ymin=min(y,ymin);
        }
        double tmp=cnt();
        ymax=max(ymax,tmp);
        //printf("%f %f\n",ymin,ymax);
        if(Y<=ymax+eps&&Y>=ymin-eps) puts("Yes");
        else puts("No");
    }
    return 0;
}