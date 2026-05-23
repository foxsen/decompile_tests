#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)7 + (int)1e9;
const int N = 1000005;
const double PI = 4 * atan(1);
const double eps = 1e-10;
const long long oo = 1e10;
const int K = 26;
int n, k;
int p[N];
int q[N];
int ans[N];
vector<long long> adj[N];
vector<long long> adjt[N];
bool vis[N];
vector<long long> v;
vector<long long> order;
void dfs(int src) {
  if (vis[src]) return;
  vis[src] = 1;
  for (auto t : adj[src]) {
    if (vis[t]) continue;
    dfs(t);
  }
  order.push_back(src);
}
void label(int src) {
  if (vis[src]) return;
  v.push_back(src);
  vis[src] = 1;
  for (auto t : adjt[src]) {
    if (vis[t]) continue;
    label(t);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    if (i > 0) {
      adj[p[i - 1]].push_back(p[i]);
      adjt[p[i]].push_back(p[i - 1]);
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> q[i];
    q[i]--;
    if (i > 0) {
      adj[q[i - 1]].push_back(q[i]);
      adjt[q[i]].push_back(q[i - 1]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  memset(vis, 0, sizeof(vis));
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int node = order[n - 1 - i];
    if (vis[node]) continue;
    v.clear();
    label(node);
    for (auto t : v) {
      ans[t] = (cur < 25 ? cur : 25);
    }
    cur++;
  }
  if (cur < k) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << char(ans[i] + 'a');
  }
  return 0;
}
