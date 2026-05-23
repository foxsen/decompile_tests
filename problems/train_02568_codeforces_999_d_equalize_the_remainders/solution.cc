#include <bits/stdc++.h>
using namespace std;
int a[200005];
vector<int> r[200005];
int main() {
  int n, m;
  cin >> n >> m;
  int k = n / m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    r[a[i] % m].push_back(i);
  }
  vector<pair<int, int>> ad;
  long long ans = 0;
  for (int i = 0; i < 2 * m; i++) {
    int cur = i % m;
    while (r[cur].size() > k) {
      int t = r[cur].back();
      r[cur].pop_back();
      ad.push_back({t, i});
    }
    while (r[cur].size() < k && !ad.empty()) {
      int t = ad.back().first;
      int add = ad.back().second;
      ad.pop_back();
      r[cur].push_back(t);
      a[t] += i - add;
      ans += i - add;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
