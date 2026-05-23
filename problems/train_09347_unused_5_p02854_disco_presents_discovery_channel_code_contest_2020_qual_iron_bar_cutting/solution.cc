#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> acc = {0};
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    acc.push_back(acc.back()+a);
  }
  ll ans = acc.back();
  for (ll a : acc)
    ans = min(ans, abs(acc.back()-a*2));
  cout << ans << endl;
}
