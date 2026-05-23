#include<bits/stdc++.h>
#define MN 200005
typedef std::pair<int,int> P;
int n,a[MN],lst;
int pos[MN],val[MN],cnt;
bool check(int x)
{
    cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1]) continue;
        for(;cnt&&pos[cnt]>a[i];cnt--);
        if(pos[cnt]<a[i]) pos[++cnt]=a[i],val[cnt]=0;
        for(;1;)
        {
            val[cnt]++;
            if(val[cnt]<x) break;
            if(pos[cnt]==1) return 0;
            val[cnt]=0;
            if(pos[cnt-1]!=pos[cnt]-1) pos[cnt]--;
            else cnt--;
        }
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int l=1,r=n+1,ans;
    while(l<=r)
    {
        int mid=l+r+1>>1;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
}
