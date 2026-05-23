#include <bits/stdc++.h>
using namespace std;
map<long long int, int> primef(long long int n) {
  map<long long int, int> m;
  while (n % 2 == 0) {
    m[2] = 1;
    n /= 2;
  }
  for (long long int i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      m[i] = 1;
      n /= i;
    }
  }
  if (n > 2) m[n] = 1;
  return m;
}
void solve() {
  long long int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  map<long long int, int> m = primef(n);
  if (m.size() > 1)
    cout << 1 << endl;
  else
    cout << (*m.begin()).first << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  while (tt--) solve();
  return 0;
}
