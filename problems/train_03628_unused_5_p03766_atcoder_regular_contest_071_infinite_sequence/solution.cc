#include<cstdio>
const int N=1000005,P=1000000007;
int n,f[N];
int main()
{
	scanf("%d",&n);
	f[1]=n;
	f[2]=1ll*n*n%P;
	int sum=0;
	for(int i=3;i<=n;i++)
	{
		sum=(sum+f[i-3])%P;
		f[i]=(f[i-1]+(n-1ll)*(n-1ll)+(n-i+2)+sum)%P;
	}
	printf("%d\n",f[n]);
	return 0;
}
