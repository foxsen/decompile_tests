#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<int> p(n + 1);
  vector<pair<int, int>> fruit(n + 1);
  vector<map<int, long long>> S(n + 1);
  for (int i = 2; i <= n; ++i) scanf("%d", &p[i]);
  for (int i = 0; i < m; ++i) {
    int v, d, w;
    scanf("%d%d%d", &v, &d, &w);
    fruit[v] = {d, w};
  }
  for (int i = n; i >= 2; --i) {
    int d, w;
    tie(d, w) = fruit[i];
    if (d) {
      long long amt = w;
      while (amt) {
        auto nit = S[i].upper_bound(d);
        if (nit == S[i].end()) break;
        assert(nit->first > d);
        if (nit->second <= amt) {
          amt -= nit->second;
          S[i].erase(nit);
        } else {
          nit->second -= amt;
          amt = 0;
        }
      }
      auto nit = S[i].upper_bound(d);
      if (nit != S[i].begin() && prev(nit)->first == d) {
        prev(nit)->second += w;
      } else {
        S[i][d] = w;
      }
    }
    if (S[p[i]].size() < S[i].size()) swap(S[p[i]], S[i]);
    for (auto& x : S[i]) {
      S[p[i]][x.first] += x.second;
    }
  }
  long long ans = 0;
  for (auto& x : S[1]) {
    ans += x.second;
  }
  printf("%lld\n", ans);
}
