#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P2;
ll n;
vector<P> vec;
ll dp[1005][1005]={0},dp2[1005]={0};
bool sec_ok[1005][1005]={0};
const ll inf=174417441744;
ll sec_dp(ll l,ll r){
	if(l==r){
		sec_ok[l][r]=true;
		return dp[l][r]=vec[l].second;
	}
	if(dp[l][r]!=inf) return dp[l][r];
	ll ldp=sec_dp(l+1,r);
	ll rdp=sec_dp(l,r-1);
	ll lk=0,rk=0;
	bool f=false;
	if(ldp-vec[l].first<=0&&sec_ok[l+1][r]){
		f=true;
		lk=ldp+vec[l].second;
	}
	if(rdp-vec[r].first<=0&&sec_ok[l][r-1]){
		f=true;
		rk=rdp+vec[r].second;
	}
	if(!f){
		//if(l==0&&r==1) cout<<"12FALSE"<<endl;
		sec_ok[l][r]=false;
		return dp[l][r]=0;
	}
	sec_ok[l][r]=true;
	//if(l==0&&r==1) cout<<ldp-vec[l].first<<"   12inayo   "<<rdp-vec[r].first<<endl;
	return dp[l][r]=max(lk,rk);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		ll c,w;
		cin>>c>>w;
		vec.push_back(P(c,w));
	}
	for(int i=0;i<1005;i++){
		for(int j=0;j<1005;j++){
			 dp[i][j]=inf;
			 sec_ok[i][j]=true;
		 }
		 dp2[i]=inf;
	}
	sec_dp(0,n-1);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
	//		cout<<(sec_ok[i][j]?"O":"X")<<" ";
		}
//		cout<<endl;
	}
	//cout<<endl;

	dp2[0]=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(sec_ok[i][j]) dp2[j+1]=min(dp2[j+1],(ll)(dp2[i]+1));
		}
	}
//	for(int i=0;i<=n;i++) cout<<dp2[i]<<" ";
//	cout<<endl;
	cout<<dp2[n]<<endl;
}

