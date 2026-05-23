#include <bits/stdc++.h>
using namespace std;
const long long N = 100005, Mod = 1000000007;
long long Mxdp, n, dp[N];
map<long long, bool> tagged;
map<long long, long long> col;
char buf[15];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct Node {
  long long s[7];
  inline Node() { memset(s, 0, sizeof(s)); }
};
inline Node dfs(long long x, long long dep) {
  Node now;
  long long c = 0;
  if (col.find(x) != col.end()) c = col[x];
  if (dep == 0) {
    if (c == 0)
      for (long long i = 1; i <= 6; ++i) now.s[i] = 1;
    else
      now.s[c] = 1;
    return now;
  }
  if (!tagged[x]) {
    for (long long i = 1; i <= 6; ++i) now.s[i] = dp[dep];
    return now;
  }
  Node l = dfs(x << 1, dep - 1), r = dfs(x << 1 | 1, dep - 1);
  if (c == 0) {
    for (long long i = 1; i <= 6; ++i)
      for (long long c1 = 1; c1 <= 6; ++c1)
        if ((i + c1 != 7) && (i != c1))
          for (long long c2 = 1; c2 <= 6; ++c2)
            if ((i + c2 != 7) && (i != c2))
              (now.s[i] += l.s[c1] * r.s[c2] % Mod) %= Mod;
  } else {
    for (long long c1 = 1; c1 <= 6; ++c1)
      if (c + c1 != 7 && c != c1)
        for (long long c2 = 1; c2 <= 6; ++c2)
          if (c + c2 != 7 && c != c2)
            (now.s[c] = now.s[c] + l.s[c1] * r.s[c2] % Mod) %= Mod;
  }
  return now;
}
inline long long sqr(long long x) { return 1ll * x * x % Mod; }
inline void Prepare() {
  dp[0] = 1;
  for (long long i = 0; i < Mxdp - 1; ++i) dp[i + 1] = 16 * sqr(dp[i]) % Mod;
  for (long long i = 0; i < Mxdp; ++i) cerr << dp[i] << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> Mxdp;
  Prepare();
  cin >> n;
  assert(true);
  for (long long i = 0; i < Mxdp; ++i) cerr << dp[i] << endl;
  for (long long i = 1; i <= n; ++i) {
    long long x;
    cin >> x >> buf + 1;
    assert(true);
    if (buf[1] == 'y') col[x] = 1;
    if (buf[1] == 'g') col[x] = 2;
    if (buf[1] == 'r') col[x] = 3;
    if (buf[1] == 'o') col[x] = 4;
    if (buf[1] == 'b') col[x] = 5;
    if (buf[1] == 'w') col[x] = 6;
    cerr << buf[1] << endl;
    while (x) {
      tagged[x] = true;
      x >>= 1;
    }
  }
  assert(true);
  Node ans = dfs(1, Mxdp - 1);
  for (long long i = 0; i < Mxdp; ++i) cerr << dp[i] << endl;
  long long res = 0;
  assert(true);
  for (long long i = 1; i <= 6; ++i) res = (res + ans.s[i]) % Mod;
  for (long long i = 0; i < Mxdp; ++i) cerr << dp[i] << endl;
  assert(true);
  printf("%lld\n", res);
  return 0;
}
