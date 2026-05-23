#include<stdio.h>
#define mod 1000000007
int n,a[2001];
int main()
{
	scanf("%d",&n);
	if(n<3){puts("0");return 0;}
	a[0]=1;
	for(register int i=3;i<=n;++i)
		for(register int j=3;j<=i;++j)a[i]=(a[i]+a[i-j])%mod;
	printf("%d",a[n]);
}