#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

struct StronglyConnectedComponents
{
  int n;
  vector<vector<int>> oG, rG;
  vector<int> comp, order, used;
  vector<pair<int, int>> edges;

  StronglyConnectedComponents (int n) : n(n), oG(n), rG(n), comp(n, -1), used(n, 0) {}

  int operator[] (int k)
  {
    return comp[k];
  }

  void add_edge(int u, int v)
  {
    oG[u].push_back(v);
    rG[v].push_back(u);
    edges.emplace_back(u, v);
  }

  void dfs(int v)
  {
    if (used[v]) return;
    used[v] = true;
    for (int to : oG[v]) dfs(to);
    order.push_back(v);
  }

  void rdfs(int v, int k)
  {
    if (~comp[v]) return;
    comp[v] = k;
    for (int to : rG[v]) rdfs(to, k);
  }

  void build(vector<vector<int>> &t)
  {
    for (int i = 0; i < n; ++i) dfs(i);

    reverse(order.begin(), order.end());
    int k = 0;
    for (int i : order) if (comp[i] == -1) rdfs(i, k++);

    t.resize(k);
    set<pair<int, int>> connect;
    for (auto &e : edges) {
      int u = comp[e.first], v = comp[e.second];
      if (u == v || connect.count({u, v})) continue;
      t[u].push_back(v);
      connect.emplace(u, v);
    }
  }
};

/*
StronglyConnectedComponents(g):= グラフ g で初期化する。
build(t):= 強連結成分分解をする。強連結成分の番号はトポロジカル順に昇順にふられる。
tには強連結成分ごとに縮約したグラフが格納される(多重辺が生えるので注意)。
[k] := 頂点 k が属する強連結成分の番号を返す。

int main() {
  int n, m;
  cin >> n >> m;

  StronglyConnectedComponents scc(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    scc.add_edge(u, v);
  }

  vector<vector<int>> G;
  scc.build(G);

  int q;
  cin >> q;
  while (q--) {
    int s, t;
    cin >> s >> t;
    cout << (scc[s] == scc[t]) << endl;
  }
}
*/
void solve(int n){
  double a[n];
  StronglyConnectedComponents scc(n);

  rep(i,n){
    cin >> a[i];
    int x;
    cin >> x;
    rep(j,x){
      int y;
      cin >> y;
      y--;
      scc.add_edge(i,y);
    }
  }

  VVI G;
  scc.build(G);
  // rep(i,scc.comp.size()) cout << i << ": " << scc.comp[i] << endl;
  vector<double> p(G.size(),1.);
  rep(i,scc.comp.size()){
    p[scc.comp[i]] *= a[i];
  }
  double ans = 1.;
  bool up[G.size()];
  memset(up,true,sizeof(up));
  rep(i,G.size()){
    rep(j,G[i].size()){
      up[G[i][j]] = false;
    }
  }

  rep(i,G.size()) if(up[i]) ans *= (1. - p[i]);
  printf("%0.9lf\n",ans);
}
int main(){

  int n;
  while(cin >> n, n){
    solve(n);
  }
  return 0;
}

