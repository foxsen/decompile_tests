#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n;
int a[N];
int p[N];
vector<pair<int, int>> ans;
void slv(int m) {
  int c = -1;
  for (int i = 0; i < m; i++) {
    if (c != -1) {
      ans.emplace_back(p[i], p[c]);
      swap(p[i], p[c]);
    }
    if (p[i] == m - 1) c = i;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  iota(p, p + n, 0);
  sort(p, p + n,
       [&](int i, int j) { return a[i] == a[j] ? i < j : a[i] < a[j]; });
  for (int i = n; i > 0; i--) slv(i);
  cout << ans.size() << "\n";
  for (auto [f, s] : ans) cout << f + 1 << " " << s + 1 << "\n";
}
