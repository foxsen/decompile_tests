#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
void solve() {
  long long int n, q, x, y, z, w, mini, maxi = INT_MAX, prev;
  cin >> q >> x;
  unordered_map<long long int, int> m1, m2;
  y = 0;
  while (q--) {
    cin >> n;
    n %= x;
    m1[x * m2[n] + n]++;
    m2[n]++;
    while (m1[y]) y++;
    cout << y << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
