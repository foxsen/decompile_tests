#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX_N 300005
#define MOD 998244353
#define int long long

using namespace std;

int n,a,b,K,ans=0;
int f[MAX_N];
int inf[MAX_N];

void exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}

int inv(int a)
{
	int x,y;
	exgcd(a,MOD,x,y);
	return (x%MOD+MOD)%MOD;
}

int c(int n,int m)
{
	return f[n]*inf[m]%MOD*inf[n-m]%MOD;
}

signed main()
{
	scanf("%lld%lld%lld%lld",&n,&a,&b,&K);
	f[0]=1;
	for(int i=1;i<=n;i++) f[i]=f[i-1]*i%MOD;
	inf[n]=inv(f[n]),inf[0]=1;
	for(int i=n-1;i>=1;i--) inf[i]=inf[i+1]*(i+1)%MOD;
	for(int i=0;i<=n;i++)
	{
		if(!((K-a*i)%b))
		{
			int j=(K-a*i)/b;
			if(0<=j && j<=n) ans=(ans+c(n,i)*c(n,j)%MOD)%MOD;
		}
	}
	printf("%lld\n",ans);
}
