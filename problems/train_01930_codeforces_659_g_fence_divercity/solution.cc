#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1000011;
int n;
int h[MAX];
const int MOD = int(1e9) + 7;
inline int add(const int a, const int b, const int mod = MOD) {
  return (a + b >= mod) ? (a + b - mod) : (a + b);
}
inline int sub(const int a, const int b, const int mod = MOD) {
  return (a - b < 0) ? (a - b + mod) : (a - b);
}
inline void inc(int &a, const int b, const int mod = MOD) {
  a = add(a, b, mod);
}
inline int negate(const int a, const int mod = MOD) { return mod - a; }
inline int mul(const int a, const int b, const int mod = MOD) {
  return (a * 1ll * b) % mod;
}
int binPow(int b, int p, const int mod = MOD) {
  int r = 1;
  while (p) {
    if (p & 1) r = mul(r, b, mod);
    b = mul(b, b, mod);
    p >>= 1;
  }
  return r;
}
int inv(const int a, const int mod = MOD) {
  int res = binPow(a, mod - 2, mod);
  return res;
}
inline int dvd(const int a, const int b, const int mod = MOD) {
  return mul(a, inv(b, mod), mod);
}
void clear() {}
void solve() {
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
    h[i]--;
  }
  int ans = 0;
  int f = 0;
  for (int i = 0; i < n; i++) {
    ans = add(ans, h[i]);
    ans = add(ans, mul(i ? min(h[i], h[i - 1]) : h[i], f));
    if (i < n - 1) {
      int mnr = min(h[i], h[i + 1]);
      int mnl = i ? min(h[i], h[i - 1]) : h[i];
      int mn = min(mnl, mnr);
      int nf = mnr;
      nf = add(nf, mul(mn, f));
      f = nf;
    }
  }
  printf("%d\n", ans);
}
int main() {
  while (scanf("%d", &n) == 1) {
    clear();
    solve();
    return 0;
  }
  return 0;
}
