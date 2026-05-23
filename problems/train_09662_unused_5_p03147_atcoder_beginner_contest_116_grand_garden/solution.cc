#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,i;
  cin>>n;
  int h[n];
  for(i=0;i<n;i++)
    cin>>h[i];
  
  int ans=0;
  
  for(i=0;i<n;i++){
    if(i!=n-1 && h[i]>h[i+1])
      ans+=h[i]-h[i+1];
    if(i==n-1)
      ans+=h[i];
  }
  cout<<ans;
    
}