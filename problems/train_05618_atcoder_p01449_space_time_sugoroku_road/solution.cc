#include <algorithm>
#include <iostream>
#define INF (1e9)
#define N 100001
using namespace std;

int main(){
  int n,p[N],dp[N];
  cin>>n;
  for(int i=0;i<n;i++) cin>>p[i];
  for(int i=0;i<n;i++) dp[i]=INF;
  dp[n-1]=0;
  for(int i=n-1;i>=0;i--){
    if(p[i]>0) dp[i]=min(dp[i],dp[i+p[i]]);
    if(!p[i])
      for(int j=1;j<=6;j++)
	if(i+j<=n-1)
	  dp[i]=min(dp[i],dp[i+j]+1);
  }
  while(1){
    int f=0;
    for(int i=n-1;i>=0;i--){
      if(p[i]>0)
	if(dp[i]>dp[i+p[i]]) dp[i]=dp[i+p[i]],f=1;
      if(!p[i])
	for(int j=1;j<=6;j++)
	  if(i+j<=n-1)
	    if(dp[i]>dp[i+j]+1) dp[i]=dp[i+j]+1,f=1;
      if(p[i]<0)
	if(dp[i]>dp[i+p[i]]) dp[i]=dp[i+p[i]],f=1;
    }
    if(!f) break;
  }
  cout<<dp[0]<<endl;
  return 0;
}