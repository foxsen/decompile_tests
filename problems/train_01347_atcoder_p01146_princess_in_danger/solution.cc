#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int dp[110][110];
int dp2[110][110];

int main(){
	int n,m,L,K,A,H;
	while(cin>>n>>m>>L>>K>>A>>H,n){
		rep(i,n) rep(j,n) dp[i][j] = dp2[i][j] = 1e9;
		vector<int> ll(L);
		rep(i,L) cin>>ll[i];
		ll.push_back(A);
		ll.push_back(H);
		L+=2;
		sort(ll.begin(), ll.end());

		rep(i,K){
			int a,b,c;
			cin>>a>>b>>c;
			dp[a][b] = dp[b][a] = c;
		}
		rep(i,n) dp[i][i] = 0;

		rep(k,n) rep(i,n) rep(j,n) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

		rep(i,L){
			rep(j,L){
				dp2[i][j] = (dp[ll[i]][ll[j]] > m ? 1e9: dp[ll[i]][ll[j]]);
			}
		}
		rep(i,L) dp2[i][i] = 0;

		rep(k,L) rep(i,L) rep(j,L) dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k][j]);

		int a,h;
		rep(i,L){
			if(ll[i]==A) a=i;
			if(ll[i]==H) h=i;
		}
		if(dp2[h][a]>1e8){
			cout<<"Help!"<<endl;
		}
		else{
			int t = dp2[h][a];
			if(t < m) cout<<t<<endl;
			else cout<<t+(t-m)<<endl;
		}
	}
}