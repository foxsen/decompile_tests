#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,p; cin >> n;
  int ans=0,maxi=0;
  while(n--){
    cin >> p;
    ans+=p;
    maxi=max(maxi,p);
  }
  cout << ans-(maxi/2) << endl;
  
  return 0;
}
