#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

char s[5000][5000];
int dp[5000][2][2];
int n,m;

int solve(int x,int y){
	memset(dp,0,sizeof(dp));
	for(int i=y;i<m;i++){
		int j=x-(i-y);
		if(j<0)break;
		rep(k,2)rep(l,2){
			if(j+2<n&&s[j][i]=='R'&&s[j+1][i]=='G'&&s[j+2][i]=='W'&&!k&&!l){
				dp[i+1][0][0]=max(dp[i+1][0][0],dp[i][k][l]+1);
			}
			if(i+2<m&&s[j][i]=='R'&&s[j][i+1]=='G'&&s[j][i+2]=='W'){
				dp[i+1][l][1]=max(dp[i+1][l][1],dp[i][k][l]+1);
			}
			dp[i+1][l][0]=max(dp[i+1][l][0],dp[i][k][l]);
		}
	}
	int Max=0;
	rep(i,m+1)rep(j,2)rep(k,2)Max=max(Max,dp[i][j][k]);
	return Max;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%s",s[i]);
	int ans=0;
	rep(i,n-1)ans+=solve(i,0);
	rep(i,m)ans+=solve(n-1,i);
	cout<<ans<<endl;
}
