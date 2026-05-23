#include<bits/stdc++.h>

using namespace std;

struct StronglyConnectedComponents
{
  vector< vector< int > > gg, rg;
  vector< pair< int, int > > edges;
  vector< int > comp, order, used;

  StronglyConnectedComponents(size_t v) : gg(v), rg(v), comp(v, -1), used(v, 0) {}

  void add_edge(int x, int y)
  {
    gg[x].push_back(y);
    rg[y].push_back(x);
    edges.emplace_back(x, y);
  }

  int operator[](int k)
  {
    return (comp[k]);
  }

  void dfs(int idx)
  {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt)
  {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(vector< vector< int > > &t)
  {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    set< pair< int, int > > connect;
    for(auto &e : edges) {
      int x = comp[e.first], y = comp[e.second];
      if(x == y) continue;
      if(connect.count({x, y})) continue;
      t[x].push_back(y);
      connect.emplace(x, y);
    }
  }
};

int N, M;
int A[200][2], B[200][2];
int X[15], Y[15];
double g[200][2][200][2];

int main()
{
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 2; j++) {
      cin >> A[i][j] >> B[i][j];
    }
  }
  for(int i = 0; i < M; i++) {
    cin >> X[i] >> Y[i];
  }

  fill_n(***g, 200 * 2 * 200 * 2, 1e9);
  for(int i = 0; i < M; i++) {
    vector< vector< double > > dp(M, vector< double >(1 << M, 1e9));
    dp[i][1 << i] = 0.0;
    for(int j = 0; j < (1 << M); j++) {
      for(int k = 0; k < M; k++) {
        for(int l = 0; l < M; l++) {
          dp[l][j | (1 << l)] = min(dp[l][j | (1 << l)], dp[k][j] + sqrt(pow(X[k] - X[l], 2) + pow(Y[k] - Y[l], 2)));
        }
      }
    }
    for(int z = 0; z < M; z++) {
      for(int j = 0; j < N; j++) {
        for(int k = 0; k < 2; k++) {
          for(int l = 0; l < N; l++) {
            for(int m = 0; m < 2; m++) {
              double latte = sqrt(pow(A[j][k] - X[i], 2) + pow(B[j][k] - Y[i], 2));
              double malta = sqrt(pow(A[l][m] - X[z], 2) + pow(B[l][m] - Y[z], 2));
              g[j][k][l][m] = min(g[j][k][l][m], latte + malta + dp[z].back());
            }
          }
        }
      }
    }
  }

  auto check = [&](double dist)
  {
    StronglyConnectedComponents scc(N + N);
    for(int i = 0; i < N; i++) {
      for(int j = i + 1; j < N; j++) {
        bool b1 = g[i][0][j][0] > dist;
        bool b2 = g[i][0][j][1] > dist;
        bool b3 = g[i][1][j][0] > dist;
        bool b4 = g[i][1][j][1] > dist;
        if(b1) scc.add_edge(i << 1, (j << 1) | 1), scc.add_edge(j << 1, (i << 1) | 1);
        if(b2) scc.add_edge(i << 1, j << 1), scc.add_edge((j << 1) | 1, (i << 1) | 1);
        if(b3) scc.add_edge((i << 1) | 1, (j << 1) | 1), scc.add_edge(j << 1, i << 1);
        if(b4) scc.add_edge((i << 1) | 1, j << 1), scc.add_edge((j << 1) | 1, i << 1);
      }
    }
    vector< vector< int > > g;
    scc.build(g);
    for(int i = 0; i < N; i += 2) if(scc[i] == scc[i + 1]) return (false);
    return (true);
  };


  double low = 0, high = 1e9;
  for(int i = 0; i < 100; i++) {
    double mid = (low + high) * 0.5;
    if(check(mid)) high = mid;
    else low = mid;
  }

  cout << fixed << setprecision(10) << high << endl;
}