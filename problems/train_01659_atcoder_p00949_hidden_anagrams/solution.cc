#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull B=1e9+7;
ull Hash(vector<int> &v){
  ull h=0;
  for(int i=0;i<26;i++)h=h*B+v[i];
  return h;
}

int main(){
  string a,b;
  cin>>a>>b;
  int ans=0,n=a.size(),m=b.size();
  
  for(int i=1;i<=n;i++){
    unordered_set<ull> S;
    vector<int> v(26,0);
    for(int j=0;j<n;j++){
      if(i==j)S.insert(Hash(v));
      v[a[j]-'a']++;
      if(j>=i) {
	v[a[j-i]-'a']--;
	S.insert(Hash(v));
      }
    }
    S.insert(Hash(v));
    v=vector<int>(26,0);
    for(int j=0;j<m;j++){
      if(i==j&&S.count(Hash(v)))ans=i;
      v[b[j]-'a']++;
      if(j>=i){
	v[b[j-i]-'a']--;
	if(S.count(Hash(v)))ans=i;
      }    
    }
    if(S.count(Hash(v)))ans=i;
  }
  cout <<ans<<endl;
  return 0;
}