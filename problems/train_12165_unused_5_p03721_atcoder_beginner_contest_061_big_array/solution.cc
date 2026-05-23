#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,k;
  cin>>n>>k;
  pair<int,int> p[111111];
  for(int i=0;i<n;i++)cin>>p[i].first>>p[i].second;
  sort(p,p+n);
  int cnt=0;
  for(int i=0;i<n;i++){
    cnt+=p[i].second;
    if(cnt>=k){
      cout<<p[i].first<<endl;
      return 0;
    }
  }
}
