#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
typedef pair<int,int>P;
typedef pair<P,int>P2;
#define fi first
#define se second
 
typedef unsigned long long ull;
 
 
struct RollingHash{
  typedef unsigned long long ull;
  string S;
  ull B;
  int len;
  vector<ull> hash,p;
  RollingHash(){}
  RollingHash(string S_,ull B_=1000000009LL):
    S(S_),B(B_),len(S.length()),hash(len+1),p(len+1){
    hash[0]=0;p[0]=1;
    for(int i=0;i<len;i++){
      hash[i+1]=hash[i]*B+S[i];
      p[i+1]=p[i]*B;
    }
  }
  //S[l,r)
  ull find(int l,int r){
    return hash[r]-hash[l]*p[r-l];
  }
};
 
signed main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  string t=s;
 
   set<char>st;
  r(i,n){
    st.insert(s[i]);
  }
 
  reverse(t.begin(),t.end());
 
  if(st.size()==1){
    cout<<2<<endl;
    return 0;
  }
 
  RollingHash S(s);
  RollingHash T(t);
 
  for(int i=2;i<=n;i++){
 
    int idx=0 , F=0 ;
    ull A=S.find(0,i);
 
    for(int j=0;;j++){
 
      if(j%2==0){
 
        if(idx+i>n){//cout<<j<<endl;
          int x=n-idx;
          ull has=S.find(0,x);
 
          if(S.find(idx,n)!=has){
            F++;
            break;
          }
        }
 
        else{
        if(S.find(idx,idx+i) != A){
          F++;
          break;
        }}
      }
 
      else{
 
        if(n-idx-i<0){
 
          ull has=S.find(i-(n-idx),i);
 
          //cout<<i-n-idx<<' '<<i<<endl;
 
          if(T.find(0,n-idx)!=has){
            F++;
            break;
          }
        }
 
        else{
        if(T.find(n-idx-i,n-idx) != A){
          //cout<<n-idx-i<<' '<<n-idx<<endl;
          F++;
          break;
        }}
      }
 
      idx+=i-1;
 
      //cout<<idx<<endl;
 
      if(idx>n)break;
    }
 
    //cout<<idx<<' '<<i<<endl;
    if(!F){
 
      cout<<i<<endl;
      return 0;
 
    }
  }
 
}
