#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, x;
    cin >> n >> x;
    ll ar[n];
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
    }
    sort(ar, ar + n);
    ll ans = 0;
    ll num = 0;
    for (int i = n - 1; i >= 0; i--) {
      ++num;
      ll ff = num * ar[i];
      if (ff >= x) {
        ++ans;
        num = 0;
        continue;
      }
    }
    cout << ans << "\n";
  }
}
