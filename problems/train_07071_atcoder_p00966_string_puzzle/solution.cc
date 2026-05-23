#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n,a,b,q;
  cin>>n>>a>>b>>q;
  vector<Int> x(a),y(b),h(b),z(q);
  vector<char> c(a);
  for(Int i=0;i<a;i++) cin>>x[i]>>c[i],x[i]--;
  for(Int i=0;i<b;i++) cin>>y[i]>>h[i],y[i]--,h[i]--;
  for(Int i=0;i<q;i++) cin>>z[i],z[i]--;

  y.emplace_back(n);

  auto pos=
    [&](Int k)->Int{
      Int j=b;
      while(1){
	while(j>=0&&k<y[j]) j--;
	if(j<0||h[j]<0||y[j+1]<=k) return k;
	Int l=y[j+1]-y[j];
	if(h[j]+l<=y[j]){
	  k=h[j]+(k-y[j]);
	  continue;
	}
	Int m=y[j]-h[j];
	k=h[j]+(k-y[j])%m;
      }
    };
  
  map<Int, char> dp;  
  for(Int i=0;i<a;i++) dp[pos(x[i])]=c[i];
  for(Int i=0;i<q;i++){
    Int k=pos(z[i]);
    cout<<(dp.count(k)?dp[k]:'?');
  }
  cout<<endl;  

  return 0;
}

