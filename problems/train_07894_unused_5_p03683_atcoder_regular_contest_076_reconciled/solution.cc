#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;
ll fact(ll num){
  if(num==1) return 1;
  else return ll(num*(fact(num-1)%ll(1e9+7)))%ll(1e9+7);
}
int main(){
  ll n, m;cin>>n>>m;
  if(n>m)swap(n, m);
  if(m-n>1)cout<<0<<endl;
  else if(n==m)cout<<(((fact(n)*fact(n))%ll(1e9+7))*2)%ll(1e9+7)<<endl;
  else cout<<(((fact(n)*fact(n))%ll(1e9+7))*m)%ll(1e9+7)<<endl;
}