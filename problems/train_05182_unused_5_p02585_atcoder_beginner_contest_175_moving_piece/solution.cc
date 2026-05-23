#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int p[6000],c[6000];
int par[30][6000];
ll dp[30][6000],dp2[30][6000];

int main(){
	int n,K;cin>>n>>K;
	rep(i,n)scanf("%d",&p[i]),p[i]--;
	rep(i,n)scanf("%d",&c[i]);
	rep(i,30)rep(j,n)dp[i][j]=-INFL;
	rep(i,n){
		dp[0][i]=dp2[0][i]=c[p[i]];
		par[0][i]=p[i];
	}
	for(int i=1;i<30;i++)rep(j,n){
		par[i][j]=par[i-1][par[i-1][j]];
		dp2[i][j]=dp2[i-1][j]+dp2[i-1][par[i-1][j]];
		dp[i][j]=max(dp[i-1][j],dp2[i-1][j]+dp[i-1][par[i-1][j]]);
	}
	ll Max=-INFL;
	rep(i,n){
		int pos=i;
		ll score=0;
		rep(j,30){
			if(K>>j&1){
				Max=max(Max,score+dp[j][pos]);
				score+=dp2[j][pos];
				pos=par[j][pos];
			}
		}
	}
	cout<<Max<<endl;
}