#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5, maxa = (1 << 20);
int N, a[2 * maxn];
vector<pair<int, int> > adj[maxa];
bool vis[maxn];
void dfs(int u, int p, bool ok) {
  while (adj[u].size()) {
    auto v = adj[u].back();
    adj[u].pop_back();
    if (vis[v.second / 2]) continue;
    vis[v.second / 2] = true;
    dfs(v.first, v.second, ok);
  }
  if (p != -1 && ok) {
    cout << p + 1 << ' ' << (p ^ 1) + 1 << ' ';
  }
}
bool check(int b, bool ok = false) {
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < maxa; ++i) adj[i].clear();
  int mask = (1 << b) - 1;
  for (int i = 0; i < 2 * N; ++i) {
    adj[a[i] & mask].emplace_back(a[i ^ 1] & mask, i ^ 1);
  }
  for (int i = 0; i < maxa; ++i) {
    if (adj[i].size() & 1) return false;
  }
  for (int i = 0; i < maxa; ++i) {
    if (adj[i].size()) {
      dfs(i, -1, ok);
      break;
    }
  }
  for (int i = 0; i < N; ++i)
    if (!vis[i]) return false;
  return true;
}
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i = 0; i < 2 * N; ++i) cin >> a[i];
  for (int b = 20; b >= 0; --b) {
    if (check(b)) {
      cout << b << '\n';
      check(b, 1);
      return 0;
    }
  }
}
