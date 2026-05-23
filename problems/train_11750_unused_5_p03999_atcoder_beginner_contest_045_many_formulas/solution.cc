#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int ans=0,sum;
  string s;
  cin>>s;  
  for(int bit=0;bit<(1<<s.size());bit++){
    sum=0;
    for(int i=0;i<s.size();i++){
      if(bit&(1<<i)){
        ans+=sum;
        sum=0;
      }
      sum*=10;
      sum+=s[i]-'0';
    }
    ans+=sum;
  }
  cout<<ans/2<<"\n";
}