#include<bits/stdc++.h>
using namespace std;
#define int long long
struct SA{
  int n,k;
  string S;
  vector<int> r,r2,t,sa;
  SA(){}
  SA(string S):S(S){init();}
  void init(){
    n=S.size();
    r.resize(n+1,0);
    r2.resize(n+1,0);
    t.resize(n+1,0);
    sa.resize(n+1,0);
    constract_sa();
  }
  bool compare_sa(int i,int j){
    if(r[i]!=r[j]) return r[i]<r[j];
    else{
      int ri=i+k<=n?r[i+k]:-1;
      int rj=j+k<=n?r[j+k]:-1;
      return ri<rj;
    }
  }
  void constract_sa(){
    n=S.length();
    for(int i=0;i<=n;i++){
      sa[i]=i;
      r[i]=i<n?S[i]:-1;
    }
    for(k=1;k<=n;k*=2){
      sort(sa.begin(),sa.end(),[&](const int &i, const int &j){
	  if(r[i]!=r[j]) return r[i]<r[j];
	  else{
	    int ri=i+k<=n?r[i+k]:-1;
	    int rj=j+k<=n?r[j+k]:-1;
	    return ri<rj;
	  }
	});
      t[sa[0]]=0;
      for(int i=1;i<=n;i++){
	t[sa[i]]=t[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
      }
      for(int i=0;i<=n;i++){
	r[i]=t[i];
      }
    }
  }
  bool contains(string T){
    int a=0,b=S.length()+1;
    while(a+1<b){
      int c=(a+b)/2;
      //cout<<a<<" "<<b<<" "<<c<<endl;
      if(S.compare(sa[c],T.length(),T)<0) a=c;
      else b=c;
    }
    if(b==(int)S.length()+1) b--;
    return S.compare(sa[b],T.length(),T)==0;
  }
};
char buf[1000001];
signed main(){
  scanf("%s",buf);
  string T(buf);
  SA sa(T);
  int q;
  scanf("%lld",&q);
  while(q--){
    scanf("%s",buf);
    string P(buf);
    printf("%lld\n",(int)sa.contains(P));
  }
  return 0;
}