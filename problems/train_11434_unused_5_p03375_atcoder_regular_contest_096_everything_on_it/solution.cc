#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=3005;
typedef long long ll;

int power_mod(int a,int b,ll mod) 
{
	int ans=1;
	while (b) 
	{
		if (b&1) ans=(ll)ans*a%mod;
		b>>=1;
		a=(ll)a*a%mod;
	}
	return ans;
}


int n;
ll mod;
int C[N][N],S[N][N],p2[N*N];

int main()
{
	scanf("%d%lld",&n,&mod);
	C[0][0]=S[0][0]=1;
	for (int i=1;i<=n+1;i++)
	{
		S[i][0]=C[i][0]=1;
		for (int j=1;j<=i;j++) 
		{
			C[i][j]=C[i-1][j]+C[i-1][j-1];if (C[i][j]>=mod) C[i][j]-=mod;
			S[i][j]=((ll)S[i-1][j]*(j+1)+S[i-1][j-1])%mod;
		}
	}
	p2[0]=1;
	for (int i=1;i<=n*n;i++) 
	{
		p2[i]=p2[i-1]+p2[i-1];
		if (p2[i]>=mod) p2[i]-=mod;
	}
	int ans=0,tmp=0,t=1;
	for (int i=0;i<=n;i++,t=mod-t) 
	{
		tmp=0;
		for (int j=0;j<=i;j++) tmp=((ll)S[i][j] * p2[(n-i)*j]%mod+ tmp)%mod;
		tmp=(ll)tmp*power_mod( 2,power_mod(2,n-i,mod-1) ,mod)%mod;
		ans=((ll)t*C[n][i]%mod*tmp+ans)%mod;
	}
	printf("%d\n",ans);
	return 0;
}