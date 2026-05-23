#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20;

int n,m,u,v,ans;
bool vis[N];
vector <int> adj[N];

void dfs(int node)
{
	vis[node]=true;
	for(auto child:adj[node])
		if(not vis[child]) dfs(child);
}

int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1;i<=n;i++)
		if(not vis[i]) dfs(i),ans++;
	printf("%d",ans-1);
}