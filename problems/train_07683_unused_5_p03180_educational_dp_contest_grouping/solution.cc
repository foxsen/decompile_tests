#include <bits/stdc++.h>
using namespace std;
long long dp[100005], n, a[20][20];
long long solve(int bitmask){
	if (dp[bitmask]!=-1) return dp[bitmask];
	dp[bitmask]=0;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if (bitmask&(1<<i) and bitmask&(1<<j))
				dp[bitmask]+=a[i][j];
		}
	}
	int ekstramask=bitmask;
	while (true){
		ekstramask--; ekstramask&=bitmask;
		if (!ekstramask) break;
		dp[bitmask] = max(dp[bitmask], solve(ekstramask)+solve(bitmask^ekstramask));
	}
	return dp[bitmask];
}
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n;
for (int i=0; i<n; i++){
	for (int j=0; j<n; j++){
		cin >> a[i][j];
	}
} 
for (int i=1; i<(1<<n); i++) dp[i]=-1;
cout << solve((1<<n)-1);
return 0;
}
