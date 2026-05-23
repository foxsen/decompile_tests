#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, k;
  vector<long long int> v;
  cin >> n >> m >> k;
  if (k == 1) {
    for (long long int i = 1; i <= n + m; i += (n - 1)) v.push_back(i);
  } else {
    for (long long int i = 0; i < k; i++) v.push_back(1);
    for (long long int i = 2; i <= n + m; ++i) {
      if (i % n == 0)
        v.push_back(i);
      else if (i % n == 1) {
        for (long long int j = 0; j < k - 1; j++) v.push_back(i);
      }
    }
  }
  cout << v.size() << "\n";
  for (long long int i : v) cout << i << " ";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  solve();
  return 0;
}
