#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int N=305;

int n,m;
int dp[N][N][N];
char s[N];

int main(){
	int l,r,k,d,i;
	scanf("%s",s+1); n=strlen(s+1);
	scanf("%d",&m);
	for (i=1;i<=n;i++)
		for (k=0;k<=m;k++) dp[i][i][k]=1;
	for (d=2;d<=n;d++){
		for (l=1;l+d-1<=n;l++){
			r=l+d-1;
			for (k=0;k<=m;k++){
				if (k) dp[l][r][k]=max(dp[l][r][k],dp[l][r][k-1]);
				dp[l][r][k]=max(dp[l][r][k],dp[l+1][r][k]);
				dp[l][r][k]=max(dp[l][r][k],dp[l][r-1][k]);
				if (s[l]==s[r]) dp[l][r][k]=max(dp[l][r][k],dp[l+1][r-1][k]+2);
				if (k) dp[l][r][k]=max(dp[l][r][k],dp[l+1][r-1][k-1]+2);
			}
		}
	}
	printf("%d\n",dp[1][n][m]);
	return 0;
}