#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  string s;
  long long int a[5]={};
  string march="MARCH";
  for(int i=0;i<n;i++){
    cin>>s;
    
    for(int j=0;j<5;j++)
      if(s.at(0)==march[j])
        a[j]++;
    
  }
  long long int ans=0;
 
  for(int i=0;i<3;i++)
    for(int j=i+1;j<4;j++)
      for(int k=j+1;k<5;k++){
        ans+=a[i]*a[j]*a[k];
       
      }
      
  
  cout<<ans;
  return 0;
  
}