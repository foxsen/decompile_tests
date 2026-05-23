#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

int dp[5050][5050];

int main(){
  int N; cin>>N;
  string S; cin>>S;
  int ans=0;
  for(int i=N-1;i>=0;i--){
    for(int j=N-1;j>=0;j--){
      if(S[i]==S[j]){
        dp[i][j]=max(dp[i][j],dp[i+1][j+1]+1);
      }
      ans=max(ans,min(dp[i][j],j-i));
    }
  }
  cout<<ans<<endl;
  return 0;
}