#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > a;
vector<pair<int, int> > v, w;
bool f(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return 1LL * (-c.second + a.second) * (b.first - a.first) >
         1LL * (-b.second + a.second) * (c.first - a.first);
}
int main() {
  int n, m, x, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    a.insert(pair<int, int>(x, -y));
    v.push_back(pair<int, int>(x, -y));
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    v.push_back(pair<int, int>(x, -y));
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (pair<int, int> t : v) {
    while (w.size() && w.back().second > t.second) w.pop_back();
    while (w.size() > 1 && f(w[w.size() - 2], w.back(), t)) w.pop_back();
    w.push_back(t);
  }
  string ans = "Min";
  for (pair<int, int> t : w)
    if (a.count(t)) {
      ans = "Max";
      break;
    }
  puts(ans.c_str());
  return 0;
}
