#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=1e6;
const LL INF=1e16;
int n;
LL now[N+10],sum[N+10],f[N+10];
struct data {
    LL x,y;
}a[N+10];
bool cmp1(data p,data q) {
    return p.x<q.x;
}
bool cmp2(data p,data q) {
    return p.y<q.y;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp2);
    for (int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+a[i].y;
        now[i]=sum[i]-a[i].y+a[i+1].y;
    }
    sort(a+1,a+n+1,cmp1);
    for (int i=n;i>=1;i--) f[i]=f[i+1]+a[i].y;
    LL nowx=0,ans=f[1];
    for (int i=1;i<=n;i++) {
        nowx+=a[i].x;
        if (i==n) {
            ans=min(ans,nowx);
            continue;
        }
        if (f[i+1]!=sum[n-i]) {
            ans=min(ans,nowx+sum[n-i]);
            continue;
        }
        ans=min(ans,min(nowx+sum[n-i]-a[i].x+a[i+1].x,nowx+now[n-i]));
    }
    printf("%lld\n",ans);
    return 0;
}
