#include<bits/stdc++.h>
typedef long long ll;
const int maxn=1e5+9;
using namespace std;
int main()
{
	ll n,m,v,p,i,a[maxn]={0},ans=0;
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ans=p;
	v-=(p-1);
	ll sum=a[n-p+1],b=a[n-p+1];
	for(i=n-p;i>=1;i--)
	{
		if(v-i<=0)
		{
			if(a[i]+m>=b)ans++;
		}
		else
		{
			if(sum+(v-i)*m<=(n-p+1-i)*(a[i]+m)&&b<=a[i]+m)ans++;
		}
		sum+=a[i];
	}
	printf("%lld\n",ans);
}