#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  map<double, int> m;
  for (int i = 0; i < n; i++) {
    double xi, ai;
    cin >> xi >> ai;
    m[xi - ai / 2.0]++;
    m[xi + ai / 2.0]--;
  }
  vector<pair<double, int> > v;
  int res = 2;
  for (__typeof(m.begin()) it = m.begin(); it != m.end(); ++it) {
    v.push_back(make_pair(it->first, it->second));
  }
  int ct = 0;
  for (int i = 0; i < (int)v.size() - 1; i++) {
    ct += v[i].second;
    if (!ct) {
      if (v[i + 1].first - v[i].first - 1e-10 > t)
        res += 2;
      else if (abs(v[i + 1].first - v[i].first - t) <= 1e-10)
        res += 1;
    }
  }
  cout << res << endl;
  return 0;
}
