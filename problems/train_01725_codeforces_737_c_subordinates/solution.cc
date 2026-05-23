#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, second, ans = 0, k = 1, i, a;
  cin >> n >> second;
  map<long long, long long> mp;
  for (i = 1; i <= n; i++) {
    cin >> a;
    if (i == second && a)
      ans++;
    else
      mp[a]++;
  }
  for (i = 1; i < n; i++) {
    if (k >= n) break;
    if (mp[i] == 0)
      k++, ans++;
    else
      k += mp[i];
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  solve();
  return 0;
}
