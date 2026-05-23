#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
  ll n,m,ans=0;
  cin>>n>>m;
  if (n<m) {
    vll x(m);
    for (ll i=0;i<m;i++) cin >> x[i];
    sort(x.begin(),x.end());
    vll dif(m-1);
    for (ll i=0;i<m-1;i++) dif[i]=x[i+1]-x[i];
    sort(dif.begin(),dif.end());
    for (ll i=0;i<m-n;i++) ans += dif[i];
  }
  cout << ans;
}