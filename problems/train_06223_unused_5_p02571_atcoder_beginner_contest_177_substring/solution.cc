#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin >> s >> t;
  int i,j;
  int ans=10000;
  for(i=0;i<s.size()-t.size()+1;i++){
    int x=0;
    for(j=0;j<t.size();j++){
      if(s[i+j]!=t[j]){
        x++;
      }
    }
    ans=min(ans,x);
  }
  cout << ans << endl;
}