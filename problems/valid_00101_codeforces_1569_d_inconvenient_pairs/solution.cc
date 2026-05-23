#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
const int N = 3e5 + 5;
const int M = 20 * N;
void Evlos() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(n), y(m);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> y[i];
  }
  long long ans = 0;
  vector<vector<int>> a(m + 5), b(n + 5);
  for (int i = 0; i < k; i++) {
    int p, q;
    cin >> p >> q;
    int it = lower_bound(x.begin(), x.end(), p) - x.begin();
    int jt = lower_bound(y.begin(), y.end(), q) - y.begin();
    if (x[it] == p && y[jt] == q) continue;
    if (x[it] == p) {
      a[jt].push_back(it);
    } else {
      b[it].push_back(jt);
    }
  }
  for (int i = 0; i < n; i++) {
    sort(b[i].begin(), b[i].end());
    for (int j = 0; j < b[i].size();) {
      int l = j;
      while (l < b[i].size() && b[i][l] == b[i][j]) l++;
      ans += 1LL * (l - j) * (b[i].size() - l);
      j = l;
    }
  }
  for (int i = 0; i < m; i++) {
    sort(a[i].begin(), a[i].end());
    for (int j = 0; j < a[i].size();) {
      int l = j;
      while (l < a[i].size() && a[i][l] == a[i][j]) l++;
      ans += 1LL * (l - j) * (a[i].size() - l);
      j = l;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) Evlos();
  return 0;
}
