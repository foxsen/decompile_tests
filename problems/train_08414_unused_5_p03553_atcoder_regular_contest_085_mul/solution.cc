#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e13
using namespace std;

const int maxn = 210;
const int maxm = 110000;

int n,st,ed;
int s[maxn];

struct edge{int y,nex;ll c;}a[maxm]; int len,fir[maxn];
inline void ins(const int x,const int y,const ll c)
{
	a[++len]=(edge){y,fir[x],c};fir[x]=len;
	a[++len]=(edge){x,fir[y],0};fir[y]=len;
}

queue<int>q;
int h[maxn];
bool bfs()
{
	for(int i=1;i<=ed;i++) h[i]=0;
	h[st]=1; q.push(st);
	while(!q.empty())
	{
		const int x=q.front(); q.pop();
		for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(a[k].c&&!h[y])
			h[y]=h[x]+1,q.push(y);
	}
	return h[ed]>0;
}
ll dfs(const int x,const ll flow)
{
	if(x==ed) return flow;
	ll delta=0;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(a[k].c&&h[y]==h[x]+1)
	{
		ll mink=dfs(y,min(a[k].c,flow-delta));
		a[k].c-=mink; a[k^1].c+=mink;
		delta+=mink;
		if(delta==flow) return delta;
	}
	if(!delta) h[x]=0;
	return delta;
}
ll flow()
{
	ll re=0;
	while(bfs()) 
		re+=dfs(st,LLONG_MAX);
	return re;
}

ll re;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&s[i]);
		if(s[i]>0) re+=(ll)s[i];
	}
	len=1; //
	st=n+1,ed=st+1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>0) ins(i,ed,(ll)s[i]);
		if(s[i]<0) ins(st,i,(ll)-s[i]);
		for(int j=i+i;j<=n;j+=i) ins(i,j,inf);
	}
	printf("%lld\n",re-flow());
	
	return 0;
}
