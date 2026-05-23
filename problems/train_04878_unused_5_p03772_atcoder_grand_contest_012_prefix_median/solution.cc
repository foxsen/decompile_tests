#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char ch=getchar();long long x=0,ff=1;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*ff;
}
void write(long long aa)
{
	if(aa<0) putchar('-'),aa=-aa;
	if(aa>9) write(aa/10);
	putchar('0'+aa%10);
	return;
}
const long long mod=1e9+7;
long long n,ans;
long long a[105],f[55][105][105],vis[105];
int main()
{
	n=read();
	for(long long i=1;i<=2*n-1;++i) a[i]=read();
	sort(a+1,a+2*n);
	for(int i=n-1;i;--i) if(a[i+1]==a[i]) vis[i]=1;
	for(int i=n+1;i<2*n;++i) if(a[i-1]==a[i]) vis[i]=1;
	f[1][1][0]=1;
	for(long long i=2;i<=n;++i) 
	{
		for(long long l=0;l<=2*n-1;++l)
		for(long long r=0;r<=2*n-1;++r) if(f[i-1][l][r])
		{
			int L=l+1-vis[n-i+1],R=r+1-vis[n+i-1];
			for(int k=1;k<=L+R;++k)
			{
				if(k<L) (f[i][k][R+1]+=f[i-1][l][r])%=mod;
				else if(k==L) (f[i][k][R]+=f[i-1][l][r])%=mod;
				else (f[i][L+1][R-k+L]+=f[i-1][l][r])%=mod;
			}
		}
	}
	for(long long i=0;i<=n*2-1;++i)
	for(long long j=0;j<=n*2-1;++j) (ans+=f[n][i][j])%=mod;
	write(ans);
	return 0;
}