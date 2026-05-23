#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int p=998244353;
int n,m,mx,i,j,k,l,val,ans,f[302][302][302],a[302],b[302],sum,sz;
char s[10010];
int main(){
	scanf("%s",s+1);
	scanf("%d",&mx);
	n=strlen(s+1);
	for(i=1;i<=n;i++){
		if(s[i]=='1')sz++,sum++;
		 else{
		 	a[++m]=sz;sz=0;
		 }
	}
	f[0][0][0]=1;
	for(i=1;i<=m;i++){
		b[i]=a[i];
		a[i]+=a[i-1];
		for(j=a[i-1];j<=sum;j++)
		 for(k=0;k<=min(j,mx);k++)if(f[i-1][j][k])
		  for(l=max(0,a[i]-j);l<=sum-j;l++){
		  	val=max(0,l-b[i]);
		  	if(k+val<=mx)(f[i][j+l][k+val]+=f[i-1][j][k])%=p;
		  }
	}
	for(j=a[m];j<=sum;j++)
	for(k=0;k<=min(mx,sum);k++)ans=(ans+f[m][j][k])%p;
	printf("%d",ans);
}