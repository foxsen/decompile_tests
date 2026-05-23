#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],b[N],dp[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),b[a[i]]=i;
	int ans=0;
	for (int i=1;i<=n;i++){
		int p=b[a[i]-1];
		dp[i]=dp[p]+1;
		ans=max(ans,dp[i]);
	}
	printf("%d",n-ans);
	return 0;
}