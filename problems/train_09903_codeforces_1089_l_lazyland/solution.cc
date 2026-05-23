#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k, ans = 0, i;
  cin >> n >> k;
  vector<int> a(n), b(n), d(k + 1), e;
  vector<pair<int, int>> c(n);
  for (auto &it : a) cin >> it;
  ;
  for (auto &it : b) cin >> it;
  ;
  for (i = 0; i < n; ++i) {
    c[i] = {b[i], a[i]};
  }
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  for (i = 0; i < n; ++i) {
    if (d[c[i].second]) {
      e.push_back(c[i].first);
    } else {
      --k;
      d[c[i].second] = 1;
    }
  }
  sort(e.begin(), e.end());
  for (i = 0; i < k; ++i) {
    ans += e[i] * 1ll;
  }
  cout << ans;
  return 0;
}
