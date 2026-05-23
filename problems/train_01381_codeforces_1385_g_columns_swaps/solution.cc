#include <bits/stdc++.h>
using namespace std;
long long mo(long long a) { return a % (long long)(1e9 + 7); }
long long po(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res % p;
}
vector<vector<pair<long long, long long>>> g;
vector<long long> vis, col;
vector<vector<long long>> ty;
void dfs(long long par, long long anc = -1, long long type = -1) {
  if (anc == -1) {
    col[par] = 0;
    ty[col[par]].push_back(par);
  } else {
    if (type) {
      col[par] = !col[anc];
      ty[col[par]].push_back(par);
    } else {
      col[par] = col[anc];
      ty[col[par]].push_back(par);
    }
  }
  vis[par] = 1;
  for (pair<long long, long long> e : g[par]) {
    if (!vis[e.first]) {
      dfs(e.first, par, e.second);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<long long>> r(n, vector<long long>(2, -1)),
        c(n, vector<long long>(2, -1));
    for (long long i = 0; i < 2; i++) {
      for (long long j = 0; j < n; j++) {
        long long x;
        cin >> x;
        x--;
        if (r[x][0] == -1)
          r[x][0] = i;
        else
          r[x][1] = i;
        if (c[x][0] == -1)
          c[x][0] = j;
        else
          c[x][1] = j;
      }
    }
    long long pos = 1;
    for (long long i = 0; i < n; i++) {
      if (r[i][0] == -1 || r[i][1] == -1) pos = 0;
    }
    if (!pos) {
      cout << -1 << "\n";
      continue;
    }
    g.assign(n, {});
    vis.assign(n, 0);
    col.assign(n, -1);
    ty.assign(2, {});
    for (long long i = 0; i < n; i++) {
      if (r[i][0] == r[i][1] && c[i][0] != c[i][1]) {
        g[c[i][0]].push_back({c[i][1], 1});
        g[c[i][1]].push_back({c[i][0], 1});
      }
      if (r[i][0] != r[i][1] && c[i][0] != c[i][1]) {
        g[c[i][1]].push_back({c[i][0], 0});
        g[c[i][0]].push_back({c[i][1], 0});
      }
    }
    vector<long long> ans;
    for (long long i = 0; i < n; i++) {
      if (!vis[i]) {
        ty[0].clear();
        ty[1].clear();
        dfs(i);
        if (ty[0].size() > ty[1].size()) swap(ty[0], ty[1]);
        for (long long e : ty[0]) ans.push_back(e);
      }
    }
    cout << ans.size() << "\n";
    for (long long e : ans) cout << e + 1 << " ";
    cout << "\n";
  }
  return 0;
}
