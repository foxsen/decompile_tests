#include <bits/stdc++.h>
using namespace std;

signed main(){
  int n,k;cin>>n>>k;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  while(k--){
    vector<int> w(n+1,0);
    for(int i=0;i<n;i++){
      int l=max(0,i-v[i]),r=min(n-1,i+v[i]);
      w[l]++;w[r+1]--;
    }
    for(int i=0;i<n;i++)v[i]=w[i],w[i+1]+=w[i];
    bool ok=1;
    for(int i=0;i<n;i++)ok&=v[i]==n;
    if(ok)break;
  }
  for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<endl;
}
