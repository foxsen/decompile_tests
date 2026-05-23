#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
int t, n, a[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (a[n] == 0) {
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << n + 1 << '\n';
    return;
  }
  int x = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0 && a[i + 1] == 1) x = i;
  }
  if (x == -1)
    cout << -1 << '\n';
  else {
    for (int i = 1; i <= x; i++) cout << i << ' ';
    cout << n + 1 << ' ';
    x++;
    for (int i = x; i <= n; i++) cout << i << ' ';
    cout << '\n';
  }
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
