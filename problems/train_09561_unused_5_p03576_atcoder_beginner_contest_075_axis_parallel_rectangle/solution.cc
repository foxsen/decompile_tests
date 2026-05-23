#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const ll inf=5e18;

int main() {
  ll n,K;
  cin >> n >> K;
  vec x(n),y(n);
  for(ll i=0;i<n;i++) {
    cin >> x[i] >> y[i];
  }
  ll ans=inf;
  for(ll i=0;i<n;i++) {
    for(ll j=i+1;j<n;j++) {
      for(ll k=0;k<n;k++) {
        for(ll l=k+1;l<n;l++) {
          ll count=0;
          ll hh=max(y[i],y[j]);
          ll lh=min(y[i],y[j]);
          ll hw=max(x[k],x[l]);
          ll lw=min(x[k],x[l]);
          for(ll m=0;m<n;m++) {
            if(hh>=y[m]&&lh<=y[m]&&hw>=x[m]&&lw<=x[m]) count++;
          }
          if(count>=K) {
            ans=min(ans,(hh-lh)*(hw-lw));
          }
        }
      }
    }
  }
  cout << ans << endl;
}