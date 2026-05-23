//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    string s;
    cin>>s;

    map<char,ll> mp;
    ll MOD = 998244353;
    ll ans = 1;
    FOR(i,0,3*n){
      vector<ll> v(3);
      v[0] = mp['R'];
      v[1] = mp['G'];
      v[2] = mp['B'];
      sortAlr(v);
      if(mp[s[i]] == v[0]){
        ans = ans*(n-mp[s[i]])%MOD;
      }
      else if(mp[s[i]] == v[1]){
        ans = ans*(v[0] - v[1])%MOD;
      }
      else{
        ans = ans*(v[1] - v[2])%MOD;
      }
      mp[s[i]]++;
    }
    cout<<ans<<endl;

}
