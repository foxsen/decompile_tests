#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007
using namespace std;
const int MAXN = 100005;
int fac[MAXN*2],inv[MAXN*2],n,m,a,b;
typedef long long ll;
inline int ksm(int x,int k)
{
	int ret=1;
	while(k){
		if(k&1)ret=(ll)ret*x%MOD;
		x=(ll)x*x%MOD;
		k>>=1;
	}
	return ret;
}
inline void init()
{
	fac[0]=1;
	for(int i=1;i<=m+n;++i)
		fac[i]=(ll)fac[i-1]*i%MOD;
	inv[m+n]=ksm(fac[m+n],MOD-2);
	inv[0]=1;
	for(int i=m+n-1;i;--i)
		inv[i]=(ll)inv[i+1]*(i+1)%MOD;
}
inline int C(int n,int m)
{
	return (ll)fac[m]*inv[m-n]%MOD*inv[n]%MOD;
}
inline void add(int &x,int a)
{
	x+=a;
	if(x>=MOD)x-=MOD;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	init();
	int ans=0;
	for(int i=1;i<=n-a;++i)
		add(ans,(ll)C(b-1,b-1+i-1)*C(n-i,n-i+m-b-1)%MOD);
	printf("%d\n",ans);
	return 0;
}
