#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll N,K;
  ll L[222222],R[222222];
  cin >> N >> K;
  ll i,k;
  for(i=0;i<=K-1;i++)
    cin >> L[i] >> R[i];
  ll dp[222222] = {0};
  dp[1] = 1;
  ll sum[222222] = {0};
  sum[1] = 1;
  for(i=2;i<=N;i++)
    for(k=0;k<=K-1;k++){
      dp[i] = (dp[i] + sum[i-L[k]] - sum[i-R[k]-1]) % 998244353;
      sum[i] = (sum[i-1] + dp[i]) % 998244353;
    }
  if(dp[N] < 0) dp[N] += 998244353;
  cout << dp[N] << endl;
}