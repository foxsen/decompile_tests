#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int cnt[31][100001] = {0};
int main(){
  int N,C;
  cin>>N>>C;
  for(int i(0);i<N;i++){
    int s,t,c;
    cin>>s>>t>>c;
    for(int j(s);j<=t;j++){
      cnt[c][j] = 1;
    }
  }
  int ans(0);
  for(int i(0);i<=100000;i++){
    int tmp(0);
    for(int j(1);j<=C;j++){
      if(cnt[j][i] == 1) tmp++;
    } 
    ans = max(ans,tmp);
  }
  cout << ans << endl;
  return 0;
}

