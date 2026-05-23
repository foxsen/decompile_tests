#include<iostream>
#include<cstdio>
#include<cmath>
typedef long long ll;
const int N=305;
int h,w,d,row[N*N],col[N*N],a[N][N];
ll dp[N*N];
int main() {
    scanf("%d%d%d",&h,&w,&d);
    for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) scanf("%d",a[i]+j),row[a[i][j]]=i,col[a[i][j]]=j;
    for(int i=1;i<=h*w;i++) if(i<=d) dp[i]=0;else dp[i]=dp[i-d]+abs(row[i]-row[i-d])+abs(col[i]-col[i-d]);
    int q,l,r;scanf("%d",&q);
    while(q--) {
        scanf("%d%d",&l,&r);
        printf("%lld\n",dp[r]-dp[l]);
    }
    return 0;
}
