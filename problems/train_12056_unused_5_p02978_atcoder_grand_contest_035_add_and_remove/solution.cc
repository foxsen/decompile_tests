#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
#define N 200012
typedef long long ll;
struct node{ll x,y;friend bool operator<(node a,node b){return (a.x^b.x)?a.x<b.x:a.y<b.y;}};
int n,a[N];
map<node,ll>dp[22][22];
ll cal(int l,int r,ll x,ll y)
{if(l==r-1)return 0;if(dp[l][r].count((node){x,y}))return dp[l][r][(node){x,y}];
	ll ret=4e18;
	for(int i=l+1;i<r;i++)
	{
		ret=min(ret,cal(l,i,x,x+y)+cal(i,r,x+y,y)+1ll*(x+y)*a[i]);
	}return dp[l][r][(node){x,y}]=ret;
}
int main()
{
    scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	printf("%lld\n",cal(1,n,1,1)+a[1]+a[n]);
}
