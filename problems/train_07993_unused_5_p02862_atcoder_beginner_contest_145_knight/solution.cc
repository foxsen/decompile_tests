#include<bits/stdc++.h>
using namespace std;
int x,y;
const int N=1e6+9;
const int mod=1e9+7;
int inv[N],frac[N];
void init(){
  frac[0]=frac[1]=inv[0]=inv[1]=1;
  for(int i=2;i<N;i++)frac[i]=1ll*i*frac[i-1]%mod,
  inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
  for(int i=2;i<N;i++)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
int C(int x,int y){
  return 1ll*frac[x]*inv[x-y]%mod*inv[y]%mod;
}
int main(){
  init();
  cin>>x>>y;
  int t=(x+y)/3;
  int ans=0;
  if(x>=t&&x<=2*t&&((x+y)%3==0))ans=C(t,x-t);
  cout<<ans<<endl;
}
