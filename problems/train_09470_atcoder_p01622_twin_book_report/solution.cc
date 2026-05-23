#include <bits/stdc++.h>
typedef long long LL;
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
int main(void)
{
  for(;;){
    int n;
    cin >> n;
    if(!n) return 0;
    vector<int> a,b;
    a.resize(n);
    b.resize(n);
    REP(i,n) cin >> a[i] >> b[i];
    int asum=0,amax=0,bsum=0;
    REP(i,n){
      asum+=a[i];
      amax=max(amax,a[i]);
      bsum+=b[i];
    }
    int dp[4096];
    REP(i,2048) dp[i]=0;
    dp[0]=1;
    REP(i,n) for(int j=1000;j>=0;--j){
      if(a[i]==amax) continue;
      if(dp[j]){
	dp[j+a[i]]+=dp[j];
	dp[j+a[i]+b[i]]+=dp[j];
      }
    }
    int answer=asum+bsum;
    if(asum<amax*2){
      for(int i=amax;dp[i]==0;--i) answer++;
    }
    cout << answer << endl;
    


  }
}