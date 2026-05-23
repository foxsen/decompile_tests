#include<bits/stdc++.h>
using namespace std;

const int N=300100,M=20;

int a[N],dp[N],dq[N],b[M],V,n,le[M][N],ri[M][N],c[N];
int m;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>V;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(;V>>m;++m)b[m]=V>>m;
	for(int i=0;i<=m;++i){
		ri[i][n]=n;ri[i][n+1]=n+1;
		for(int j=n-1;j;--j)
			ri[i][j]=(a[j+1]-a[j]<=b[i]?ri[i][j+1]:j);
		le[i][0]=0;le[i][1]=1;
		for(int j=2;j<=n;++j)
			le[i][j]=(a[j]-a[j-1]<=b[i]?le[i][j-1]:j);
	}
	fill(dq,dq+N,n+1);
	for(int i=1;i<(1<<m);++i)
		for(int j=0;j<m;++j)
			if(i>>j&1){
				dp[i]=max(dp[i],ri[j+1][dp[i-(1<<j)]+1]);
				dq[i]=min(dq[i],le[j+1][dq[i-(1<<j)]-1]);
				dp[i]=min(dp[i],n);
				dq[i]=max(dq[i],1);
			}
	for(int i=0;i<(1<<m);++i){
		int l=dp[i]+1,r=dq[(1<<m)-1-i]-1;
		if(r<=ri[0][l]){
			if(l>r)++c[1];
			else ++c[l],--c[r+1];
		}
	}
	for(int i=1;i<=n;++i){
		c[i]+=c[i-1];
		cout<<(c[i]?"Possible\n":"Impossible\n");
	}
	return 0;
}
