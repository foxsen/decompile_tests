#include <bits/stdc++.h>
using namespace std;
const int maxn(1e6 + 5);
const int mod(1e9 + 7);
inline void Inc(int &x, int y) { x = x + y >= mod ? x + y - mod : x + y; }
inline int Add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline void Dec(int &x, int y) { x = x - y < 0 ? x - y + mod : x - y; }
inline int Sub(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
int n, val[maxn], mx, cnt[maxn], val1[maxn], val2[maxn], pw[maxn];
int pw10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000};
long long ans;
int main() {
  int i, j, s, nxt;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", &val[i]), mx = max(mx, val[i]);
  for (pw[0] = i = 1; i <= n; ++i) pw[i] = Add(pw[i - 1], pw[i - 1]);
  for (i = 1; i <= n; ++i)
    Inc(val1[val[i]], val[i]), ++cnt[val[i]],
        Inc(val2[val[i]], (long long)val[i] * val[i] % mod);
  for (j = 1; j <= 6; ++j)
    for (i = mx; ~i; --i) {
      if (i / pw10[j - 1] % 10 == 9) continue;
      nxt = i + pw10[j - 1];
      Inc(val1[i], val1[nxt]), Inc(val2[i], val2[nxt]), Inc(cnt[i], cnt[nxt]);
    }
  for (i = 0; i <= mx; ++i)
    if (cnt[i]) {
      val1[i] = (long long)val1[i] * val1[i] % mod;
      Dec(val1[i], val2[i]);
      if (cnt[i] > 1)
        val1[i] = (long long)val1[i] * pw[cnt[i] - 2] % mod;
      else
        val1[i] = 0;
      val2[i] = (long long)val2[i] * pw[cnt[i] - 1] % mod;
      Inc(val1[i], val2[i]);
    }
  for (j = 1; j <= 6; ++j)
    for (i = 0; i <= mx; ++i) {
      if (i / pw10[j - 1] % 10 == 9) continue;
      nxt = i + pw10[j - 1], Dec(val1[i], val1[nxt]);
    }
  for (i = 0; i <= mx; ++i) ans ^= (long long)val1[i] * i;
  printf("%lld\n", ans);
  return 0;
}
