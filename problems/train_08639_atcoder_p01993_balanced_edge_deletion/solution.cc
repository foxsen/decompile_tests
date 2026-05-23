#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)

int n,m;
vector<pii> g[125252];

// スパソを写経しました
vector<pii> bridges;
vector<vector<int>> islands;
int num[125252];
bool inS[125252];
stack<int> roots, S;
int tim = 0;
void visit(int v,int u){
  num[v] = ++tim;
  S.push(v);inS[v]=true;
  roots.push(v);
  for(pii P : g[v]){
    int to = P.first;
    if(num[to]==0){
      visit(to,v);
    }else if(u!=to && inS[to]){
      while(num[roots.top()] > num[to])roots.pop();
    }
  }
  if(v == roots.top()){
    bridges.push_back(pii(u,v));
    islands.push_back(vector<int>());
    while(1){
      int w = S.top(); S.pop(); inS[w] = false;
      islands.back().push_back(w);
      if(v==w)break;
    }
    roots.pop();
  }
}
void bridge(){
  REP(u,n)if(num[u]==0){
    visit(u,n);
    bridges.pop_back();
  }
}

int mp[125252];
ll wsum[125252];
ll wall;
vector<pii> g2[125252];

ll mini = 1e18;
set<pii> SS;

ll csum[125252];

void dfs(int p, int bef){
  csum[p] += wsum[p];
  for(pii P : g2[p]){
    int to = P.first;
    ll w = P.second;
    if(to == bef)continue;
    dfs(to, p);
    csum[p] += csum[to] + w;
    ll cost = abs(csum[to] - (wall - csum[to] - w));
    if(cost < mini){
      mini = cost;
      SS.clear();
    }
    if(cost == mini){
      SS.insert(pii(min(p,to),max(p,to)));
    }
  }
}

int n2 = islands.size();

int main(){
  scanf("%d%d",&n,&m);
  wall = 0;
  REP(i,m){
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    --u;--v;
    g[u].push_back(pii(v,w));
    g[v].push_back(pii(u,w));
    wall += w;
  }
  bridge();
  // oh じゃあないんだよ
  // if(islands.size()==1){
  //   // oh
  //   int ansu = n+1, ansv = n+1;
  //   REP(i,n)for(pii P : g[i]){
  //     int j = P.first;
  //     if(i>j)continue;
  //     if(i<ansu || (i==ansu && j<ansv)){
  //       ansu = i;
  //       ansv = j;
  //     }
  //   }
  //   printf("%d %d\n",ansu+1,ansv+1);
  //   return 0;
  // }
  REP(i,islands.size()){
    for(int x : islands[i]){
      mp[x] = i;
    }
  }
  REP(i,n)for(pii P : g[i]){
    int to = P.first;
    int w = P.second;
    if(i>to)continue;
    if(mp[i]==mp[to]){
      wsum[mp[i]] += w;
    }else{
      g2[mp[i]].push_back(pii(mp[to], w));
      g2[mp[to]].push_back(pii(mp[i], w));
    }
  }
  dfs(0,-1);
  int ansu = n+1, ansv = n+1;
  REP(i,n)for(pii P : g[i]){
    int to = P.first;
    int w = P.second;
    if(i>to)continue;
    if(mp[i]==mp[to]){
      continue;
    }else{
      pii Q = pii(min(mp[i],mp[to]),max(mp[i],mp[to]));
      if(SS.count(Q)){
        if(i<ansu || (i==ansu && to<ansv)){
          ansu = i;
          ansv = to;
        }
      }
    }
  }
  REP(i,n)for(pii P : g[i]){
    int to = P.first;
    int w = P.second;
    if(i>to)continue;
    ll cost = wall-w;
    if(cost < mini){
      mini = cost;
      ansu = i;
      ansv = to;
    }else if(cost == mini){
      if(i<ansu || (i==ansu && to<ansv)){
        ansu = i;
        ansv = to;
      }
    }
  }
  printf("%d %d\n",ansu+1,ansv+1);
  return 0;
}

