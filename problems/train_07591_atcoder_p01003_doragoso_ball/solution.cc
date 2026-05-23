#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> P2;

int n,m,l,k;
int u,v,c;
int s,g,t;
int b[7];

int dis[51][1<<7][10],vis[51][1<<7];
vector<P> G[51];
const int INF = 100000000;

int main(){
  while(cin >> n >> m >> l >> k,n+m+l+k){
    for(int i=1;i<=n;i++)G[i].clear();
    for(int i=0;i<m;i++){
      cin >> u >> v >> c;
      G[u].push_back(P(c,v));
      G[v].push_back(P(c,u));
    }
    cin >> s >> g;
    for(int i=0;i<l;i++)cin >> b[i];

    for(int i=1;i<=n;i++)
      for(int j=0;j<(1<<l);j++){
	for(int x=0;x<k;x++)dis[i][j][x] = INF;
	vis[i][j] = 0;
      }

    int st = 0;
    for(int i=0;i<l;i++)if(s==b[i])st |= 1<<i;

    priority_queue< P2,vector<P2>,greater<P2> > q;
    q.push(P2(0,P(s,st)));
    
    while(q.size()){
      P2 p = q.top(); q.pop();
      int dist = p.first, pos = p.second.first, state = p.second.second;

      if(vis[pos][state] < k){
	dis[pos][state][vis[pos][state]] = dist;
	vis[pos][state]++;
      }else continue;

      for(int i=0;i<G[pos].size();i++){
	int cost = G[pos][i].first, nxt = G[pos][i].second;
	int nstate = state;
	for(int j=0;j<l;j++)if(nxt==b[j])nstate |= 1<<j;

	if(vis[nxt][nstate] < k)q.push(P2(dist+cost,P(nxt,nstate)));
      }
    }
    int res = dis[g][(1<<l)-1][k-1];
    if(res==INF)cout << "NA\n";
    else cout << res << endl;
  }
}
      