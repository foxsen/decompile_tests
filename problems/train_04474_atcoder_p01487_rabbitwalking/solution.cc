#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

vector<int> v[111111];
vector<P> p;
int u[111111][2],c[2];

void dfs(int x,int t) {
  if(u[x][t]) return;
  c[t]++;
  u[x][t]=1;
  for(int i=0; i<v[x].size(); i++) dfs(v[x][i],t^1);    
}

bitset<100001> t;

int main() {
  int n,m;
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    int x,y;
    cin >> x >> y;
    x--,y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=0; i<n; i++) {
    if(u[i][0]||u[i][1]) continue;
    c[0]=c[1]=0;
    dfs(i,0);
    if(c[0]<c[1]) swap(c[0],c[1]);
    p.push_back(P(c[0],c[1]));
  }
  for(int i=0; i<n; i++) {
    if(u[i][0]&&u[i][1]) {
      cout << -1 << endl;
      return 0;
    }
  }
  t.set(0);
  for(int i=0; i<p.size(); i++) {
    t=(t<<p[i].first)|(t<<p[i].second);
  }
  ll ans=0;
  for(ll i=0; i<=n; i++) {
    if(t[i]) ans=max(ans,i*(n-i)-m);
  }
  cout << ans << endl;
  return 0;
}
