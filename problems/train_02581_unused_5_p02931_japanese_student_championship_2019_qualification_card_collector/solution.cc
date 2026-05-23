#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int u;
	int v;
	ll w;
}a[200005];
int h,w,m,pa[200005];
ll ans;
bool pos[200005];
bool cmp(Edge a,Edge b)
{
	return a.w>b.w;
}
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main()
{
	scanf("%d%d%d",&m,&h,&w);
	for(int i=1;i<=h+w;i++)
	  pa[i]=i,pos[i]=1;
	for(int i=1;i<=m;i++)
	  scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=a[i].u,y=a[i].v+h;
		x=find(x),y=find(y);
		if(x!=y)
		{
			if(pos[x]&&pos[y])
			{
				pa[x]=y;
				ans+=a[i].w;
			}
			else if(pos[x]||pos[y])
			{
				pa[x]=y;
				pos[y]=0;
				ans+=a[i].w;
			}
		}
		else
		{
			if(pos[x])
			{
				ans+=a[i].w;
				pos[x]=0;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}