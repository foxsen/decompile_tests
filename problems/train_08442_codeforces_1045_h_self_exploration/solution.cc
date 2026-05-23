#include <bits/stdc++.h>
using namespace std;
const int MaxN(100003);
const int Mod(1e9 + 7);
int fac[MaxN], inv[MaxN];
char s1[MaxN], s2[MaxN];
int fexp(int x, int k) {
  int res = 1;
  for (; k; k >>= 1, x = (long long)x * x % Mod)
    if (k & 1) res = (long long)res * x % Mod;
  return res;
}
inline int C(int n, int m) {
  return (n < 0 || m < 0 || n < m)
             ? 0
             : (long long)fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}
inline int val(int a, int b, int c, int d) {
  if (a == 0 && c == 0) return C(d - 1, b - 1);
  if (b == 0 && d == 0) return C(c - 1, a - 1);
  return (long long)C(c - 1, a - 1) * C(d - 1, b - 1) % Mod;
}
inline void upd(int &x, int y) { (x += y) >= Mod ? x -= Mod : x; }
int calc(char *s, int a, int b, int c, int d, int t) {
  int n = strlen(s), ans = 0;
  if (c + d > n) return 0;
  if (c + d < n) return val(a, b, c, d);
  for (int i = 0; i < n; i++) {
    if (i && s[i] != s[i - 1]) s[i] == '1' ? a-- : b--;
    if (s[i] == '1') {
      if (i && s[i - 1] == '1' && (a == b - 1 || a == b))
        upd(ans, val(a, b - 1, c, d));
      else if (i && s[i - 1] == '0' && (a + 1 == b || a == b))
        upd(ans, val(a + 1, b, c, d));
      d--;
    } else
      c--;
  }
  (s[n - 1] == '1') ? b-- : a--;
  if (t && !a && !b && !c && !d) upd(ans, 1);
  return ans;
}
int work(char *s, int a, int b, int c, int d) {
  int n = strlen(s);
  if (c + d != n) return 0;
  --d, --b;
  for (int i = 1; i < n; i++) {
    if (s[i] == '1')
      --d, b -= s[i - 1] == '0';
    else
      --c, a -= s[i - 1] == '1';
  }
  return a == 0 && b == 0 && c == 0 && d == 0;
}
int main() {
  int a, b, c, d;
  scanf("%s%s", s1, s2);
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if (b != c && b != c - 1) return puts("0"), 0;
  if (b == c)
    swap(a, b), swap(b, c), ++b, c += a, d += b;
  else
    swap(a, b), swap(b, c), ++a, c += a, d += b;
  for (int i = fac[0] = inv[0] = 1; i <= max(c, d); i++) {
    fac[i] = (long long)fac[i - 1] * i % Mod;
    inv[i] = fexp(fac[i], Mod - 2);
  }
  printf("%d\n",
         (calc(s2, a, b, c, d, 1) - calc(s1, a, b, c, d, 0) + Mod) % Mod);
  return 0;
}
