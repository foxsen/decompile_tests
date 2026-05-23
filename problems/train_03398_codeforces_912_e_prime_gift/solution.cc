#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0;
  register char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x;
}
const int N = 63;
int n, cnt;
long long a[N], c[N], k, l, r;
vector<long long> s[2];
void dfs(int i, int x, long long now) {
  s[i].push_back(now);
  for (register int j = x; j <= cnt; ++j)
    if (1e18 / c[j] >= now) dfs(i, j, now * c[j]);
}
long long solve(long long x) {
  int j = 0;
  long long tot = 0;
  for (register int i = s[0].size() - 1; i >= 0; --i) {
    while (j < s[1].size() && s[1][j] <= x / s[0][i]) ++j;
    tot += j;
  }
  return tot;
}
int main() {
  n = read();
  for (register int i = 1; i <= n; ++i) a[i] = read();
  sort(a + 1, a + n + 1);
  scanf("%lld", &k);
  cnt = 0;
  for (register int i = 1; i <= n; ++i)
    if (i & 1) c[++cnt] = a[i];
  dfs(0, 1, 1);
  cnt = 0;
  for (register int i = 1; i <= n; ++i)
    if (!(i & 1)) c[++cnt] = a[i];
  dfs(1, 1, 1);
  sort(s[0].begin(), s[0].end());
  sort(s[1].begin(), s[1].end());
  l = 1, r = 1e18;
  while (l + 1 < r) {
    long long mid = (l + r) >> 1;
    if (solve(mid) >= k)
      r = mid;
    else
      l = mid + 1;
  }
  if (solve(l) >= k)
    printf("%lld\n", l);
  else
    printf("%lld\n", r);
  return 0;
}
