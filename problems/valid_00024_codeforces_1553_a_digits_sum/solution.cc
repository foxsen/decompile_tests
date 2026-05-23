#include <bits/stdc++.h>
using namespace std;
void basics() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  if (n % 10 == 9)
    cout << (n / 10) + 1 << '\n';
  else
    cout << n / 10 << '\n';
}
int32_t main() {
  basics();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
