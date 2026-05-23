#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
pair<long long, long long> p[MAXN];
int n, res = 0;
bool cw(pair<long long, long long> a, pair<long long, long long> b,
        pair<long long, long long> c) {
  return (b.first - a.first) * (c.second - b.second) -
             (c.first - b.first) * (b.second - a.second) <
         0;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i].first >> p[i].second;
    p[i].second -= p[i].first * p[i].first;
  }
  sort(p + 1, p + 1 + n);
  vector<pair<long long, long long> > hull;
  hull.push_back(p[1]);
  for (int i = 2; i <= n; ++i)
    if (cw(p[1], p[i], p[n]) || i == n) {
      while ((int)hull.size() > 1 &&
             !cw(hull[(int)hull.size() - 2], hull.back(), p[i]))
        hull.pop_back();
      hull.push_back(p[i]);
    }
  for (int i = 1; i < (int)hull.size(); ++i)
    if (hull[i].first != hull[i - 1].first) ++res;
  cout << res;
  return 0;
}
