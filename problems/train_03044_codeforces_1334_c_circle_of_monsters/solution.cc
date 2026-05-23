#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<long long, long long> > a;
    for (int i = 0; i < n; i += 1) {
      long long x, y;
      cin >> x >> y;
      a.push_back({x, y});
    }
    long long cum = 0, mini = LLONG_MAX;
    for (int i = 1; i < n; i++) {
      if (a[i].first > a[i - 1].second) {
        cum += a[i].first - a[i - 1].second;
        a[i].first = a[i - 1].second;
      }
      mini = min(mini, a[i].first);
    }
    if (a[n - 1].second < a[0].first) {
      cum += a[0].first - a[n - 1].second;
      a[0].first = a[n - 1].second;
    }
    mini = min(mini, a[0].first);
    long long ans = cum + mini;
    cout << ans << "\n";
  }
  return 0;
}
