#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
const int maxn=1e6+10;
int n,p;
long long ans,dp[10][maxn];
char s[maxn];
map<int,int>num;
int main()
{
	scanf("%d%d%s",&n,&p,s+1);
	if (p==2)
	{
		for (int i=1;i<=n;i++) if ((s[i]-'0')%2==0) ans+=i;
		printf("%lld\n",ans);
	}
	else if (p==5)
	{
		for (int i=1;i<=n;i++) if ((s[i]-'0')%5==0) ans+=i;
		printf("%lld\n",ans);
	}
	else 
	{
		int now=0,mi=1; num[0]=1;
		for (int i=n;i>=1;i--)
		{
			now=(now+(s[i]-'0')*mi%p)%p;
			ans+=num[now]; num[now]++; mi=mi*10%p;
		}
		printf("%lld\n",ans);
	}
return 0;
}