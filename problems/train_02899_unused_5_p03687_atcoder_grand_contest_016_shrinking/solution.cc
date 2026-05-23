#include<bits/stdc++.h>
using namespace std;

int main(){

  string s;
  cin>>s;

  int ans=105;
  
  for(int i=0;i<s.size();i++){

    int cnt=0, maxcnt=0;
    
    for(int j=s.size()-1;j>=0;j--){
      
      if(s[i]==s[j]) cnt=0;
      else cnt++;
      
      maxcnt=max(maxcnt,cnt);
      
    }    
    
    ans=min(ans,maxcnt);
    
  }

  cout<<ans<<endl;
  
  return 0;
}
