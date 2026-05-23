#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 5e18
#define mod 1000000007

struct edge{
  ll v,a,b;
};
struct state{
  ll v,d;
};
bool operator<(const state& a,const state& b){
  return a.d > b.d;
}

ll N,M,S,G;
vector<edge> g[200010];
ll dist[200010];

int main(){
  cin>>N>>M>>S>>G;
  S--;G--;

  rep(i,M){
    ll u,v,a,b;
    cin>>u>>v>>a>>b;
    u--;v--;
    g[u].push_back((edge){v,a,b});
    g[v].push_back((edge){u,a,b});
  }

  priority_queue<state> que;
  que.push((state){S,0});
  rep(i,N)dist[i]=INF;
  while(que.size()){
    state crt=que.top(); que.pop();
    if(dist[crt.v]!=INF)continue;
    dist[crt.v]=crt.d;
    ll v=crt.v; ll t=crt.d;
    for(edge e : g[v]){
      ll k=max(0LL,(ll)floor(sqrt((double)e.b))-e.a-t);
      rep(add,3){
        ll nk=k+add;
        que.push((state){e.v,t+nk+((e.b+t+nk+e.a-1)/(t+nk+e.a))});
      }
    }
  }

  if(dist[G]==INF)cout<<-1<<endl;
  else cout<<dist[G]<<endl;

  return 0;
}

