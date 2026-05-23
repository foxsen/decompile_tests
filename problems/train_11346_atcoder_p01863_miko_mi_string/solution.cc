#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


struct RollingHash{
  using ull = unsigned long long;
  vector<ull> hash,p;
  RollingHash(){}
  RollingHash(const string &s,ull B=1000000007LL){
    int n=s.size();
    hash.assign(n+1,0);
    p.assign(n+1,1);
    for(int i=0;i<n;i++){
      hash[i+1]=hash[i]*B+s[i];
      p[i+1]=p[i]*B;
    }
  }
  //S[l, r)
  ull find(int l,int r){
    return hash[r]-hash[l]*p[r-l];
  }
};

//INSERT ABOVE HERE
signed main(){
  string s;
  cin>>s;
  int n=s.size();
  int ans=n+1;

  RollingHash rh(s);
  for(int a=1;a*3<n;a++){
    if((n-a*3)&1) continue;
    int b=(n-a*3)/2;
    using ull = RollingHash::ull;
    ull u=rh.find(0,a);
    ull v=rh.find(a,a+b);
    ull w=rh.find(a+b,a+b+a);
    ull x=rh.find(a+b+a,a+b+a+b);
    ull y=rh.find(a+b+a+b,a+b+a+b+a);
    if(u==w&&w==y&&v==x) chmin(ans,a+b);
  }

  if(ans<=n) cout<<"Love "<<s.substr(0,ans)<<"!"<<endl;
  else cout<<"mitomerarenaiWA"<<endl;
  return 0;
}

