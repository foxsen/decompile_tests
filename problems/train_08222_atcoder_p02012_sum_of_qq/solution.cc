#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){

  int S;
  int ans = 0, con = 0;
  map<int,int> mp;
  
  cin>>S;

  for(int i = 1; i <= S; i++){
    for(int j = i, sum = i; sum <= S; j++){
      mp[sum]++;
      // cout<<"i "<<i<<" j "<<j<<" "<<sum<<endl;
      sum += j+1;
      
      con++;
    }
  }

  // cout<<con<<endl;

   for(int i = 1; i <= S; i++){
     if(S%i) continue;
     int a = mp[i], b = mp[S/i];

     // if(i == S/i) b--;

      if(a < 0 || b < 0) continue;

     ans += a * b;
   }

   cout<<ans<<endl;

  return 0;
}


