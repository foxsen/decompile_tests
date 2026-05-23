#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,t;
  cin>>n>>t;
  vector<int> ds(n);
  for(int i=0;i<n;i++) cin>>ds[i];
  sort(ds.begin(),ds.end());

  using ll = long long;
  const int mod = 1e9+7;
  ll ans=1;
  for(int i=0;i<n;i++){
    auto it=lower_bound(ds.begin(),ds.begin()+i,ds[i]-t);
    ans*=(ll)(ds.begin()+i+1-it);
    ans%=mod;
  }

  cout<<ans<<newl;
  return 0;
}

