#include<bits/stdc++.h>
using namespace std;
long long solve(){
	int n;
	cin>>n;
	vector<int>H(n);
	vector<long long>V(n);
	for(int i=0;i<n;i++) cin>>H[i];
	for(int i=0;i<n;i++) cin>>V[i];
	map<int,long long>A; //more height means more dp[i]
	long long dp[n];
	dp[0]=V[0];
	A[H[0]]=V[0];
	long long ans=V[0];
	for(int i=1;i<n;i++){
		dp[i]=V[i];
		auto it=A.lower_bound(H[i]);
		if(it!=A.begin()){
			auto it1=it;
			dp[i]=V[i]+(--it1)->second;
		}
		auto it1=it;
		while(it!=A.end() && it->second<=dp[i]) it++;
		A.erase(it1,it);
		A[H[i]]=dp[i];
		ans=max(ans,dp[i]);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<solve();

}