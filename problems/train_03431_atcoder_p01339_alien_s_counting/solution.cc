#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) begin(x),end(x)

using namespace std;

#define MAX_V 1024

vector<int> g[MAX_V], rg[MAX_V], vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to) {
  g[from].push_back(to);
  rg[to].push_back(from);
}

void dfs(int v) {
  used[v] = true;
  for (int i : g[v]) if (!used[i]) dfs(i);
  vs.push_back(v);
}

void rdfs(int v, int k) {
  used[v] = true; cmp[v] = k;
  for (int i : rg[v]) if (!used[i]) rdfs(i, k);
}

int scc(int V) {
  memset(used, 0, sizeof(used));
  vs.clear();
  REP(v, V) if (!used[v]) dfs(v);
  memset(used, 0, sizeof(used));
  reverse(ALL(vs));
  int k = 0;
  for (int i : vs) if (!used[i]) rdfs(i, k++);
  return k;
}

vector<vector<int>> buildGraph(int V, int K) {
  vector<set<int>> s(K);
  vector<vector<int>> res(K,vector<int>(K));
  REP(i,V) for (int j : g[i]) s[cmp[i]].insert(cmp[j]);
  REP(i,K) for (int j : s[i]) ++res[i][j];
  return res;
}

void dfs2(vector<vector<int>>& dag, int i, vector<int64_t>& dp, vector<bool>& vis) {
  int n=dag.size();
  vis[i] = true;
  REP(j,n) {
    if (dag[j][i]==0)continue;
    if (j==i) continue;
    if (!vis[j])
      dfs2(dag, j, dp, vis);
    dp[i] *= dp[j];
    dp[i] %= 1000000007;
  }
  ++dp[i];
  dp[i] %= 1000000007;
}

int main() {
  int n,m;
  cin>>n>>m;
  REP(i,m){
    int s,d;
    cin>>s>>d;
    --s;--d;
    add_edge(s,d);
  }
  int k = scc(n);
  auto dag = buildGraph(n, k);
  vector<int64_t> dp(k, 1);
  vector<bool> vis(k);
  int64_t sum = 1;
  REP(i,k) {
    if(!vis[i]) {
      bool ok = true;
      REP(j,k){
        if(j==i)continue;
        if(dag[i][j] != 0){
          ok=false;
          break;
        }
      }
      if (ok) {
        dfs2(dag, i, dp, vis);
        sum *= dp[i];
        sum %= 1000000007;
      }
    }
  }
  cout<<sum<<endl;
  return 0;
}