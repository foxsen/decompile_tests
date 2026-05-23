#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=310,mod=998244353;
int n,f[N][N][N],g[N][N][N],C[N*2][N*2];
char s[N];
void add(int &x,int y){x+=y;x>=mod?x-=mod:0;}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%s",s);n=strlen(s);
	g[n][0][0]=1;
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n*2;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)g[n][i][j]=C[i+j][i];
	for(int i=n-1;~i;i--)for(int j=0;j<=i;j++)for(int k=0;k<=i;k++){
		g[i][j][k]=g[i+1][j][k];
		if(s[i]=='0'&&k)add(g[i][j][k],g[i][j][k-1]);
		if(s[i]=='1'&&j)add(g[i][j][k],g[i][j-1][k]);
	}
	f[0][0][0]=1;
	for(int i=0;i<=n;i++)for(int j=i;~j;j--)for(int k=i;~k;k--){
		if(j&&j+k>=2)f[i][j-1][k]|=f[i][j][k];
		if(k&&j+k>=2)f[i][j][k-1]|=f[i][j][k];
		if(i<n){if(j&&s[i]=='1')f[i+1][j-1][k+1]|=f[i][j][k];
			if(k&&s[i]=='0')f[i+1][j+1][k-1]|=f[i][j][k];
			if(j+k)f[i+1][j][k]|=f[i][j][k];
		}
		if(i+2<=n){
			if(s[i]=='0'||s[i+1]=='0') f[i+2][j+1][k]|=f[i][j][k];
			if(s[i]=='1'||s[i+1]=='1') f[i+2][j][k+1]|=f[i][j][k];
		}
	}
	int ans=0;
	for(int i=n;~i;i--)
		for(int j=i;~j;j--) {
			for(int k=i;~k;k--) {
//				printf("%d %d %d : %d %d\n", i, j, k, f[i][j][k], dp[i][j][k]);
				if( !f[i][j][k] ) continue;
				add(ans,g[i][j][k]);
				int cnt[2] = {};
				for(int l=i-1;l>=0;l--) {
					cnt[s[l]-'0']++;if(j<cnt[0]||k<cnt[1])break;
					f[l][j-cnt[0]][k-cnt[1]]=0;
				}
			}
	}
	printf("%d\n", ans);
}