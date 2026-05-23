#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll cake[4010];
int n;

ll dp[4010][4010];

ll dfs(int l, int r){
	if(dp[l][r]>-1)return dp[l][r];
	if(l==r){
		dp[l][r]=0;
		return dp[l][r];
	}
	if(l+1==r){
		dp[l][r]=min(cake[l],cake[r]);
		return dp[l][r];
	}
	if(cake[l]==cake[r]){
		dp[l][r] = cake[l+1] + dfs(l+2,r);
		dp[l][r] = max(dp[l][r], cake[r] + dfs(l+1,r-1));
		dp[l][r] = max(dp[l][r], cake[l] + dfs(l+1,r-1));
		dp[l][r] = max(dp[l][r], cake[r-1] + dfs(l,r-2));
		return dp[l][r];
	}
	if(cake[l]>cake[r]){
		dp[l][r] = cake[l+1] + dfs(l+2,r);
		dp[l][r] = max(dp[l][r], cake[r] + dfs(l+1,r-1));
		return dp[l][r];
	}
	if(cake[l]<cake[r]){
		dp[l][r] = cake[l] + dfs(l+1,r-1);
		dp[l][r] = max(dp[l][r], cake[r-1] + dfs(l,r-2));
		return dp[l][r];
	}
}

int main(){
	
	ll ans=0;
	
	for(int i=0;i<4010;i++){
		for(int j=0;j<4010;j++){
			dp[i][j]=-1;
		}
	}
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cake[i];
		cake[n+i]=cake[i];
	}
	
	for(int i=0;i<n;i++){
		ll tmp=0;
		tmp = cake[i] + dfs(i+1,i+n-1);
		ans=max(ans,tmp);
	}
	
	cout<<ans<<endl;
	
	return 0;
}
