#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
const long long INF = (long long)1e16;
using namespace std;
void dummy_func() {}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<long long> f(m, -INF), g(m, -INF);
  for (int i = 0; i < n; ++i) {
    vector<int> s(m);
    scanf("%d", &s.front());
    for (int j = 1; j < m; ++j) {
      int t = 0;
      scanf("%d", &t);
      s[j] = s[j - 1] + t;
    }
    if (i == 0) {
      for (int j = 0; j < m; ++j) f[j] = s[j];
      continue;
    }
    g.assign(m, -INF);
    if (i & 1) {
      long long curMax = f.back();
      for (int j = m - 2; j >= 0; --j) {
        g[j] = curMax + s[j];
        curMax = max(curMax, f[j]);
      }
    } else {
      long long curMax = f.front();
      for (int j = 1; j < m; ++j) {
        g[j] = curMax + s[j];
        curMax = max(curMax, f[j]);
      }
    }
    f.swap(g);
  }
  long long ans = -INF;
  for (int i = 0; i < m; ++i) ans = max(ans, f[i]);
  cout << ans << '\n';
  return 0;
}
