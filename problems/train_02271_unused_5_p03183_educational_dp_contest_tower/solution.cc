#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,pii> box;
#define s first
#define w second.first
#define v second.second
#define maxn 1005
#define maxs 20005
int main()
{
	int n;
	scanf("%d",&n);
	box b[maxn];
	for(int i=0; i<n; i++){
		scanf("%d%d%d", &b[i].w, &b[i].s, &b[i].v);
		b[i].s += b[i].w;
	}
	sort(b,b+n);
	LL dp[maxs] = {};
	LL ans = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=b[i].s; j>=b[i].w; j--)
		{
			dp[j] = max(dp[j], dp[j-b[i].w]+b[i].v);
			ans = max(ans, dp[j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}