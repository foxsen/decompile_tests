#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> a;
vector<vector<long long> > d;
bool ok(long long k) {
  long long sum = accumulate(a.begin(), a.end(), 0ll);
  if (k >= 2 * sum) return true;
  if (k < sum) return false;
  long long num = 2 * sum - k;
  vector<long long> z(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < d[i].size(); ++j) {
      int s = d[i][j];
      if (s <= k && s > z[i]) z[i] = s;
    }
  }
  vector<pair<int, int> > v;
  for (int i = 0; i < n; ++i) {
    if (z[i] == 0) continue;
    v.push_back(make_pair(z[i], i));
  }
  sort(v.begin(), v.end());
  long long cur = 0;
  for (int i = 0; i < v.size(); ++i) {
    long long day = v[i].first;
    long long iii = v[i].second;
    long long add = min(a[iii], day - cur);
    cur += add;
  }
  return (cur >= num);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  d.resize(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --y;
    d[y].push_back(x);
  }
  long long l = 0;
  long long r = 400005;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    (ok(mid) ? r : l) = mid;
  }
  cout << r;
  return 0;
}
