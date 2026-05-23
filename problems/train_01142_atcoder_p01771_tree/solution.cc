#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define int long long
struct LCA {
  int N, logN;
  vector<vector<int>> G;
  vector<int> depth;
  vector<vector<int>> parent;
  LCA(int size) : N(size), G(size), depth(size) {
    logN = 0;
    for(int x = 1; x < N; x *= 2) logN++;
    parent.assign(max<int>(logN, 1), vector<int>(N));
  }
  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }
  void build() {
    queue<pair<int, int>> Q;
    Q.emplace(0, -1);
    while(!Q.empty()) {
      pair<int, int> p = Q.front(); Q.pop();
      int cur = p.first, prev = p.second;
      parent[0][cur] = prev;
      if(prev == -1) depth[cur] = 0;
      else depth[cur] = depth[prev] + 1;
      for(int next : G[cur]) {
        if(next != prev) Q.emplace(next, cur);
      }
    }
    for(int k = 1; k < logN; k++) {
      for(int v = 0; v < N; v++) {
        if(parent[k - 1][v] == -1) parent[k][v] = -1;
        else parent[k][v] = parent[k - 1][parent[k - 1][v]];
      }
    }
  }
  int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = 0; k < logN; k++) {
      if(((depth[v] - depth[u]) >> k) & 1) {
        v = parent[k][v];
      }
    }
    if(u == v) return u;
    for(int k = logN - 1; k >= 0; k--) {
      if(parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};
const int sqrtN = 400;
struct SqrtDecomposition {
  int N, K;
  vector<int> data;
  vector<int> addpart;
  vector<int> addall;
  SqrtDecomposition(int n) : N(n) {
    K = (N + sqrtN - 1) / sqrtN;
    data.assign(K * sqrtN, 0);
    addpart.assign(K, 0);
    addall.assign(K, 0);
  }
  void put(int a, int b, int value) {
    for(int k = 0; k < K; ++k) {
      int l = k * sqrtN, r = (k + 1) * sqrtN;
      if(r <= a || b <= l) continue;
      if(a <= l && r <= b) {
        addall[k] += value;
      }
      else {
        for(int i = max(a, l); i < min(b, r); ++i) {
          data[i] += value;
          addpart[k] += value;
        }
      }
    }
  }
  int get(int a, int b) {
    int ret = 0;
    for(int k = 0; k < K; ++k) {
      int l = k * sqrtN, r = (k + 1) * sqrtN;
      if(r <= a || b <= l) continue;
      if(a <= l && r <= b) {
        ret += addall[k] * sqrtN + addpart[k];
      }
      else {
        for(int i = max(a, l); i < min(b, r); ++i) {
          ret += data[i] + addall[k];
        }
      }
    }
    return ret;
  }
};
const int MAX_N = 150000;
int IN[MAX_N], IN2[MAX_N], OUT[MAX_N], OUT2[MAX_N];
int in, out;
vector<vector<int>> G;
void dfs() {
  stack<pair<int, pair<int, int>>> S;
  S.push(make_pair(+1, make_pair(0, -1)));
  while(!S.empty()) {
    pair<int, pair<int, int>> pp = S.top(); S.pop();
    int t = pp.first, cur = pp.second.first, prev = pp.second.second;
    if(t == +1) {
      IN[cur] = in++;
      IN2[cur] = out;
      S.push(make_pair(-1, make_pair(cur, prev)));
      for(int next : G[cur]) {
        if(next != prev) {
          S.push(make_pair(+1, make_pair(next, cur)));
        }
      }
    }
    else {
      OUT[cur] = out++;
      OUT2[cur] = in;
    }
  }
}
signed main() {
  int N, Q; scanf("%lld %lld", &N, &Q);
  G.resize(N);
  LCA lca(N);
  REP(i,N-1) {
    int a, b; scanf("%lld %lld", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
    lca.add_edge(a, b);
  }
  lca.build();
  in = 0, out = 0;
  dfs();
  SqrtDecomposition plus(N);
  SqrtDecomposition minus(N);
  REP(q,Q) {
    int t, a, b; scanf("%lld %lld %lld", &t, &a, &b);
    if(!t) {
      int c = lca.lca(a, b);
      int d1 = plus.get(0, IN[a] + 1) - minus.get(0, IN2[a]);
      int d2 = plus.get(0, IN[b] + 1) - minus.get(0, IN2[b]);
      int d3 = plus.get(0, IN[c] + 1) - minus.get(0, IN2[c]);
      printf("%lld\n", d1+d2-d3*2);
    }
    else {
      plus.put(IN[a] + 1, OUT2[a], b);
      minus.put(IN2[a], OUT[a], b);
    }
  }
}