#include <bits/stdc++.h>
#pragma GCC optimize("O2")
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
using namespace std;
const int maxn = 1000 * 100 + 5;
const long long inf = 9223372036854775807;
const long long mod = 1e9 + 7;
void Main() {
  int n, k;
  cin >> n >> k;
  set<int> adj[n + 1];
  vector<int> b[n + 1];
  set<pair<int, int> > s;
  int f[n + 1], d[n + 1];
  memset(f, 0, sizeof f);
  memset(d, 0, sizeof d);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
    d[u]++;
    d[v]++;
  }
  if (k == 1) {
    cout << n - 1 << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (d[i] == 1) {
      f[*adj[i].begin()]++;
      b[*adj[i].begin()].push_back(i);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    s.insert({-1 * f[i], i});
  }
  while (s.size()) {
    if ((s.begin()->first) * -1 < k) break;
    ans++;
    int v = s.begin()->second;
    s.erase(*s.begin());
    int x = k;
    while (x--) {
      int l = b[v][b[v].size() - 1];
      b[v].pop_back();
      s.erase({f[l], l});
      d[v]--;
      f[v]--;
      adj[v].erase(l);
    }
    s.insert({-1 * f[v], v});
    if (d[v] == 1) {
      int u = *adj[v].begin();
      b[u].push_back(v);
      s.erase({-1 * f[u], u});
      f[u]++;
      s.insert({-1 * f[u], u});
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    Main();
  }
}
