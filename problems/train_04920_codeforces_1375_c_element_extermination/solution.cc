#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int INF = (int)1e18;
void fileio() {}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  if (v[0] < v[n - 1])
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  fileio;
  int t;
  cin >> t;
  while (t--) solve();
}
