#include <bits/stdc++.h>
#define N 100010
using namespace std;
int sum[N],ans,n;
int main()
{
	scanf ("%d",&n);
	for (int i=1,a;i<=n;i++) scanf("%d",&a),sum[a]++;
	for (int i=1;i<=100000;i++) ans=max(ans,sum[i]+sum[i-1]+sum[i+1]);
	printf("%d\n",ans);
	return 0;
}