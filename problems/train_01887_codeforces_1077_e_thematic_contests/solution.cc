#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a;
  map<long long, long long> m;
  scanf("%lld", &n);
  for (long long i = 0; i < n; ++i) {
    scanf("%lld", &a);
    ++m[a];
  }
  vector<long long> v;
  for (auto e : m) {
    v.push_back(e.second);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long long ans = v[0], tmp, now = v[0], kal = 2;
  for (long long i = 1; i < v.size(); ++i) {
    now >>= 1;
    now = min(now, v[i]);
    if (!now) break;
    kal <<= 1;
    tmp = now * (kal - 1);
    ans = max(ans, tmp);
  }
  printf("%lld\n", ans);
  return 0;
}
