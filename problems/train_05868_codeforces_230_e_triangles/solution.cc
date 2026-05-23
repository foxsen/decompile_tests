#include <bits/stdc++.h>
using namespace std;
long long deg[1000011];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long ans = n * (n - 1) * (n - 2) / 6;
  for (long long i = 0; i < n; i++) deg[i]++;
  while (m--) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    ans -= n - deg[u] - deg[v];
    deg[u]++;
    deg[v]++;
  }
  cout << ans << endl;
  return 0;
}
