#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    ll c, sum;
    cin >> c >> sum;
    ll x = sum / c;
    ll big = sum - c * x;
    ll small = c - big;
    ll ans = small * x * x + big * (x + 1) * (x + 1);
    cout << ans << '\n';
  }
  return 0;
}
