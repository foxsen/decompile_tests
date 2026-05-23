#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<long long> v;
bool eval(long long targ) {
  long long total_cost = 0;
  for (int i = n / 2; i < n; i++) {
    total_cost += max(0ll, targ - v[i]);
  }
  return total_cost <= k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  v.assign(n, 0);
  for (auto &x : v) cin >> x;
  sort((v).begin(), (v).end());
  long long median = v[v.size() / 2];
  long long lo = median;
  long long hi = median + k + 5;
  long long ans = lo;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    if (eval(mid)) {
      ans = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  cout << ans << '\n';
  return 0;
}
