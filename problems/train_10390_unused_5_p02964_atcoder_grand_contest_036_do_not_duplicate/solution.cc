#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
int a[N],b[N],h[N],to[N];
int n,w;
ll K;
void solve(int p,int s)
{
	memset(b,0,sizeof(b));
	for(int i = 1;i <= s;i ++)
	{
		if(!b[a[p]])
			h[++ w] = a[p],b[a[p]] = 1;
		else
		{
			while(h[w] != a[p])
				b[h[w]] = 0,w --;
			b[h[w]] = 0;w --;
		}
		p = p%n+1;
	}
	for(int i = 1;i <= w;i ++)
		printf("%d ",h[i]);
}
void solve2(int p,ll s)
{
	while(to[p]-p+1 <= s)
	{
		s -= to[p]-p+1;
		p = to[p]%n+1;
	}
	solve(p,s);
}
int main()
{
	scanf("%d%lld",&n,&K);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	for(int i = n;i >= 1;i --)
		b[a[i]] = i+n;
	for(int i = n;i >= 1;i --)
		to[i] = b[a[i]],b[a[i]] = i;
	memset(b,0,sizeof(b));
	int p = 1;ll s = 0,sc = 0;
	while(!b[p])
	{
		b[p] = 1;
		s += to[p]-p+1;
		p = to[p]%n+1;
	}
	int q = p;
	while(true)
	{
		sc += to[q]-q+1;
		q = to[q]%n+1;
		if(q == p)
			break;
	}
	if(n*K <= s)
		solve(1,n*K);
	else
		solve2(p,(n*K-s)%sc);
    return 0;
}