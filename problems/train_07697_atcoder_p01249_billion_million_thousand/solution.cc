#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> void chmin(T1 &a,T2 b){if(a>b) a=b;};
template<typename T1,typename T2> void chmax(T1 &a,T2 b){if(a<b) a=b;};

signed main(){
  Int n;
  Int cnt=0;
  while(cin>>n,n){
    vector<string> ss(n);
    vector<Int> ls(n),vs(n);
    for(Int i=0;i<n;i++) cin>>ss[i]>>vs[i],ls[i]=ss[i].size();
    string t;
    cin>>t;
    Int m=t.size();

    const Int INF = 1e9;
    vector<Int> dp1(m+1,-INF);
    dp1[0]=0;

    for(Int i=0;i<m;i++){
      for(Int j=0;j<n;j++){
	if(i+ls[j]>m) continue;
	if(t.substr(i,ls[j])!=ss[j]) continue;
	chmax(dp1[i+ls[j]],dp1[i]+vs[j]);
      }
    }

    vector<Int> dp2(dp1[m]+1,INF);
    dp2[0]=0;
    for(Int i=0;i<dp1[m];i++){
      for(Int j=0;j<n;j++){
	if(i+vs[j]>dp1[m]) continue;
	chmin(dp2[i+vs[j]],dp2[i]+ls[j]);
      }      
    }
    
    cout<<"Case "<<++cnt<<": "<<dp2[dp1[m]]<<endl;
  }
  return 0;
}


