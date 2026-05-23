#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

#define LL long long

const int N=200,_N=N+33;

const int MOD=1000000007;

int n,m,k;

int fir[_N],nxt[_N],to[_N],tote=1;

int C[_N][_N];

void prework()
{
	for(int i=0,j;i<=N;++i)
	{
		for(C[i][0]=1,j=1;j<=i;++j)
			if((C[i][j]=C[i-1][j-1]+C[i-1][j])>=MOD)
				C[i][j]-=MOD;
	}
}

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}

int quickpow(int x,int y)
{
	int res=1;
	for(;y;y>>=1,x=(LL)x*x%MOD)if(y&1)
		res=(LL)res*x%MOD;
	return res;
}

int ny(int x)
{
	return quickpow(x,MOD-2);
}

int polya(int n,int k)
{
	if(n==0)
		return 1;
	int res=0;
	for(int i=0;i<n;++i)
		if((res+=quickpow(k,gcd(i,n))%MOD)>=MOD)
			res-=MOD;
	return (LL)res*ny(n)%MOD;
}

int low[_N],dfn[_N],dfstime,stk[_N],tp;

int col[_N],totc,lst[_N],ed;

int ans=1;

void dfs(int u,int fa)
{
	dfn[u]=low[u]=++dfstime;stk[++tp]=u;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
	{
		if(dfn[v])
			low[u]=min(low[u],dfn[v]);
		else
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				int o,cnt_e=0;
				ed=0;
				++totc;
				do
					col[lst[++ed]=o=stk[tp--]]=totc;
				while(o!=v);
				if(col[u]!=totc)
					col[lst[++ed]=u]=totc;
				for(int j=1;j<=ed;++j)
					for(int k=fir[lst[j]];k;k=nxt[k])
						cnt_e+=(col[to[k]]==totc);
				cnt_e>>=1;
				if(ed==1)
					ans=(LL)ans*k%MOD;
				else if(ed==cnt_e)
					ans=(LL)ans*polya(cnt_e,k)%MOD;
				else
					ans=(LL)ans*C[cnt_e+k-1][cnt_e]%MOD;
			}
		}
	}
	if(!fa)
		--tp;
}

int main()
{
	//freopen("sample","r",stdin);
	prework();
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		to[++tote]=v;nxt[tote]=fir[u];fir[u]=tote;
		to[++tote]=u;nxt[tote]=fir[v];fir[v]=tote;
	}
	for(int i=1;i<=n;++i)if(!dfn[i])
		dfs(i,0);
	printf("%d\n",ans);
	return 0;
}
