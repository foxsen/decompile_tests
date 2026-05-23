#include<bits/stdc++.h>
using namespace std;

#define int long long

#define INF (int)(1e17)
#define MAX 110000

int N, D;
int t[MAX], F[MAX];

signed main(){
  int num = 0, ans = 0;

  cin>>N>>D;

  for(int i = 0; i < N; i++){
    cin>>t[i]>>F[i];
  }
  t[N] = INF;
  F[N] = 1;

  if(t[0] < F[0]-1){
    cout<<-1<<endl;
    return 0;
  }
  for(int i = 0; i < N; i++){
    if(num + 1 > D){
      cout<<-1<<endl;
      return 0;
    } else num++;

    if(t[i+1] - t[i] < abs(F[i+1]-F[i])){
      cout<<-1<<endl;
      return 0;
    } else if(t[i+1]-t[i] >= F[i+1] + F[i] - 2){
      ans += num*(F[i]-1);
      num = 0;
    } else {
      ans += num*(t[i+1]-t[i]);
    }
  }

  cout<<ans<<endl;

  
  return 0;
}

