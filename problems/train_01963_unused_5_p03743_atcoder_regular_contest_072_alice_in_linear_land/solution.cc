#include <bits/stdc++.h>
#define yabs(x) ((x<0)?(-(x)):(x))

using namespace std;

const int N=5e5+10,Inf=1e9+10;

int n,D,Q,a[N],now[N],suf[N];

void Init()
{
	scanf("%d%d",&n,&D);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
}

void Solve()
{
	now[0]=D;
	for (int i=1;i<=n;++i) now[i]=min(now[i-1],yabs(now[i-1]-a[i]));
	suf[n+1]=1;
	for (int i=n;i>=1;--i)
		if (yabs(suf[i+1]-a[i])>=suf[i+1]) suf[i]=suf[i+1];
		else suf[i]=min(suf[i+1]+a[i],Inf);
	
	scanf("%d",&Q);int x;
	for (int i=1;i<=Q;++i)
	{
		scanf("%d",&x);
		if (suf[x+1]>now[x-1]) printf("NO\n");
		else printf("YES\n");	
	}
}

int main()
{
	Init();
	Solve();
	return 0;
}