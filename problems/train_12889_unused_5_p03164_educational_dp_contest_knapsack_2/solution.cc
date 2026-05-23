
#include <bits/stdc++.h>
using namespace std;
#define fo(i,ini,n) for(int i=ini;i<n;i++)
#define rfo(i,ini,n) for(int i=ini;i>=n;i--)
int const inf=1e9+7;
typedef long long ll;

int main(){
	int t=1;
	while(t--){
		ll n,W,v,w;
		cin>>n>>W;
		vector<ll>dp(100001,inf);
		dp[0]=0;
		fo(i,0,n){
			cin>>w>>v;
			rfo(j,100001-v,0){
				dp[j+v]=min(dp[j+v],dp[j]+w);
				
			}
		}
		rfo(i,100000,0){
			if(dp[i]<=W){
			cout<<i<<endl;
			break;
			}
		}
	}

	return 0;
}
