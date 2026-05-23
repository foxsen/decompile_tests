#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 3;
set<pair<int, int> > s;
int ans[maxn];
int main() {
  long long sum = 0;
  int n, k, a;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a);
    s.insert(make_pair(a, i));
    if (i >= k + 1) {
      auto t = s.end();
      --t;
      ans[t->second] = i;
      sum = sum + 1LL * (i - t->second) * t->first;
      s.erase(t);
    }
  }
  for (int i = 1; i <= k; ++i) {
    auto t = s.end();
    --t;
    ans[t->second] = n + i;
    sum = sum + 1LL * (i + n - t->second) * t->first;
    s.erase(t);
  }
  printf("%lld\n", sum);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
