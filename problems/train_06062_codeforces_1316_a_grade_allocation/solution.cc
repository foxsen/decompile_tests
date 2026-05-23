#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, x, s = 0;
    cin >> n >> m;
    cin >> a;
    for (int i = 1; i < n; i++) {
      cin >> x;
      s += x;
    }
    a = min(m, a + s);
    cout << a << '\n';
  }
}
