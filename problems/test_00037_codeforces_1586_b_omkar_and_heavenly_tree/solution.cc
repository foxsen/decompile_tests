#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> leaves(n + 1, 0);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    leaves[b] = 1;
  }
  int root = -1;
  for (int i = 1; i <= n; i++) {
    if (leaves[i] == 0) {
      root = i;
      break;
    }
  }
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (i == root) {
      continue;
    } else {
      v.push_back(i);
    }
  }
  for (int i = 0; i < v.size(); i++) {
    cout << root << " " << v[i] << endl;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
