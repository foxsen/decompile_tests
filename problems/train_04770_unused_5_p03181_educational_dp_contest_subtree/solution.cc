#include<cstdio>
#include<vector>
std::vector <int> ve[100050];
int m,n,ans[100050],pre[100050],suf[100050],dp[100050];
void dfs(int u,int fa){
	int lim=ve[u].size(),y;
	dp[u]=1;
	for (int i=0;i<lim;i++)if ((y=ve[u][i])!=fa){
		dfs(y,u);
		pre[y]=dp[u];
		dp[u]=(dp[y]+1)*1ll*dp[u]%m;
	}
	int k=1;
	for (int i=lim-1;i>=0;i--)if ((y=ve[u][i])!=fa){
		suf[y]=k;
		k=(dp[y]+1)*1ll*k%m;
	}
}
void get_ans(int u,int fa,int t){
	ans[u]=(t+1)*1ll*dp[u]%m;
	int lim=ve[u].size(),y;
	for (int i=0;i<lim;i++)if ((y=ve[u][i])!=fa)get_ans(y,u,(t+1)*1ll*pre[y]%m*suf[y]%m);
}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)scanf("%d%d",&u,&v),ve[u].push_back(v),ve[v].push_back(u);
	dfs(1,0);
	get_ans(1,0,0);
	for (int i=1;i<=n;i++)printf("%d\n",ans[i]);
}