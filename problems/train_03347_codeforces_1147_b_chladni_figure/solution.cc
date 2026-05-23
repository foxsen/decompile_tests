#include <bits/stdc++.h>
using namespace std;
int main() {
  long long(n), (m);
  scanf("%lld%lld", &(n), &(m));
  ;
  vector<pair<long long, long long>> A;
  vector<vector<long long>> dists(n + 1);
  for (long long i = 0; i < (m); i++) {
    long long(a), (b);
    scanf("%lld%lld", &(a), &(b));
    ;
    dists[a].push_back((b - a + n) % n);
    dists[b].push_back((a - b + n) % n);
  }
  vector<long long> diffs;
  for (long long i = 1; i < (n + 1); i++) {
    if (dists[i].size() == 0)
      diffs.push_back(-1);
    else {
      sort((dists[i]).begin(), (dists[i]).end());
      for (auto j : dists[i]) diffs.push_back(j);
    }
  }
  vector<long long> s = diffs;
  for (auto i : diffs) s.push_back(i);
  long long sz = (long long)s.size();
  vector<long long> z(sz);
  for (long long i = 1, l = 0, r = 0; i < sz; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < sz && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  for (long long i = 1; i < (diffs.size()); i++) {
    if (z[i] >= diffs.size()) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
