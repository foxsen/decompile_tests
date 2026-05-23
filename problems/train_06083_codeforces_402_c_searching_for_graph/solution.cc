#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2 * 1e5 + 10;
ll res;
ll a[N];
void solve() {
  ll n, p, ct = 0, tt;
  cin >> n >> p;
  tt = 2 * n + p;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      cout << i << " " << j << "\n";
      ++ct;
      if (ct == tt) return;
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
