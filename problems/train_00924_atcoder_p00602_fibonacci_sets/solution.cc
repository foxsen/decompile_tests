#include<bits/stdc++.h>
#define N 1005
#define M 1001
#define P 30
using namespace std;
typedef long long ll;

int main(){
  int v,d;
  ll f[N];
  vector<ll> F;
  while(cin>>v>>d){
    f[0]=f[1]=1;
    for(int i=2;i<2+v;i++){
      f[i]=(f[i-1]+f[i-2])%M;
      F.push_back(f[i]);
    }
    sort(F.begin(),F.end());
    int ans=0;
    for(int i=1;i<F.size();i++){
      if(abs(F[i]-F[i-1])>=d)ans++;
    }
    cout<<ans+1<<endl;
    F.clear();
  }
  return 0;
}