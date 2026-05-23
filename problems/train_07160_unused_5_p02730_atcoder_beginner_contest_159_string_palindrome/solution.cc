#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  string str,ans;
  cin>>str;
  n=str.size();
  ans="Yes";
  for(int i=0; i<(n-1)/2; i++){
    if(str.at(i)!=str.at(n-1-i)){
      ans="No";
      break;
    }
    if(str.at(i)!=str.at((n-1)/2-i-1)){
      ans="No";
      break;
    }
  }
  cout<<ans;
}
