#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <typename T = int>
inline T nxt() {
  char c = nc();
  T x = 0;
  int f = 1;
  for (; c > '9' || c < '0'; c = nc())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
  x *= f;
  return x;
}
const int maxn = 200123;
long long a[maxn];
unordered_map<long long, long long> cnt;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  long long n = nxt(), k = nxt();
  long long m = 1 << k;
  m--;
  a[0] = 0, cnt[0] = 1;
  for (int i = 1; i < (n + 1); ++i) {
    long long x = nxt();
    a[i] = a[i - 1] ^ x;
  }
  for (int i = 1; i < (n + 1); ++i) {
    long long v = min(a[i], a[i] ^ m);
    cnt[v]++;
  }
  long long ans = n * 1ll * (n - 1) / 2;
  ans += n;
  for (auto& q : cnt) {
    long long w = q.second;
    long long v = w / 2;
    w -= v;
    ans -= v * (v - 1) / 2;
    ans -= w * (w - 1) / 2;
  }
  cout << ans << endl;
}
