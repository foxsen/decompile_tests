#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int INF = 1e9;
int n, m;
int solve() {
  cin >> n >> m;
  for (int i = 1;; i++) {
    if (i & 1) {
      if (n < i) return cout << "Vladik" << endl, 0;
      n -= i;
    } else {
      if (m < i) return cout << "Valera" << endl, 0;
      m -= i;
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
