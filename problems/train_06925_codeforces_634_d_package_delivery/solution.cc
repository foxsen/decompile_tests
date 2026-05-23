#include <bits/stdc++.h>
using namespace std;
long long x[200007];
long long p[200007];
vector<pair<long long, long long> > v;
set<pair<long long, long long> > s;
set<pair<long long, long long> >::iterator it;
int main() {
  long long d, n, lst, fst, ans = 0, temp;
  int m;
  cin >> d >> n >> m;
  for (int i = 0; i < m; ++i) cin >> x[i] >> p[i];
  for (int i = 0; i < m; ++i) v.push_back(make_pair(p[i], x[i]));
  sort(v.begin(), v.end());
  s.insert(make_pair(0, n));
  for (int i = 0; i < m; ++i) {
    it = s.upper_bound(make_pair(v[i].second, INT_MAX));
    if (it != s.end())
      lst = it->first;
    else
      lst = d;
    --it;
    fst = it->second;
    if (lst <= fst) continue;
    temp =
        min(min(n, lst - v[i].second), min(lst - fst, n - (fst - v[i].second)));
    s.insert(make_pair(v[i].second, max(v[i].second, fst) + temp));
    ans += temp * v[i].first;
  }
  long long prev = 0;
  for (it = s.begin(); it != s.end(); ++it) {
    if (it->first > prev) ans = -1;
    prev = it->second;
  }
  if (prev < d) ans = -1;
  cout << ans;
  return 0;
}
