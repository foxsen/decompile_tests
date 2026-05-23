#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
vector<ll> ans;
int s, n;
ll ten[12];
void solve(void) {
  cin >> s >> n;
  ll t = 1;
  while (t * 10 <= s) {
    t *= 10;
  }
  int count = 0;
  ans.clear();
  while (count + 1 < n) {
    if (s - t >= n - count - 1) {
      ans.push_back(t);
      s -= t;
      count++;
    } else {
      t /= 10;
    }
  }
  ans.push_back(s);
  for (auto d : ans) {
    cout << d << ' ';
  }
  cout << '\n';
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ten[0] = 1;
  for (int i = 1; i <= 10; i++) {
    ten[i] = ten[i - 1] * 10;
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
