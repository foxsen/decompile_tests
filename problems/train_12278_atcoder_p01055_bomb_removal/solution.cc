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

#define INF 1e16
#define mod 1000000007

ll W,H,N;
ll sx,sy;
vector<P> ps[5];
map<P,bool> dame;

bool vis[20][20][50][1<<5];
ll di[]={-1,-1,-1,0,0,1,1,1,0};
ll dj[]={-1,0,1,-1,1,-1,0,1,0};

struct state{
  ll i,j,t,S;
};

int main(){
  cin>>W>>H>>N;
  cin>>sx>>sy;
  sx--;sy--;
  rep(i,N){
    int tmp;
    cin>>tmp;
    rep(j,tmp){
      int a,b;
      cin>>b>>a;
      a--;b--;
      ps[i].push_back(P(a,b));
    }
    dame[ps[i][tmp-1]]=true;
  }

  queue<state> que;
  vis[sy][sx][0][0]=true;
  que.push((state){sy,sx,0,0});
  while(que.size()){
    state crt=que.front(); que.pop();

    ll nS=crt.S;
    rep(i,N){
      if(crt.t<(ll)ps[i].size()&&ps[i][crt.t]==P(crt.i,crt.j))nS|=(1<<i);
    }
    if(!vis[crt.i][crt.j][crt.t][nS]){
      vis[crt.i][crt.j][crt.t][nS]=true;
      que.push((state){crt.i,crt.j,crt.t,nS});
    }

    rep(dir,9){
      ll ni=crt.i+di[dir],nj=crt.j+dj[dir];
      if(ni>=0&&ni<H&&nj>=0&&nj<W&&crt.t+1<50&&!dame[P(ni,nj)]&&!vis[ni][nj][crt.t+1][crt.S]){
        vis[ni][nj][crt.t+1][crt.S]=true;
        que.push((state){ni,nj,crt.t+1,crt.S});
      }
    }
  }

  rep(t,50){
    rep(i,H)rep(j,W){
      if(vis[i][j][t][(1<<N)-1]){
        cout<<t<<endl;
        return 0;
      }
    }
  }
  cout<<-1<<endl;

  return 0;
}

