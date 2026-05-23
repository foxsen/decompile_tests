#include <bits/stdc++.h>
using namespace std;
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
void solve() {
  long long int n, i, j;
  cin >> n;
  vector<long long int> v(n);
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if ((2 * sum) % n != 0) {
    cout << 0 << endl;
    return;
  }
  sort(v.begin(), v.end());
  long long int val = (2 * sum) / n, ans = 0;
  for (long long int i = 0; i < n; i++) {
    long long int diff = val - v[i];
    auto low = lower_bound(v.begin() + i + 1, v.end(), diff);
    auto upp = upper_bound(v.begin() + i + 1, v.end(), diff);
    ans += upp - low;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
