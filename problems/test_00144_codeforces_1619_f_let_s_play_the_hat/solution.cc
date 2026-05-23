#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int p = 1, q, n_big = n % m, n_small = m - n_big, n_member = n / m;
  while (k--) {
    for (int i = 0; i < n_big; i++) {
      cout << n_member + 1 << ' ';
      for (int j = 0; j < n_member + 1; j++) {
        cout << p << ' ';
        p = p == n ? 1 : p + 1;
      }
      cout << '\n';
    }
    q = p;
    for (int i = 0; i < n_small; i++) {
      cout << n_member << ' ';
      for (int j = 0; j < n_member; j++) {
        cout << q << ' ';
        q = q == n ? 1 : q + 1;
      }
      cout << '\n';
    }
  }
  cout << '\n';
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
