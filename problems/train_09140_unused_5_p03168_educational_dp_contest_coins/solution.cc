#include <stdio.h>

const int MAX_N = 3005;

typedef long double real;

int n;
real p[MAX_N],dp[MAX_N][MAX_N];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%Lf",p+i);
	dp[0][0]=1;
	for (int i=1; i<=n; i++)
	{
		dp[i][0]=(1-p[i])*dp[i-1][0];
		for (int h=1; h<=i; h++)
			dp[i][h]=p[i]*dp[i-1][h-1]+(1-p[i])*dp[i-1][h];
	}
	real ans=0;
	for (int h=n; h>n-h; h--)
		ans+=dp[n][h];
	printf("%.10Lf\n",ans);
	return 0;
}
