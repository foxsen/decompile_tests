#include <bits/stdc++.h>
using namespace std;
const int maxn=405,INF=1e9;
int dp[maxn+100][maxn+100]; // i个a j个b最小的消耗
int a[maxn],b[maxn],c[maxn];
int main() {
	int n,A,B;
	cin>>n>>A>>B;
	for(int i=1; i<=n; i++)
		cin>>a[i]>>b[i]>>c[i];
	for(int i=0; i<=400; i++)
		for(int j=0; j<=400; j++)
			dp[i][j]=INF;
	dp[0][0]=0;
	for(int x=1; x<=n; x++) {
		for(int i=400; i>=0; i--)
			for(int j=400; j>=0; j--)
				if(dp[i][j]!=INF)
					dp[i+a[x]][j+b[x]]=min(dp[i+a[x]][j+b[x]],dp[i][j]+c[x]);
	}
	int ans=INF;
	for(int i=1; i<=400; i++) {
		for(int j=1; j<=400; j++)
			if(dp[i][j]!=INF && i*B==A*j)
				ans=min(ans,dp[i][j]);
	}
	printf("%d\n",ans==INF?-1:ans);
	return 0;
}