#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#define f first
#define s second
#define mp make_pair

using namespace std;

typedef vector<vector<int> > G;

int flow(G &g, int s, int d){
  int n = g.size();
  int ans = 0;

  while(true){
    vector<int> prevs(n,-1);
    queue<int> q;
    bool ok = false;
    
    prevs[s]=n;
    q.push(s);
    while(!q.empty()){
      int now = q.front();
      q.pop();
      if(now == d){
        ok = true;
        break;
      }
      for(int i=0;i<n;i++){
        if(g[now][i]>0){
          if(prevs[i]==-1){
            prevs[i]=now;
            q.push(i);
          }
        }
      }
    }

    if(!ok) return ans;

    int f = 100000;
    int pos = d;
    while(pos != s){
      int pos2 = prevs[pos];
      f = min(f,g[pos2][pos]);
      pos = pos2;
    }
    pos = d;
    while(pos != s){
      int pos2 = prevs[pos];
      g[pos2][pos]-=f;
      g[pos][pos2]+=f;
      pos = pos2;
    }
    ans += f;
  }
}

map<pair<int,int>, int> id;

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<vector<int> > g(n, vector<int>(n));

  REP(i,m){
    int a, b;
    scanf("%d%d", &a, &b);
    g[a-1][b-1] = 1;
    g[b-1][a-1] = 1;
    id[make_pair(a-1,b-1)] = i;
  }

  int s, t;
  scanf("%d%d", &s, &t);

  //REP(i,n){REP(j,n) printf("%2d ", g[i][j]); puts("");}

  int ans = flow(g, s-1, t-1);
  vector<int> rev;

  //REP(i,n){REP(j,n) printf("%2d ", g[i][j]); puts("");}

  REP(i,n) REP(j,n) if(g[i][j] == 2){
    if(id.count(make_pair(i,j))) rev.push_back(id[make_pair(i,j)] + 1);
  }
  sort(rev.begin(), rev.end());

  printf("%d\n", ans);
  printf("%d\n", rev.size());
  REP(i,rev.size()) printf("%d\n", rev[i]);

  return 0;
}