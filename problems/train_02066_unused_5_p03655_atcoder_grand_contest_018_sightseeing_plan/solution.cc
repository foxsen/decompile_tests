#include<cstdio>
#include<iostream>
#define ll long long
#define N 2000010
using namespace std;
const int p = 1000000007;
int jie[N],ni[N];
const int inf = 2000005;
int c(int m,int n)
{
    return 1LL*jie[n]*ni[m]%p*ni[n-m]%p;
}
ll ans;
int ss(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int as=0;
    for(int i=y1;i<=y2;i++)
    {
        (as+=1LL*c(x3-x2-1,x3-x2-1+y3-i)*c(x2-x1,x2-x1+i-y1)%p*(x2-x1+1+i-y1)%p)%=p;
    }
    for(int i=x1;i<=x2;i++)
    {
        (as+=1LL*c(y3-y2-1,y3-y2-1+x3-i)*c(y2-y1,y2-y1+i-x1)%p*(y2-y1+1+i-x1)%p)%=p;
    }
    return as;
}
int x1,x2,x3,x4,x5,x6;
int y1,y2,y3,y4,y5,y6;
int calc(int a1,int b1,int a2,int b2)
{
    int as=0;
    as+=ss(a1,b1,x4,y4,a2,b2);
    as+=ss(a1,b1,x3-1,y3-1,a2,b2);as%=p;
    as-=ss(a1,b1,x3-1,y4,a2,b2);
    as-=ss(a1,b1,x4,y3-1,a2,b2);
    return (as%p+p)%p;
}
int solve(int x,int y)
{
    int as=0;
    as+=calc(x,y,x6+1,y6+1);as+=calc(x,y,x5,y5);as%=p;
    as-=calc(x,y,x6+1,y5);as-=calc(x,y,x5,y6+1);
    return (as%p+p)%p;
}
int main()
{
    jie[0]=ni[0]=ni[1]=1;
    for(int i=1;i<=inf;i++)jie[i]=1LL*jie[i-1]*i%p;
    for(int i=2;i<=inf;i++)ni[i]=1LL*(p-p/i)*ni[p%i]%p;
    for(int i=2;i<=inf;i++)ni[i]=1LL*ni[i-1]*ni[i]%p;
    scanf("%d%d%d%d%d%d",&x1,&x2,&x3,&x4,&x5,&x6);
    scanf("%d%d%d%d%d%d",&y1,&y2,&y3,&y4,&y5,&y6);
    ans+=solve(x1-1,y1-1);
    ans+=solve(x2,y2);
    ans-=solve(x1-1,y2);
    ans-=solve(x2,y1-1);
    ans=(ans%p+p)%p;
    printf("%lld\n",ans);
    return 0;
}