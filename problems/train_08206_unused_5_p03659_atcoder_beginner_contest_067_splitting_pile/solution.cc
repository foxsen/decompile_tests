#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a[200000]={};
  long long sum=0,tsum=0,x;
  cin>>n;
  for(int i=0;i<n;i++){cin>>a[i];tsum+=a[i];}
  long long ans=1000000000000000000;
  for(int i=0;i<n-1;i++){
    sum+=a[i];
    x=abs(sum-(tsum-sum));
    if(x<ans) ans=x;
  }
  cout<<ans<<endl;
  
  return 0;
}