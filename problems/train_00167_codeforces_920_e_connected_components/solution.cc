#include <bits/stdc++.h>
using namespace std;
long long n, m, u, v, cnt;
set<long long> adj[300005], rem;
set<long long>::iterator it;
vector<long long> ans;
void dfs(long long node) {
  rem.erase(node);
  cnt++;
  for (it = rem.begin(); it != rem.end();) {
    if (adj[node].count(*it)) {
      it++;
      continue;
    }
    long long tmp = *it;
    dfs(tmp);
    it = rem.lower_bound(tmp);
  }
  adj[node].clear();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for (long long i = 1; i <= n; i++) rem.insert(i);
  for (long long i = 1; i <= n; i++) {
    if (rem.count(i)) {
      cnt = 0;
      dfs(i);
      ans.push_back(cnt);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto x : ans) cout << x << " ";
  cout << endl;
  return 0;
}
