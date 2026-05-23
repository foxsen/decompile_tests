#include<bits/stdc++.h>
#define STDIO
using namespace std;
stack<pair<int,int> > stk;
int MOD=998244353;
int n;
pair<int,int> robo[200100];
int dp[200100];
int main(){
	#ifndef STDIO
		freopen("input.in","r",stdin);
		freopen("output.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>robo[i].first>>robo[i].second;
		robo[i].second+=robo[i].first;
	}
	sort(robo,robo+n);
	dp[n]=1;
	stk.emplace(2e9,1);
	for(int i=n-1;i>=0;i--){//处理机器人
		while(stk.size()&&stk.top().first<robo[i].second)
			stk.pop();
		if(stk.size())
			dp[i]=stk.top().second;
		dp[i]+=dp[i+1];
		dp[i]%=MOD;
		stk.emplace(robo[i].first,dp[i]);
	}
	cout<<dp[0]<<endl;
	return 0;
}
