#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  using P = pair<Int, Int>;
  auto mul=[](P a,Int b){return P(a.first*b,a.second*b);};
  auto add=[](P a,Int b){return P(a.first,a.second+b);};
  auto sub=[](P a,Int b){return P(a.first,a.second-b);};
  P cur(1,0);
  for(Int i=0;i<n;i++){
    Int t,x;
    cin>>t>>x;
    if(t==1) cur=mul(cur,x);
    if(t==2) cur=add(cur,x);
    if(t==3) cur=sub(cur,x);
  }
  cout<<-cur.second<<" "<<cur.first<<endl;
  return 0;
}

