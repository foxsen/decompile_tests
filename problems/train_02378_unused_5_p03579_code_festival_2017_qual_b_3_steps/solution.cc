#include<iostream>
#include<cstdio>
#include<cstring>
typedef long ll;
const int MAXN=1e5+5;

int N,M;

struct E{int next,to;} e[MAXN<<1];int ecnt,G[MAXN];
void addEdge(int u,int v){e[++ecnt]=(E){G[u],v};G[u]=ecnt;}
void addEdge2(int u,int v){addEdge(u,v);addEdge(v,u);}

int clr[MAXN];
bool dfs(int u)
{
	for(int i=G[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(~clr[v])
		{
			if(clr[v]==clr[u]) return false;
			else continue;
		}
		clr[v]=clr[u]^1;
		if(!dfs(v)) return false;
	}
	return true;
}

int main()
{
	int i;
	scanf("%d%d",&N,&M);
	for(i=1;i<=M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		addEdge2(u,v);
	}
	memset(clr,-1,sizeof(clr));
	clr[1]=0;
	ll cnt=0;
	if(dfs(1))
	{
		for(i=1;i<=N;i++) if(clr[i]) cnt++;
		cnt=(ll)cnt*(N-cnt);
	}else cnt=(ll)N*(N-1)/2;
	std::cout<<cnt-M;
	return 0;
}