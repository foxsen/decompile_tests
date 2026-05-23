#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

template< typename flow_t >
struct FordFulkerson{
  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
  };

  vector<vector<edge>> graph;
  vector<int> used;
  const flow_t INF;

  FordFulkerson(int V):graph(V),used(V),INF(numeric_limits<flow_t>::max()) {}

  void add_edge(int from,int to,flow_t cap){
    graph[from].push_back((edge){to,cap,(int)graph[to].size(),false});
    graph[to].push_back((edge){from,0,(int)graph[from].size()-1,true});
  }

  flow_t dfs(int now,int t,flow_t f){
    if(now==t) return f;
    used[now]=true;
    for(int i=0;i<graph[now].size();i++){
      edge &e=graph[now][i];
      if(!used[e.to]&&e.cap>0){
        flow_t d=dfs(e.to,t,min(f,e.cap));
        if(d>0){
          e.cap-=d;
          graph[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(int s,int t){
    flow_t flow=0;
    for(;;){
      for(int i=0;i<graph.size();i++) used[i]=0;

      flow_t f=dfs(s,t,INF);
      if(f>0) flow+=f;
      else return flow;
    }
  }
};

const int N=2000;
const ll INF=1e9;

int main(){
  int R,C;
  cin>>R>>C;
  vector<string> S(R);
  rep(i,R) cin>>S[i];

  FordFulkerson<ll> graph(N);
  int s=R*C,t=s+1;
  int cnt=t+1;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(S[i][j]=='.') continue;
      graph.add_edge(s,i*C+j,1);
      graph.add_edge(i*C+j,t,1);
    }
  }

  int ans=0;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(S[i][j]=='.') continue;
      if(i+1<R&&S[i+1][j]=='#'){
        ans--;
        graph.add_edge(cnt,t,1);
        graph.add_edge(s,cnt,0);
        graph.add_edge(i*C+j,cnt,INF);
        graph.add_edge((i+1)*C+j,cnt,INF);
        cnt++;
      }
      if(j+1<C&&S[i][j+1]=='#'){
        ans--;
        graph.add_edge(cnt,t,0);
        graph.add_edge(s,cnt,1);
        graph.add_edge(cnt,i*C+j,INF);
        graph.add_edge(cnt,i*C+j+1,INF);
        cnt++;
      }
    }
  }

  ans+=graph.max_flow(s,t);
  cout<<ans<<endl;
  

  return 0;
}
