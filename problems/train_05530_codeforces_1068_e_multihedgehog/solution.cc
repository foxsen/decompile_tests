#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e9;
const long long int INFF = 1e18;
const long long int M = 1e9 + 7;
long long int n, k;
vector<long long int> adj[100005];
long long int par[100005];
long long int dep[100005];
long long int mx = 0, mxNode = 0;
bool valid = 1;
void dfs(long long int u, long long int parent, long long int depth) {
  dep[u] = depth;
  if (mx < depth) {
    mx = depth;
    mxNode = u;
  }
  par[u] = parent;
  for (auto v : adj[u]) {
    if (v != parent) {
      dfs(v, u, depth + 1);
    }
  }
}
void dfs2(long long int u, long long int parent, long long int depth) {
  dep[u] = depth;
  par[u] = parent;
  long long int children = 0;
  for (auto v : adj[u]) {
    if (v != parent) {
      children++;
      dfs2(v, u, depth + 1);
    }
  }
  if (children == 0 && depth != k) {
    valid = 0;
  }
  if (children == 1 || children == 2) {
    valid = 0;
  }
}
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    long long int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0, 0);
  mx = 0;
  dfs(mxNode, 0, 0);
  long long int dia = mx;
  if (dia % 2 || dia != 2 * k) {
    cout << "No";
    return;
  }
  long long int cnt = dia / 2;
  long long int x = mxNode;
  while (cnt) {
    x = par[x];
    cnt--;
  }
  long long int center = x;
  dfs2(center, 0, 0);
  if (!valid) {
    cout << "No";
    return;
  }
  cout << "Yes";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  int tt = t;
  while (t--) {
    solve();
  }
  return 0;
}
