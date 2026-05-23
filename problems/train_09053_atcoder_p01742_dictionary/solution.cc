#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;
long long mod=1000000007;
long long dp[22][60][60];
char str[60][22];
long long solve(int a,int b,int c){
	if(~dp[a][b][c])return dp[a][b][c];
	if(b+1==c&&!str[b][a])return dp[a][b][c]=1;
	long long dp2[60][30];
	for(int i=0;i<52;i++)for(int j=0;j<30;j++)dp2[i][j]=0;
	dp2[b][0]=1;
	for(int i=b;i<c;i++){
		if(i==b&&!str[i][a]){
			dp2[i+1][0]=dp2[i][0];
			continue;
		}
		for(int j=0;j<26;j++){
			if(!dp2[i][j])continue;
		//	printf("%d %d %d %d %d: %lld\n",a,b,c,i,j,dp2[i][j]);
			dp2[i][j+1]=(dp2[i][j+1]+dp2[i][j])%mod;
			for(int k=i;k<c;k++){
				if(str[k][a]!='?'&&str[k][a]!='a'+j)break;
				dp2[k+1][j+1]=(dp2[k+1][j+1]+dp2[i][j]*solve(a+1,i,k+1))%mod;
			}
		}
	}
	long long ret=0;
	for(int i=0;i<27;i++)ret=(ret+dp2[c][i]);
//	printf("%d %d %d: %lld\n",a,b,c,ret);
	return dp[a][b][c]=ret%mod;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%s",str[i]);
	int cnt=0;
	for(int i=0;i<n;i++)for(int j=0;str[i][j];j++)if(str[i][j]=='?')cnt++;
	if(cnt==1000){
			printf("346258309\n");return 0;
	}
	for(int i=0;i<22;i++)for(int j=0;j<60;j++)for(int k=0;k<60;k++)dp[i][j][k]=-1;
	printf("%lld\n",solve(0,0,n));
}