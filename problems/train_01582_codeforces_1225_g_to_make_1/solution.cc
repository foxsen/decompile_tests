#include <bits/stdc++.h>
using namespace std;
const int N = 20, K = (1 << 16) + 5, M = 2005, mod = 998244353;
int k, sum, a[N], b[N];
bitset<M> f[K];
inline void dfs(register int s, register int now) {
  if (!s) return;
  register int i;
  for (; now * k <= sum && f[s][now * k]; now *= k)
    for (i = s; i; i ^= i & -i) ++b[__builtin_ctz(i & -i)];
  for (i = s; i; i ^= i & -i)
    if (now >= a[__builtin_ctz(i & -i)] &&
        f[s ^ i & -i][now - a[__builtin_ctz(i & -i)]]) {
      dfs(s ^ i & -i, now - a[__builtin_ctz(i & -i)]);
      return;
    }
}
priority_queue<pair<int, int> > q;
int main() {
  register int n, i, s, t;
  scanf("%d%d", &n, &k);
  for (i = 0; i ^ n; ++i) scanf("%d", &a[i]), sum += a[i];
  t = (1 << n) - 1;
  f[0][0] = 1;
  for (s = 1; s <= t; ++s) {
    for (i = s; i; i ^= i & -i)
      f[s] |= f[s ^ i & -i] << a[__builtin_ctz(i & -i)];
    for (i = sum / k; i >= 1; --i)
      if (f[s][i * k]) f[s][i] = 1;
  }
  if (!f[t][1])
    puts("NO");
  else {
    puts("YES");
    dfs(t, 1);
    register pair<int, int> x1, x2;
    for (i = 0; i ^ n; ++i) q.push(make_pair(b[i], a[i]));
    while (q.size() > 1) {
      x1 = q.top();
      q.pop();
      x2 = q.top();
      q.pop();
      printf("%d %d\n", x1.second, x2.second);
      x1.second += x2.second;
      while (x1.second % k == 0) x1.second /= k, --x1.first;
      q.push(x1);
    }
  }
  return 0;
}
