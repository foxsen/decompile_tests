#include <bits/stdc++.h>
using namespace std;
const int maxn=2000005;
const int mod = 998244353;
int n, m;
long long fact[maxn],inv[maxn];
long long r(int x, int p)
{
	long long ret=1,w=x;
	while(p)
	{
		if(p&1) 
		  ret=ret*w%mod;
		w=w*w%mod;
		p>>=1;
	}
	return ret;
}
long long b(int x, int y)
{
	return fact[x]*(inv[y]*inv[x-y]%mod)%mod;
}
int f(int n,int odd,int sum)
{
	long long ret=0;
	for(int i=0;i<=odd&&i<=sum&&i<=n;i++)
	{
		if(sum%2==i%2)
		{
			ret+=b((sum-i)/2+n-1,n-1)*b(n,i)%mod;
		}
	}
	return ret%mod;
}
long long g(int n,int sum)
{
	return b(sum+n-1,n-1);
}
int main()
{
	fact[0]=inv[0]=1;
	for(int i=1;i<maxn;i++)
	{
		fact[i]=fact[i-1]*i%mod;
		inv[i]=r(fact[i],mod-2);
	}
	cin>>n>>m;
	long long ret=f(n,m,3*m);
	for(int i=2*m+1;i<=3*m;i++)
	{
		ret+=mod-n*g(n-1,3*m-i)%mod;
	}
	cout<<ret%mod<<endl;
	return 0;
}