#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P2;
const int inf=1000000000;
int dp[101][101][301]={};
ll w1[101]={};
int v1[101]={};
ll km[101]={};
int main() {
	int n;
	ll w;
	cin>>n>>w;
	for(int i=1;i<n+1;++i){
		cin>>w1[i]>>v1[i];
		km[i]=km[i-1]+w1[i]-w1[1];
	}
	int r=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			for(ll k=0;k<=km[i];++k){
				ll k1=w1[i]-w1[1];
				if(k1<=k){
					dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-1][k-k1]+v1[i]);
				}else{
					dp[i][j][k]=dp[i-1][j][k];
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(ll k=0;k<=km[n];++k){
			if(w>=w1[1]*i+k)r=max(r,dp[n][i][k]);
		}
	}

	cout<<r<<endl;
	return 0;
}
