#include<bits/stdc++.h>
using namespace std;

int main(){
  int num[9];
  for(int i=0;i<9;i++){
    cin>>num[i];
    //cout<<A[i]<<endl;
  }
    
  bool A[9]={false};
  int N;
  cin>>N;
  
  int b;
  for(int i=0;i<N;i++){
    cin>>b;
    for(int j=0;j<9;j++){
      if(num[j]==b)A[j]=true;
    }
  }
  
  string ans="No";
  if(A[0] && A[1] && A[2])ans="Yes";
  if(A[3] && A[4] && A[5])ans="Yes";
  if(A[6] && A[7] && A[8])ans="Yes";
  if(A[0] && A[3] && A[6])ans="Yes";
  if(A[1] && A[4] && A[7])ans="Yes";
  if(A[2] && A[5] && A[8])ans="Yes";
  if(A[0] && A[4] && A[8])ans="Yes";
  if(A[2] && A[4] && A[6])ans="Yes";
  
  cout<<ans<<endl;

}
