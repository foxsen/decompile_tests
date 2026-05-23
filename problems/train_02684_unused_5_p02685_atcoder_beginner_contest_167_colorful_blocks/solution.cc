#include<iostream>
using namespace std;
const long mod=998244353;
long power(long a,long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
long fac[2<<17],inv[2<<17];
int N,M,K;
int main()
{
	fac[0]=1;
	for(int i=1;i<2<<17;i++)fac[i]=fac[i-1]*i%mod;
	inv[(2<<17)-1]=power(fac[(2<<17)-1],mod-2);
	for(int i=(2<<17)-1;i--;)inv[i]=inv[i+1]*(i+1)%mod;
	cin>>N>>M>>K;
	long ans=power(M,N);
	for(int L=K+1;L<N;L++)
	{
		ans-=fac[N-1]*inv[N-1-L]%mod*inv[L]%mod*M%mod*power(M-1,N-L-1)%mod;
	}
	cout<<(ans%mod+mod)%mod<<endl;
}
