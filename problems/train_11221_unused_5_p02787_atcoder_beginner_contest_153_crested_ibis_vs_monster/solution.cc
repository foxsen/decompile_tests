#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
int main(){
	
	int H, n;
	cin>>H>>n;
	vector<int> dp(H+1, INF);
  	dp[0] = 0;
	while(n--){
		int val, cost;
		cin>>val>>cost;
		for(int i=0;i<=H;i++){
			int j=min(H, i+val);
			dp[j] = min(dp[j], dp[i] + cost);
		}
	}
	cout<<dp[H]<<endl;	
	
}