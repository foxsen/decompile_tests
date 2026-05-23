#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const double Pi = acos(-1.0);
const double E = exp(1.0);
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
template <typename T>
inline T _gcd(T a, T b) {
  return (b == 0) ? a : _gcd(b, a % b);
}
template <typename T>
inline T _lcm(T a, T b) {
  return a / _gcd(a, b) * b;
}
long long int qmod(long long int a, long long int b, long long int c) {
  long long int ret = 1ll;
  while (b) {
    if (b & 1) ret = ret * a % c;
    b >>= 1, a = a * a % c;
  }
  return ret;
}
int trie[N * 40][3], sum[N * 40], val[N * 40], to[N * 40], cnt, weishu = 30 - 1;
long long int ans, tot, ta, tt;
inline void insert(int x) {
  int now = 0;
  for (int i = weishu, bt; i >= 0; i--) {
    bt = 1 - (0 == (x & (1 << i)));
    if (!trie[now][bt]) trie[now][bt] = ++cnt;
    now = trie[now][bt];
    sum[now]++;
  }
  val[now] = x;
}
inline int query(int x, int pre) {
  int now = 0;
  for (int i = weishu, bt; i >= 0; i--) {
    bt = 1 - (0 == (x & (1 << i)));
    if (!trie[now][bt]) bt = 1 - bt;
    if (now == pre) bt = 1 - bt;
    now = trie[now][bt];
  }
  return now;
}
void dfs2(int x, int &pre) {
  if (trie[x][0]) dfs2(trie[x][0], pre);
  if (trie[x][1]) dfs2(trie[x][1], pre);
  if (!trie[x][0] && !trie[x][1]) {
    int now = query(val[x], pre);
    if (ta == (val[now] ^ val[x])) {
      tt = (tt + 1ll * sum[now] * sum[x] % MOD) % MOD;
    }
    if (ta > (val[now] ^ val[x])) {
      ta = (val[now] ^ val[x]);
      tt = (1ll * sum[now] * sum[x]) % MOD;
    }
  }
}
void dfs(int x) {
  if (trie[x][0]) dfs(trie[x][0]);
  if (trie[x][1]) dfs(trie[x][1]);
  if (trie[x][0] && trie[x][1]) {
    ta = (~(1 << 31)), tt = 0;
    if (to[trie[x][1]] < to[trie[x][0]])
      dfs2(trie[x][1], x);
    else
      dfs2(trie[x][0], x);
    ans += ta;
    tot = tot * tt % MOD;
  } else if (!trie[x][0] && !trie[x][1] && sum[x] > 1)
    tot = tot * qmod(1ll * sum[x], 1ll * sum[x] - 2, 1ll * MOD) % MOD;
}
int dfs1(int x) {
  if (!trie[x][0] && !trie[x][1]) return to[x] = 1;
  if (trie[x][0]) to[x] += dfs1(trie[x][0]);
  if (trie[x][1]) to[x] += dfs1(trie[x][1]);
  return to[x];
}
int main() {
  int n;
  scanf("%d", &n);
  cnt = 0;
  ans = 0ll, tot = 1ll;
  for (int i = 1, x; i <= n; i++) {
    x = read();
    insert(x);
  }
  dfs1(0);
  dfs(0);
  printf("%lld\n", ans);
  return 0;
}
