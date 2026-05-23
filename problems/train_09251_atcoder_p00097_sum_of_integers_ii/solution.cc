#include <iostream>
using namespace std;
long long dp[102][11][1002];
int main(){
  int N,S;
  while(cin>>N>>S&&(N!=0)){
    for(int i=101;i>=0;i--){
      for(int j=0;j<=N;j++){
        for(int k=0;k<=S;k++){
          long long res=0;
          if(i==101)res=(j==0&&k==0);
          else{
            res+=dp[i+1][j][k];
            if(j-1>=0&&k-i>=0)res+=dp[i+1][j-1][k-i];
          }
          dp[i][j][k]=res;
        }
      }
    }
    cout<<dp[0][N][S]<<endl;
  }
  return 0;
}