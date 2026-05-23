#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int a[100];
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];

  int ans=1000000000;
  for(int i=-100;i<=100;i++){
    int sum=0;
    for(int j=0;j<n;j++){
      sum+=(a[j]-i)*(a[j]-i);
    }
    ans=min(sum,ans);
  }

  cout<<ans<<endl;
  return 0;
}
