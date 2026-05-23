#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5, inf = 1e18 + 100;
vector<long long> g[N];
long long used[N];
void solve() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= 3 * n; ++i) g[i].clear(), used[i] = 0;
  vector<long long> seq;
  for (long long i = 1; i <= m; ++i) {
    long long u, v;
    cin >> u >> v;
    if (!used[u] && !used[v]) used[u] = 1, used[v] = 1, seq.push_back(i);
  }
  if (seq.size() >= n) {
    cout << "Matching" << '\n';
    for (long long i = 0; i < n; ++i) cout << seq[i] << ' ';
    cout << '\n';
    return;
  }
  seq.clear();
  for (long long i = 1; i <= 3 * n; ++i)
    if (!used[i]) seq.push_back(i);
  if (seq.size() >= n) {
    cout << "IndSet" << '\n';
    for (long long i = 0; i < n; ++i) cout << seq[i] << ' ';
    cout << '\n';
    return;
  }
  cout << "Impossible" << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long q;
  cin >> q;
  while (q--) solve();
  return 0;
}
