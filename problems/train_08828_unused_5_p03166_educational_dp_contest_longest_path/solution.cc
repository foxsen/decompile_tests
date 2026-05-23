#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+4;

vector<int> adj[N];
vector<int> dp(N,-1);

void dfs(int u){
	if(dp[u]!=-1)
		return ;
	dp[u] = 0;
	for(auto & n : adj[u]){
		dfs(n);
		dp[u] = max(dp[u], 1+dp[n]);
	}
}

int main(){
	int n, m;
	cin >>n >> m;
	int x, y;
	for(int i=0;i<m;++i){
		cin >> x>> y;
		adj[x].push_back(y);
	}
	for(int i=1;i<=n;++i){
		if(dp[i]==-1){
			dfs(i);
		}
	}
	int ans = 0;
	for(int i=1;i<=n;++i){
		ans = max(ans, dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}