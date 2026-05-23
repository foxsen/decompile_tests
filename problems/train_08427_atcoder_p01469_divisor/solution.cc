#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define MAX_N 300
class Dinic {
public:
  struct Edge { int to, cap, rev; };
  vector<Edge> G[MAX_N];
  int level[MAX_N], iter[MAX_N];

  void add_edge(int from, int to, int cap) {
    G[from].pb((Edge) { to, cap, (int)G[to].size() });
    G[to].pb((Edge) { from, 0, (int)G[from].size() - 1 });
  }

  void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int x = q.front(); q.pop();
      for (int i=0; i<G[x].size(); i++) {
        Edge &e = G[x][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[x] + 1;
          q.push(e.to);
        }
      }
    }
  }

  int dfs(int x, int t, int f) {
    if (x == t) return f;
    for (int &i=iter[x]; i<G[x].size(); i++) {
      Edge &e = G[x][i];
      if (e.cap > 0 && level[x] < level[e.to]) {
        int d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  int max_flow(int s, int t) {
    int flow = 0;
    while (true) {
      bfs(s);
      if (level[t] < 0) return flow;
      memset(iter, 0, sizeof(iter));
      int f;
      while (true) {
        f = dfs(s, t, INF);
        if (f <= 0) break;
        flow += f;
        if (flow >= INF) return INF;
      }
    }
  }
};

int N;
bool G[100][100];
int A[100];
bool dead[100], dead2[100];

int solve(int fix) {
  rep(i, N) dead2[i] = dead[i];
  if (fix != -1) rep(i, N) if (G[fix][i] || G[i][fix]) dead2[i] = true;
  int v = 0;
  Dinic dinic;
  int s = N+N, t = N+N+1;
  rep(i, N) {
    if (dead2[i]) continue;
    v++;
    rep(j, N) {
      if (!dead2[j] && i != j && G[i][j]) dinic.add_edge(i, j+N, 1);
    }
    dinic.add_edge(s, i, 1);
    dinic.add_edge(i+N, t, 1);
  }
  return v - dinic.max_flow(s, t);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  rep(i, N) cin >> A[i];
  rep(i, N) rep(j, N) G[i][j] = A[j] % A[i] == 0;
  int m = solve(-1);
  vector<int> ans;
  rep(i, N) {
    if (!dead[i] && ans.size() + 1 + solve(i) == m) {
      ans.pb(i);
      rep(j, N) if (G[i][j] || G[j][i]) dead[j] = true;
    }
  }
  assert(m == ans.size());
  rep(i, m) cout << ans[i]+1 << (i+1==m?"\n":" ");
  return 0;
}