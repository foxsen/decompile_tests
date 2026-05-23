#include<bits/stdc++.h>
#define N 1150
using namespace std;
bool prime[N];
vector<int> p;
int dp[205][N][15];

int main(){
  for(int i=0;i<N;i++)
    prime[i]=true;
  prime[0]=prime[1]=false;
  for(int i=0;i*i<N;i++){
    if(!prime[i])continue;
    for(int j=i*2;j<N;j+=i)
      prime[j]=false;
  }
  for(int i=0;i<N;i++)
    if(prime[i])p.push_back(i);
  while(1){
    int n,k;
    cin>>n>>k;
    if(!n&&!k)break;
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0;i<p.size();i++){
      for(int j=0;j<=n;j++){
	for(int l=0;l<=k;l++){
	  if(!dp[i][j][l])continue;
	  if(j+p[i]<=n)
	    dp[i+1][j+p[i]][l+1]+=dp[i][j][l];
	  dp[i+1][j][l]+=dp[i][j][l];
	}
      }
    }
    cout<<dp[p.size()][n][k]<<endl;
  }
  return 0;
}