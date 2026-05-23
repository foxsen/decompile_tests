#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int M=20;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n;
ll ans[M];
pair<pair<int,int>,ll> a[M];
vector<int> dis(M);
bool vis[M][2];
ll count()
{
    ll re=0;
    for(int i=0;i<n;i++)
        re+=a[i].second*dis[i];
    return re;
}
void dfs(int tot=0,int floor=0)
{
    ans[tot]=min(ans[tot],count());
    if(tot==n || floor==n) return;

    vector<int> tmp=dis;
    for(int i=0;i<n;i++)
        dis[i]=min(tmp[i],abs(a[i].first.first-a[floor].first.first));
    vis[floor][0]=1;
    dfs(tot+1,floor+1);
    vis[floor][0]=0;

    for(int i=0;i<n;i++)
        dis[i]=min(tmp[i],abs(a[i].first.second-a[floor].first.second));
    vis[floor][1]=1;
    dfs(tot+1,floor+1);
    vis[floor][1]=0;

    dis=tmp;
    dfs(tot,floor+1);
}
bool cmp(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y)
{return x.second>y.second;}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        ans[i]=INF,
        scanf("%d%d%lld",&a[i].first.first,&a[i].first.second,&a[i].second);
    for(int i=0;i<n;i++)
        dis[i]=min(abs(a[i].first.first),abs(a[i].first.second));
    dfs();
    for(int i=0;i<=n;i++)
        printf("%lld\n",ans[i]);
    //printf("%f\n",1.*clock()/CLOCKS_PER_SEC);
    return 0;
}
