#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Q = 1000000007;

int main(){
  ll N,M;
  cin >> N >> M;
  string S,T;
  cin >> S >> T;
  ll g=1,l;
  while(true){
    l=N*g;
    if(l%M==0){
      break;
    }
    g ++;
  }
  g=N*M/l;
  for(ll i=0;i<g;i++){
    if(S[i*l/M]!=T[i*l/N]){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << l << endl;
}

