#include<bits/stdc++.h>
using namespace std;
double ans=999999999;
double inf=999999999;
int n,m;
double dp[601];
vector<int>e[601];
void get_dp(int x)
{
	memset(dp,0,sizeof(dp));
	dp[n]=0;
	for(int i=n-1;i>=1;i--)
	{
		int tot=0;
		double mx=0;
		for(int j=0;j<e[i].size();j++)
			tot++,mx=max(mx,dp[e[i][j]]),dp[i]+=dp[e[i][j]];
		if(i==x)
		{
			if(tot==1)
				dp[i]=inf;
			else if(tot>=2)
				dp[i]-=mx,dp[i]/=tot-1,dp[i]++;
			else
				dp[i]=inf;
		}
		else if(tot)
			dp[i]/=tot,dp[i]++;
		else
			dp[i]=inf;
	}
	ans=min(ans,dp[1]);
}
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>v) swap(u,v);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		get_dp(i);
	printf("%lf",ans);
	return 0;
}
/*
5 5
1 2
1 3
2 3
3 5
2 5
*/