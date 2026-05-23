#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<map>
typedef long long int ll;
using namespace std;
#define maxn 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
const int mm=3e5+100;
ll d[mm],num[mm]; 
int main()
{
   ll n,m,i,j,t,a,b,c,p,k,kk; 
	  scanf("%lld",&t);
	  while(t--)
	  {
	     scanf("%lld",&n);
	     for(i=1;i<=n;i++) scanf("%lld",&d[i]);
		 ll sum1=0;
		 for(i=2;i<=n-1;i++)
		 {
		 	 if(d[i]<d[i-1]&&d[i]<d[i+1])
	     	 {
	     	  sum1++;
			 }
			 else if(d[i]>d[i-1]&&d[i]>d[i+1])
	     	 {
	     	   sum1++;
			 }
		 }
		 k=0;
		 ll s;
		 for(i=2;i<=n-1;i++)
		 {
		 	 s=0;
		 	 if(d[i-1]>d[i]&&d[i]<d[i+1]||d[i-1]<d[i]&&d[i]>d[i+1]) s++;
		 	 if(i>=3&&(d[i]>d[i-1]&&d[i-1]<d[i-2]||d[i]<d[i-1]&&d[i-1]>d[i-2])) s++;
		 	 if(i<=n-2&&(d[i]>d[i+1]&&d[i+1]<d[i+2]||d[i]<d[i+1]&&d[i+1]>d[i+2])) s++;
			 {
		 	     p=d[i]; d[i]=d[i-1];	ll sum=0;
		 	     if(d[i-1]>d[i]&&d[i]<d[i+1]||d[i-1]<d[i]&&d[i]>d[i+1]) sum++;
		 	     if(i>=3&&(d[i]>d[i-1]&&d[i-1]<d[i-2]||d[i]<d[i-1]&&d[i-1]>d[i-2])) sum++;
		 	     if(i<=n-2&&(d[i]>d[i+1]&&d[i+1]<d[i+2]||d[i]<d[i+1]&&d[i+1]>d[i+2])) sum++;
		 	     k=max(k,s-sum);
		 	     d[i]=p;
			 }
			 {
		 	     p=d[i]; d[i]=d[i+1];	ll sum=0;
		 	     if(d[i-1]>d[i]&&d[i]<d[i+1]||d[i-1]<d[i]&&d[i]>d[i+1]) sum++;
		 	     if(i>=3&&(d[i]>d[i-1]&&d[i-1]<d[i-2]||d[i]<d[i-1]&&d[i-1]>d[i-2])) sum++;
		 	     if(i<=n-2&&(d[i]>d[i+1]&&d[i+1]<d[i+2]||d[i]<d[i+1]&&d[i+1]>d[i+2])) sum++;
		 	     k=max(k,s-sum);
		 	     d[i]=p;
			 }
		 }
		// cout<<sum1<<' '<<k<<endl;
		 printf("%lld\n",sum1-k);
	  } 
} 