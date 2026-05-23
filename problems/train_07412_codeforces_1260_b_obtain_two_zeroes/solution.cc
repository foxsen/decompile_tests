#include <bits/stdc++.h>
using namespace std;
long long int poww(long long int x, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n % 2) res *= x;
    n = n >> 1;
    x *= x;
  }
  return res;
}
void solve() {
  long long int a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  if ((a + b) % 3 == 0 and 2 * a >= b)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
