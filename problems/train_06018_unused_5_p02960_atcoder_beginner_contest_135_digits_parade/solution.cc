#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[100001][13];
int main(){
	string s;
	cin>>s;
	dp[0][0]=1;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<13;j++){
			if(s[i]=='?')
				for(int k=0;k<=9;k++)
					(dp[i+1][(j*10+k)%13]+=dp[i][j])%=mod;
			else
				(dp[i+1][(j*10+s[i]-'0')%13]+=dp[i][j])%=mod;
		}
	}
	cout<<dp[s.size()][5]<<endl;
}
