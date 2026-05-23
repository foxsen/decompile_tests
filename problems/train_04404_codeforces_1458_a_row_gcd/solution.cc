#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int m,n;

long long a[200009],b[200009];

long long gcd(long long x,long long y)
{
	if(y==0)
	{
		return x;
	}
	else
	{
		return gcd(y,x%y);
	}
}



int main()
{
//	a[0]=1000000000000000000-20;
//	a[0]-=20;
//	printf("%lld",llabs(-a[0]));
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	
	long long ans=0;
	sort(a,a+n);
	
	for(i=1;i<n;i++)
	{
		
		a[i]=a[i]-a[0];
	
		ans=gcd(a[i],ans);
	}
	while(m--)
	{
		long long x;
		scanf("%lld",&x);
		printf("%lld ",gcd(a[0]+x,ans));
	}
 } 
				 		    	   							 		 	 		