#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	ll x,y;
	bool operator<(const edge&z)const
	{
		return x>z.x||(x==z.x&&y<z.y);
	}
}h,v;
struct edge2
{
	ll x,y,z;
}e[400005];
ll n,i,x,y,z,tot=0,ev[3][400005],dsu[200005],dis[400005],pre[400005],ans=0,fx,fy;
const ll inf=1e18;
priority_queue<edge>q;
vector<edge>s[400005];
ll getf(ll p){return dsu[p]==p?p:dsu[p]=getf(dsu[p]);}
bool cmp(edge2 a,edge2 b)
{
	if(a.z!=b.z)return a.z<b.z;
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		q.push((edge){0,n+i});
		pre[i]=i;pre[n+i]=n+i;
		dis[i]=inf;dis[n+i]=0; 
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		s[i].push_back((edge){n+i,x});
		s[n+i].push_back((edge){i,x});
		ev[0][i]=i;ev[1][i]=n+i;ev[2][i]=x;
	}
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		s[x].push_back((edge){y,z});
		s[y].push_back((edge){x,z});
		ev[0][n+i]=x;ev[1][n+i]=y;ev[2][n+i]=z;
	}
	while(!q.empty())
	{
		h=q.top();
		q.pop();
		if(h.x>dis[h.y])continue;
		for(i=0;i<s[h.y].size();i++)
		{
			v=s[h.y][i];
			if(dis[v.x]>dis[h.y]+v.y)
			{
				dis[v.x]=dis[h.y]+v.y;
				pre[v.x]=pre[h.y];
				q.push((edge){dis[v.x],v.x});
			}
		}
	}
	for(i=1;i<=2*n-1;i++)e[i]=(edge2){pre[ev[0][i]]-n,pre[ev[1][i]]-n,ev[2][i]+dis[ev[0][i]]+dis[ev[1][i]]};
	sort(e+1,e+2*n,cmp);
	for(i=1;i<=2*n-1;i++)
	{
		fx=getf(e[i].x);fy=getf(e[i].y);
		if(fx==fy)continue;
		ans+=e[i].z;
		dsu[fx]=fy;
	}
	printf("%lld\n",ans);
	return 0; 
} 