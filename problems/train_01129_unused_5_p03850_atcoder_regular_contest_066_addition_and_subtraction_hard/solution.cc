#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
long long f[N][3];
int main()
{
	int n; scanf("%d%d",&n,&a[1]);
	for(int i=2;i<=n;++i)
	{
		char op[2];
		scanf("%s%d",op,&a[i]);
		a[i]=(op[0]=='+'?a[i]:-a[i]);
	}
	f[1][0]=a[1],f[1][1]=f[1][2]=-1ll<<60;
	for(int i=2;i<=n;++i)
	{
		f[i][0]=max(f[i-1][0],max(f[i-1][1],f[i-1][2]))+a[i];
		f[i][1]=max(f[i-1][1],f[i-1][2])-a[i];
		f[i][2]=f[i-1][2]+a[i];
		if(a[i]<0)
		{
			f[i][1]=max(f[i][1],f[i-1][0]+a[i]);
			f[i][1]=max(f[i][1],f[i-1][1]+a[i]);
			f[i][1]=max(f[i][1],f[i-1][2]+a[i]);
			f[i][2]=max(f[i][2],f[i-1][1]-a[i]);
			f[i][2]=max(f[i][2],f[i-1][2]-a[i]);
		}
	}
		printf("%lld",max(f[n][0],max(f[n][1],f[n][2])));
}