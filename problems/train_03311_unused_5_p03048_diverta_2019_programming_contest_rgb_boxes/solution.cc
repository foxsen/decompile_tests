#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,r,g,b;
long long ans;
int main()
{
	scanf("%d%d%d%d",&r,&g,&b,&n);
	for(int i=0;i<=n/r;i++)
	{
		for(int j=0;j<=(n-r*i)/g;j++)
		{
			if(((n-i*r-j*g)%b==0)) ans++;
		}
	}
	printf("%lld",ans);
}