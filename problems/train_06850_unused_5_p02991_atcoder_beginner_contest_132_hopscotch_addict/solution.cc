#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M (1000000007)
#define N (100010)
int n,m,f[N*10][3],dp[N][3];
vector<int>G[N];

int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
	}
	scanf("%d%d",&x,&y);
	f[1][0]=x; f[1][1]=0; f[1][2]=0;
	int l=0,r=1; memset(dp,0x7f7f,sizeof(dp));
	while (l<r){
		l++;
		if (f[l][0]==y&&f[l][1]==0){
			printf("%d",f[l][2]);
			return 0;
		}
		int now=f[l][0],cnt=f[l][2]+(f[l][1]+1)/3,t=(f[l][1]+1)%3;
		for (int i=0;i<G[now].size();i++){
			int nx=G[now][i];
			if (dp[nx][t]<=cnt) continue;
			dp[nx][t]=cnt;
			f[++r][0]=nx; f[r][1]=t; f[r][2]=cnt;
		}
	}
	printf("-1");
}
