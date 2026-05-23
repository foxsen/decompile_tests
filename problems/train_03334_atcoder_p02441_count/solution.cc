#include<bits/stdc++.h>
using namespace std;

signed main(){

  int n;
  cin>>n;
  vector<int> a(n);
  for(auto& ai:a)cin>>ai;

  int q;
  cin>>q;
  while(q--){
    int l,r,k;
    cin>>l>>r>>k;
    cout<< count(a.begin()+l,a.begin()+r,k) <<endl;
  }

}
