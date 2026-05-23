#include <bits/stdc++.h>
using namespace std;

int n;
double x[1111],y[1111],dp[1111][1111];

double calc(int a,int b){
  return sqrt(pow((x[a]-x[b]),2)+pow((y[a]-y[b]),2));
}

double dfs(int l,int r,int i){
  if(i==n)return max(calc(l,n-1),calc(r,n-1));
  if(dp[l][r])return dp[l][r];
  return dp[l][r]=min(dfs(i,r,i+1)+calc(l,i) , dfs(l,i,i+1)+calc(r,i));
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++) cin>>x[i]>>y[i];
  printf("%.9f\n",dfs(0,0,1));
}
