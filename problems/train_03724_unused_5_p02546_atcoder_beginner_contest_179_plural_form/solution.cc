#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S;
  cin>>S;
  cout<<S<<(S[S.size()-1]=='s'?"es":"s")<<endl;
}