#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
ll best[3030][3030], a[3030], N, S;

int main() {
  cin>>N>>S;
  for(int i=1;i<=N;++i) {
    cin>>a[i];
  }
  best[0][0] = 1;
  for(int i=1;i<=N;++i) {
    for(int j=0;j<=S;++j) {
      best[i][j] = 2LL*best[i-1][j];
      if(j >= a[i]) {
        best[i][j] += best[i-1][j-a[i]];
      }
      best[i][j] %= MOD;
    }
  }
  
  cout<<best[N][S]<<"\n";
  return 0;
} 
