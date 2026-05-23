#include<bits/stdc++.h>
using namespace std;

const int N=4000005;
const long long MOD=1e9+7;
int n,k;
long long f[N],inv[N],p[N],ans=1;
char ch[N];

long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b%2) res=res*a%MOD;
		a=a*a%MOD,b/=2;
	}
	return res;
}

int main()
{
	scanf("%d%s",&n,ch),f[0]=p[0]=1;
	k=strlen(ch),n+=k;
	for(int i=1;i<=n;i++) f[i]=f[i-1]*i%MOD;
	inv[n]=ksm(f[n],MOD-2);
//	cout<<inv[n]*f[n]%MOD<<endl;
	for(int i=n;i>=1;i--) inv[i-1]=inv[i]*i%MOD;
	for(int i=1;i<=n;i++) p[i]=p[i-1]*25%MOD,ans=ans*26%MOD;
	for(int i=0;i<k;i++)
	{
		ans=(ans-f[n]*inv[i]%MOD*inv[n-i]%MOD*p[n-i]%MOD+MOD)%MOD;
//		cout<<i<<' '<<f[n]*inv[i]%MOD*inv[n-i]%MOD<<' '<<inv[i]<<' '<<inv[i]*f[i]%MOD<<endl;
	}
	printf("%lld\n",ans);
}