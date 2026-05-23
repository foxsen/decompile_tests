#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<ll,ll> P;
const int N=111111;
vector<ll> v[N],v2[N];
ll d[N],ord[N],low[N],c[N],u[N];
set<P> s;

void dfs(int x,int p,int &c,vector<P> &B){
  ord[x]=low[x]=c++;
  for(int i=0;i<v[x].size();i++){
    int y=v[x][i];
    if(y==p) continue;
    if(ord[y]==-1){
      dfs(y,x,c,B);
      low[x]=min(low[x],low[y]);
    } else low[x]=min(low[x],ord[y]);
    if(ord[x]<low[y]) B.push_back(P(x,y));
  }
}

void bridge(int n,vector<P> &B){
  B.clear();
  int c=0;
  fill(ord,ord+n,-1);
  for(int i=0;i<n;i++)if(ord[i]==-1)dfs(i,-1,c,B);
}

int p[N],r[N];
void init(){for(int i=0;i<N;i++)p[i]=i,r[i]=0;}
int find(int x){return (p[x]==x)?x:(p[x]=find(p[x]));}
void unite(int x,int y) {
  x=find(x),y=find(y);
  if(x==y)return;
  if(r[x]<r[y])p[x]=y;
  else{p[y]=x;if(r[x]==r[y])r[x]++;}
}
bool same(int x,int y){return find(x)==find(y);}

P dfs(ll x,ll r) {
  u[x]=1;
  P p=P(0,0);
  for(int i=0; i<v2[x].size(); i++) {
    ll y=v2[x][i];
    if(y==r) continue;
    P q=dfs(y,x);
    p.F+=q.S;
    p.S+=max(q.F,q.S);
  }
  p.F+=d[x];
  return p;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  init();
  ll n,m;
  cin >> n >> m;
  for(ll i=0; i<m; i++) {
    ll x,y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=0; i<n; i++) {
    sort(v[i].begin(),v[i].end());
    v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
  }
  vector<P> g;
  bridge(n,g);
  for(int i=0; i<g.size(); i++) {
    if(g[i].F>g[i].S) swap(g[i].F,g[i].S);
    s.insert(g[i]);
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<v[i].size(); j++) {
      int x=i,y=v[i][j];
      if(x>y) swap(x,y);
      if(s.count(P(x,y))) continue;
      unite(x,y);
    }
  }
  for(int i=0; i<n; i++) d[find(i)]++;
  for(int i=0; i<g.size(); i++) {
    int x=find(g[i].F),y=find(g[i].S);
    v2[x].push_back(y);
    v2[y].push_back(x);
  }
  for(int i=0; i<n; i++) {
    sort(v2[i].begin(),v2[i].end());
    v2[i].erase(unique(v2[i].begin(),v2[i].end()),v2[i].end());
  }
  int ans=0;
  for(int i=0; i<n; i++) {
    if(!u[i]) {
      P q=dfs(i,-1);
      ans+=max(q.F,q.S);
    }
  }
  cout << ans << endl;
  return 0;
}
