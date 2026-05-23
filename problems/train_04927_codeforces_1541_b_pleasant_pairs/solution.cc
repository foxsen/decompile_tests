#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define maxn 200005
#define inf 1e9
#define maxi LONG_LONG_MAX
#define mini LONG_LONG_MIN
#define sz(x) (x).size()
#define ed(x) (x).end()
#define contains(v,i) (v.find(i)!=v.end())
#define grt_sort(x) sort(x.begin(),x.end(),greater<>())
#define pll pair<ll,ll>
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main()
{
    flash

    ll t;
    cin>>t;

    while(t--){
      ll n;
      cin>>n;

      vector<pll> v;

      for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        v.pb({x,i+1});
      }

      sort(v.begin(),v.end());
      ll cnt=0;

      for(ll i=n-1;i>=0;i--){
        for(ll j=0;j<i;j++){
          if((v[i].first * v[j].first)>(2*n-1))
            break;

          if((v[i].first * v[j].first)==(v[i].second+v[j].second))
              cnt++;
        }
      }

      cout<<cnt<<"\n";
    }
}
