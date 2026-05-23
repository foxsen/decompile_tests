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
const int mm=2e5+100;
ll d[mm],sum[mm];
map<ll,ll> name;
void dfs(ll l,ll r)
{
	 if(d[l]==d[r]) 
	 {
	 	ll s=sum[r]-sum[l-1]; name[s]=1;
	 	//cout<<s<<endl;
		  return ;
	 }
	 else
	 {
	 ll s=sum[r]-sum[l-1]; name[s]=1;
	 //cout<<s<<endl;
	 ll mm=(d[r]+d[l])/2;
	 ll p=1,pp=r; ll o=1;
	 while(p<=pp)
	 {
	 	ll mid=(p+pp)/2;
	 	if(d[mid]<=mm)
	 	{
	 	  p=mid+1; 
		  o=mid;	
		}
		else pp=mid-1;
	 }
	 dfs(l,o); dfs(o+1,r);
     }
}
int main()
{
   ll n,m,i,j,t,a,b,c,p,k,kk; 
	  scanf("%lld",&t);
	  while(t--)
	  {
	  	  scanf("%lld%lld",&n,&m);
	  	  for(i=1;i<=n;i++) scanf("%lld",&d[i]);
	  	  sort(d+1,d+1+n);
	  	  for(i=1;i<=n;i++) sum[i]=sum[i-1]+d[i];
	  	  name.clear();
	  	  dfs(1,n);
	  	  while(m--)
	  	  {
	  	  	 scanf("%lld",&a);
	  	  	 if(name[a]) printf("Yes\n");
	  	  	 else printf("No\n");
		  }
	  }
} 