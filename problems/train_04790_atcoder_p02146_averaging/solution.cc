#include<bits/stdc++.h>
#define X first
#define Y sevcond
#define pb emplace_back
#define eb pb
#define rep(X,Y) for(int X=0;X<(Y);++X)
#define reps(X,O,Y) for(int X=(O);X<(Y);++X)
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
using ll=long long;
const ll INF=1e18;

int main(){
	int n;
	cin>>n;
	vector<int> xs(n);
	using Graph=vector<vector<int>>;
	Graph g(n);
	rep(i,n) cin>>xs[i];
	int t;
	{
		ll s=accumulate(all(xs),0ll);
		rep(i,n) xs[i]-=s/n;
		t=s%n;
	}
	rep(i,n-1){
		int x,y;
		cin>>x>>y; --x; --y;
		g[x].pb(y);
		g[y].pb(x);
	}
	vector<ll> sum(n),sz(n);
	{
		function<void(int,int)> dfs=
			[&](int v,int p){
				++sz[v]; sum[v]+=xs[v];
				for(int w:g[v])if(w!=p){
						dfs(w,v);
						sum[v]+=sum[w];
						sz[v]+=sz[v];
					}
			};
		dfs(0,-1);
	}
	vector<vector<ll>> dp(n);
	function<void(int,int)> dfs=
		[&](int v,int p){
			dp[v].pb(0);
			for(int w:g[v])if(w!=p){
					dfs(w,v);
					auto tmp=dp[v];
					dp[v].clear();
					dp[v].resize(tmp.size()+dp[w].size(),INF);
					rep(i,tmp.size())rep(j,dp[w].size()){
						dp[v][i+j]=min(dp[v][i+j],tmp[i]+dp[w][j]+abs(j-sum[w]));
						dp[v][i+j+1]=min(dp[v][i+j+1],tmp[i]+dp[w][j]+abs(j+1-sum[w]));
					}
				}
		};
	dfs(0,-1);
	// rep(i,n){
	// 	cout<<i<<endl;
	// 	for(auto x:dp[i]) cout<<x<<",";cout<<endl;
	// }
	cout<<min(dp[0][t],dp[0][max(0,t-1)])<<endl;
}

