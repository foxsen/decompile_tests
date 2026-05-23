#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin>>n;
  long long ans=0;
  map<string,long long> m;
  for(int i=0;i<n;i++){
    string s; cin>>s;
    sort(s.begin(),s.end());
    m[s]++;
  }
  for(auto p:m)ans+=p.second*(p.second-1)/2;

cout<<ans<<endl;

}
