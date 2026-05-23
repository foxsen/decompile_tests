#include <bits/stdc++.h>
using namespace std;
const long long logN = 20;
const long long N = 405;
const long long M = 1000000007;
const long long INF = 1e12;
long long pow1(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % M;
    }
    a = (a * a) % M;
    b >>= 1;
  }
  return res % M;
}
long long adj[N][N];
long long a[N], b[N], par[N];
long long s, t;
long long n, m;
long long bfs() {
  queue<pair<long long, long long> > q;
  q.push({s, LLONG_MAX});
  fill(par, par + N, -1);
  long long vis[N];
  for (long long i = 0; i < N; i++) vis[i] = -1;
  vis[s] = 1;
  while (!q.empty()) {
    pair<long long, long long> p1 = q.front();
    long long u = p1.first;
    q.pop();
    for (long long j = 0; j <= 2 * n + 1; j++) {
      if (vis[j] == -1 && adj[u][j] > 0) {
        par[j] = u;
        vis[j] = 1;
        long long nxt = min(p1.second, adj[u][j]);
        q.push({j, nxt});
        if (j == t) return nxt;
      }
    }
  }
  return 0;
}
long long maxflow() {
  long long new_flow;
  long long mx_flow = 0;
  while (new_flow = bfs()) {
    long long vertex = t;
    while (vertex != s) {
      adj[par[vertex]][vertex] -= new_flow;
      adj[vertex][par[vertex]] += new_flow;
      vertex = par[vertex];
    }
    mx_flow += new_flow;
  }
  return mx_flow;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T = 1;
  while (T--) {
    for (long long i = 0; i < N; i++)
      for (long long j = 0; j < N; j++) {
        adj[i][j] = 0;
      }
    cin >> n >> m;
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n; i++) cin >> b[i];
    for (long long i = 1; i < n + 1; i++) {
      adj[i][n + i] = LLONG_MAX;
    }
    for (long long i = 0; i < m; i++) {
      long long u, v;
      cin >> u >> v;
      long long u2 = u + (n);
      long long v2 = v + (n);
      adj[u][v2] = LLONG_MAX;
      adj[v][u2] = LLONG_MAX;
    }
    for (long long i = 1; i <= n; i++) {
      adj[0][i] = a[i - 1];
    }
    for (long long i = n + 1; i < 2 * n + 1; i++) {
      adj[i][2 * n + 1] = b[i - n - 1];
    }
    s = 0;
    t = 2 * n + 1;
    long long flow = maxflow();
    long long source_side = 0, sink_side = 0;
    for (auto it : a) source_side += it;
    for (auto it : b) sink_side += it;
    if (source_side != flow || sink_side != flow || source_side != sink_side) {
      cout << "NO"
           << "\n";
      return 0;
    }
    cout << "YES"
         << "\n";
    long long mat[n + 1][n + 1];
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) {
        long long v2 = j + n, u = i;
        mat[u][v2 - n] = adj[v2][u];
      }
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) {
        cout << mat[i][j] << " ";
      }
      cout << "\n";
    }
  }
}
