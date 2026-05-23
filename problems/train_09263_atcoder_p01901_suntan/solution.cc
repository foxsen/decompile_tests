#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int t,n;
  cin>>t>>n;
  vector<Int> a(n),b(n);
  for(Int i=0;i<n;i++) cin>>a[i]>>b[i];
  vector<Int> s(n+1);
  for(Int i=0;i<n;i++) s[i+1]=s[i]+(b[i]-a[i]);

  Int ans=0;
  for(Int i=0;i<n;i++){
    Int k=lower_bound(b.begin(),b.end(),a[i]+t)-b.begin();
    Int res=s[k]-s[i];
    if(k<n) res+=max((Int)0,(a[i]+t)-a[k]);
    chmax(ans,res);
    //cout<<i<<":"<<k<<":"<<res<<endl;    
  }
  cout<<ans<<endl;
  return 0;
}

