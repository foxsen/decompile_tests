#include <bits/stdc++.h>
using namespace std;
void file() {
  freopen("std.in", "r", stdin);
  freopen("wa.out", "w", stdout);
}
const long long N = 1e6 + 10, M = 2e6 + 10, inf = 1e9;
inline long long read() {
  bool sym = 0;
  long long res = 0;
  char ch = getchar();
  while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
  return sym ? -res : res;
}
long long n, m, t[N], h[N], s[N], cnt[N], top;
signed main() {
  n = read();
  long long mx = 0, pos;
  for (long long i = 1; i <= n; i++) {
    t[i] = read();
    if (t[i] > mx) {
      pos = i;
      mx = t[i];
    }
  }
  long long p = 0, ans = n - 1;
  for (long long i = pos + 1; i <= n; i++) h[++p] = t[i];
  for (long long i = 1; i < pos; i++) h[++p] = t[i];
  top = 0;
  for (long long i = 1; i <= p; i++) {
    while (s[top] < h[i] && top) ans += cnt[top--];
    if (s[top] != h[i]) s[++top] = h[i], cnt[top] = 0;
    ans += cnt[top]++;
  }
  while (top >= 2) ans += cnt[top--];
  cout << ans;
  return 0;
}
