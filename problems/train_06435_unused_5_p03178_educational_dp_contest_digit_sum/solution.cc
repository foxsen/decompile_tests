#include <bits/stdc++.h>
using namespace std;

string s;

int dp[10009][2][100],p,d;


int dfs(int idx,int z,bool tight){
  if(idx==s.size())return !z;
  int &res=dp[idx][tight][z];
  if(~res)return res;
  res=0;
  int x=s[idx]-'0';
  int r=(tight?9:x);
  for(int i=0;i<=r;i++){
    res+=dfs(idx+1,(z+i)%d,tight||i<r);
    res%=1000000007;
  }
  return res;
}

int main(){
  memset(dp,-1,sizeof dp);
  cin>>s>>d;
  cout<<(dfs(0,0,0)-1+1000000007)%1000000007<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
