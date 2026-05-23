#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;

const ll N=2e5+10;
vector<map<ll,ll>> si(N),dp(N);
vector<set<ll>> G(N);
ll n;

ll mpow(ll x, ll n) {
  ll ans=1;
  while(n>0) {
    if(n&1) {
      ans=ans*x%mod;
    }
    x=x*x%mod;
    n>>=1;
  }
  return ans;
}

vec tfact(1e7+1);
void fact(ll n) {
  for(ll i=0;i<=n;i++) {
    if(i==0) {
      tfact[i]=1;
    }
    else {
      tfact[i]=tfact[i-1]*i%mod;
    }
  }
}

ll dfs1(ll f, ll ff) {
  if(si[f][ff]) return si[f][ff];
  ll res=0;
  for(auto p:G[f]) {
    if(p==ff) continue;
    res+=dfs1(p,f);
  }
  if(ff) si[ff][f]=n-res-1;
  return si[f][ff]=res+1;
}

ll dfs2(ll f,ll ff) {
  if(dp[f][ff]) return dp[f][ff];
  ll res=1;
  if(dp[f][0]) {
    res=dp[f][0];
    (res*=mpow(dfs2(ff,f),mod-2)*tfact[dfs1(ff,f)]%mod)%=mod;
    (res*=mpow(tfact[dfs1(f,0)-1],mod-2))%=mod;
  }
  else {
    for(auto p:G[f]) {
      if(p==ff) continue;
      (res*=dfs2(p,f)*mpow(tfact[dfs1(p,f)],mod-2)%mod)%=mod;
    }
  }
  (res*=tfact[dfs1(f,ff)-1])%=mod;
  return dp[f][ff]=res;
}

void bfs(ll f) {
  queue<ll> q;
  q.push(f);
  while(q.size()) {
    ll n=q.front();
    q.pop();
    dfs2(n,0);
    for(auto p:G[n]) {
      if(dp[p][0]) continue;
      q.push(p);
    }
  }
}

int main() {
  cin >> n;
  for(ll i=0;i<n-1;i++) {
    ll a,b;
    cin >> a >> b;
    G[a].insert(b);
    G[b].insert(a);
  }
  fact(N);
  bfs(1);
  for(ll i=1;i<=n;i++) {
    cout << dfs2(i,0) << endl;
  }
}