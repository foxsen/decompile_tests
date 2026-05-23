#include<bits/stdc++.h>
#define MAX 2001
#define inf 1<<29
#define linf (1e16)
#define eps (1e-8)
#define Eps (1e-12)
#define mod 1000000007
#define pi acos(-1.0)
#define phi (1.0+sqrt(5.0))/2.0
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10f\n",(double)(a))
#define pld(a) printf("%.10Lf\n",(ld)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a)-1;(b)<=i;i--)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define equals(a,b) (fabs((a)-(b))<eps)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

struct edge{ ll to,cap,cost,rev; };

int v;
vector<edge> e[MAX];
ll h[MAX];
ll dist[MAX];
ll prevv[MAX],preve[MAX];

void add_edge(int from,int to,ll cap,ll cost){
  e[from].push_back((edge){to,cap,cost,(ll)e[to].size()});
  e[to].push_back((edge){from,0,-cost,(ll)e[from].size()-1});
}
 
ll min_cost_flow(ll s,ll t,ll f){
  ll res=0;
  fill(h,h+v,0);
  fill(prevv,prevv+MAX,0);
  fill(preve,preve+MAX,0);
  while(f>0){
    priority_queue<pll,vector<pll>,greater<pll> > pq;
    fill(dist,dist+v,linf);
    dist[s]=0;
    pq.push(pll(0,s));
    while(pq.size()){
      pll p=pq.top();
      pq.pop();
      int u=p.second;
      if(dist[u]<p.first)continue;
      for(int i=0;i<e[u].size();i++){
        edge &E=e[u][i];
        if(E.cap>0 && dist[E.to]>dist[u]+E.cost+h[u]-h[E.to]){
          dist[E.to]=dist[u]+E.cost+h[u]-h[E.to];
          prevv[E.to]=u;
          preve[E.to]=i;
          pq.push(pll(dist[E.to],E.to));
        }
      }
    }
    if(dist[t]==linf)return -1;
    for(int i=0;i<v;i++)h[i]+=dist[i];
 
    ll d=f;
    for(int u=t;u!=s;u=prevv[u]){
      d=min(d,e[prevv[u]][preve[u]].cap);
    }
    f-=d;
    res+=d*h[t];
    for(int u=t;u!=s;u=prevv[u]){
      edge &E=e[prevv[u]][preve[u]];
      E.cap-=d;
      e[u][E.rev].cap+=d;
    }
  }
  return res;
}


ll n,k,flow=0;
vector<pii> E[MAX];
ll ind[MAX],outd[MAX];
ll cost[MAX][MAX];

void dijkstra(int root){
  priority_queue<pll,vector<pll>,greater<pll> > pq;
  cost[root][root]=0;
  pq.push(mp(0,root));

  while(pq.size()){
    pll u=pq.top();
    pq.pop();

    if(cost[root][u.s]<u.f)continue;

    FOR(i,0,E[u.s].size()){
      int next=E[u.s][i].f;
      ll c = cost[root][u.s]+E[u.s][i].s;
      if(c<cost[root][next]){
        cost[root][next]=c;
        pq.push(mp(c,next));
      }
    }
  }
}

ll solve(){
  ll ans = 0;
  fill(ind,ind+MAX,0);
  fill(outd,outd+MAX,0);
  FOR(i,0,MAX)fill(cost[i],cost[i]+MAX,inf);
  FOR(i,0,n){
    outd[i] = E[i].size();
    FOR(j,0,E[i].size()){
      ind[E[i][j].f]++;
      ans+=E[i][j].s;
    }
  }
  FOR(i,0,n)dijkstra(i);
  vector<pii> L,R;
  FOR(i,1,n){
    if(outd[i]==0)continue;
    if(outd[i]<ind[i])L.pb(mp(i,ind[i]-outd[i]));
    if(ind[i]<outd[i]){
      R.pb(mp(i,outd[i]-ind[i]));
      flow+=(outd[i]-ind[i]);
    }
  }
  int s=L.size()+R.size(),t=s+1,u=t+1;
  v = u+1;
  FOR(i,0,L.size()){
    FOR(j,0,R.size()){
      int a = L[i].f, b = R[j].f;
      if(cost[a][b]==inf)continue;
      add_edge(i,j+L.size(),R[j].s,cost[a][b]);
    }
  }
  FOR(i,0,L.size())add_edge(s,i,L[i].s,0);
  FOR(i,0,R.size())add_edge(i+L.size(),t,R[i].s,0);
  add_edge(s,u,inf,0);
  FOR(i,0,R.size())add_edge(u,i+L.size(),R[i].s,cost[0][R[i].f]);
  ll res = min_cost_flow(s,t,flow);
  return ans+res;
}

int main()
{
  cin>>n;
  FOR(i,0,n){
    cin>>k;
    FOR(j,0,k){
      ll a,b;
      cin>>a>>b;
      E[i].pb(mp(a-1,b));
    }
  }
  cout<<solve()<<endl;
  return 0;
}

