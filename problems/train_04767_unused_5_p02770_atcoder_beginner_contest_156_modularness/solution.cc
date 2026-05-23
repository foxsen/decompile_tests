#include<bits/stdc++.h>
using namespace std;
#define int long

signed main(){
  int k,q,n,x,m;
  cin>>k>>q;
  vector<int> d(k);
  for(auto& i:d)cin>>i;
  while(q--){
    cin>>n>>x>>m;
    x%=m;
    --n;
    vector<int> e(k);
    int u=0,res,t,ps=0,s,pz=0,z;
    for(int i=0;i<k;++i)ps+=e[i]=d[i]%m,u+=(m-e[i])%m,pz+=!e[i];
    res=n/(k*m)*u;
    t=n%(k*m);
    s=ps*(t/k)+x;
    z=pz*(t/k);
    for(int i=0;i<t%k;++i)s+=e[i],z+=!e[i];
    res+=t-(s/m-x/m+z);
    cout<<res<<endl;
  }
}