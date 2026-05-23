#include <bits/stdc++.h>
using namespace std;
map<long long, pair<long long, long long> > mp;
pair<long long, long long> dfs(long long x) {
  if (x == 0) return make_pair(0, 0);
  if (mp.count(x)) return mp[x];
  long long t = pow(x + 0.5, 1.0 / 3);
  pair<long long, long long> res = dfs(t * t * t - 1);
  pair<long long, long long> tmp = dfs(x - t * t * t);
  res = max(res, make_pair(tmp.first + 1, tmp.second + t * t * t));
  mp[x] = res;
  return res;
}
int main() {
  long long m;
  scanf("%lld", &m);
  pair<long long, long long> ans = dfs(m);
  printf("%lld %lld\n", ans.first, ans.second);
  return 0;
}
