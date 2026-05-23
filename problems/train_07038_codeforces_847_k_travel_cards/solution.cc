#include <bits/stdc++.h>
using namespace std;
map<string, int> id;
inline int getID(string s) {
  if (id.find(s) == id.end()) {
    int sz = id.size();
    id[s] = sz;
  }
  return id[s];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b, k, f;
  cin >> n >> a >> b >> k >> f;
  map<pair<int, int>, int> rcost;
  int last = -1, sum = 0;
  for (int i = 0; i < n; ++i) {
    string u, v;
    cin >> u >> v;
    int su = getID(u);
    int sv = getID(v);
    if (last == su) {
      rcost[pair<int, int>(min(su, sv), max(su, sv))] += b;
      sum += b;
    } else {
      rcost[pair<int, int>(min(su, sv), max(su, sv))] += a;
      sum += a;
    }
    last = sv;
  }
  vector<int> diff;
  for (auto it = rcost.begin(); it != rcost.end(); it++) {
    int cost = it->second;
    if (cost > f) {
      diff.push_back(cost - f);
    }
  }
  sort(diff.rbegin(), diff.rend());
  for (int i = 0; i < min((int)diff.size(), k); ++i) {
    sum -= diff[i];
  }
  cout << sum;
  return 0;
}
