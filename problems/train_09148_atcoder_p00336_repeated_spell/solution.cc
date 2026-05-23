#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;

using namespace std;
#define N 1010
string s,t;
ll dp[N][N];
int main(){
    cin>>s>>t;
    int n=s.size(),m=t.size();
    lol(j,m+1)dp[0][j]=0;dp[0][0]=1;
    for(int i=1;i<=n;i++){
	lol(j,m+1){
	    dp[i][j]=dp[i-1][j];
	    if(s[i-1]==t[j-1]){
		dp[i][j]+=dp[i-1][j-1];
		dp[i][j]%=mod;
	    }
	}
    }
    cout<<dp[n][m]<<endl;
    return 0;
}

