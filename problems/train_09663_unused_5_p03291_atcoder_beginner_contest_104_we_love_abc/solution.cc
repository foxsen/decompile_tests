#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define mod 1000000007
string s;
int dp[111111][4];
signed main(){
	cin>>s;
	for(int i=s.size();i>=0;i--){
		for(int j=3;j>=0;j--){
			if(i==s.size()){
				if(j==3)dp[i][j]=1;
			}
			else{
				if(s[i]=='?')dp[i][j]=dp[i+1][j]*3;
				else dp[i][j]=dp[i+1][j];
				if(j<3&&(s[i]=='?'||(j==0&&s[i]=='A')||(j==1&&s[i]=='B')||(j==2&&s[i]=='C')))dp[i][j]+=dp[i+1][j+1];
				dp[i][j]%=mod;
			}
		}
	}
	cout<<dp[0][0]<<endl;
	return 0;
}
