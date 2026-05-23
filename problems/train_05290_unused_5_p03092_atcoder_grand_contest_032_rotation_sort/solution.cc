#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,A,B,j,ans,f[5010][5010],a[5010];
int main(){
	scanf("%lld%lld%lld",&n,&A,&B);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	memset(f,44,sizeof(f));
	f[0][0]=0;
	for(i=1;i<=n;i++){
		for(j=0;j<=n;j++){
			if(a[i]>j)f[i][a[i]]=min(f[i][a[i]],f[i-1][j]),f[i][j]=min(f[i][j],f[i-1][j]+A);
			 else f[i][j]=min(f[i][j],f[i-1][j]+B);
		}
	}
	ans=1e18;
	for(i=1;i<=n;i++)ans=min(ans,f[n][i]);
	printf("%lld",ans);
}
/*
枚举不动的数就行了 
*/