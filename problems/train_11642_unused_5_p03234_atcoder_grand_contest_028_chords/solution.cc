using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 610
#define ll long long
#define mo 1000000007
int n,K;
int to[N],c[N];
bool bz[N][N];
int f[N][N],g[N];
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=K;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		if (a>b) swap(a,b);
		to[a]=b,to[b]=a;
		for (int i=a+1;i<=b;++i)
			for (int j=b;j<=2*n;++j)
				bz[i][j]=1;
		for (int j=a;j<=b-1;++j)
			for (int i=1;i<=a;++i)
				bz[i][j]=1;
	}
	for (int i=1;i<=2*n;++i)
		c[i]=c[i-1]+(to[i]==0);
	g[0]=1;
	for (int i=2;i<=2*n;i+=2)
		g[i]=(ll)g[i-2]*(i-1)%mo;
	for (int l=2*n;l>=1;--l){
		for (int r=l+1;r<=2*n;r+=2){
			if (bz[l][r]) continue;
			ll s=0;
			for (int i=l+1;i<r;i+=2)
				(s+=(ll)f[l][i]*g[c[r]-c[i]])%=mo;
			f[l][r]=(g[c[r]-c[l-1]]-s+mo)%mo;
		}
	}
	ll ans=0;
	for (int i=1;i<=2*n;++i)
		for (int j=i+1;j<=2*n;j+=2)
			if (f[i][j])
			(ans+=(ll)f[i][j]*g[c[2*n]-(c[j]-c[i-1])])%=mo;
	printf("%lld\n",ans);
	return 0;
}












