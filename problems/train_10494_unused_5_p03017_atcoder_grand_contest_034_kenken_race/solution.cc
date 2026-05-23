#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,a,b,c,d;
  string s;
  cin>>n>>a>>b>>c>>d>>s;
  a--; b--; c--; d--;
  bool ans=0;
  if(c>d){
    int tmp=0;
    for(int i=b-1; i<=d+1; i++){
      if(s[i]!='#') tmp++;
      else tmp=0;
      if(tmp==3) ans=1;
    }
  }else{
    ans=1;
  } 
  if(ans){
    for(int i=b; i<d; i++){
      if(s[i]=='#' && s[i+1]=='#') ans=0;
    }
    for(int i=a; i<c; i++){
      if(s[i]=='#' && s[i+1]=='#') ans=0;
    }
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

