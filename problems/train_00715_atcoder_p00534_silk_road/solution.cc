#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define INF 1e10
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	long long dp[n+1][m+1];
	long long d[n+1],c[m+1];
	rep(i,n+1){
		rep(j,m+1){
			if(i==0)dp[i][j]=0;
			else dp[i][j]=INF;
		}
	}
	loop(i,1,n+1)cin>>d[i];
	loop(i,1,m+1)cin>>c[i];
	loop(i,1,n+1){
		loop(j,1,m+1){
			dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+d[i]*c[j]);
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}