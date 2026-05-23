#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e6;
const long long mod = 500001269;
int n;
bool ok;
long long h[nmax + 1];
long long pb[nmax + 1];
string s, a, b, c;
inline long long hsh(int x, int y) {
  long long ans = (h[y] - h[x - 1] * pb[y - x + 1]) % mod;
  if (ans < 0) ans += mod;
  return ans;
}
void check(int lg, int x) {
  if (lg > 0 && x > 0 && lg + x < n) {
    if ((s[n - lg + 1] == '0' && lg > 1) ||
        (s[n - lg - x + 1] == '0' && x > 1) || (s[1] == '0' && n - lg - x > 1))
      return;
    if (hsh(n - lg + 1, n) ==
        (hsh(1, n - lg - x) + hsh(n - lg - x + 1, n - lg)) % mod) {
      a.resize(n - lg - x);
      b.resize(x);
      c.resize(lg);
      for (int i = 1; i <= n - lg - x; ++i) {
        a[i - 1] = s[i];
      }
      for (int i = n - lg - x + 1; i <= n - lg; ++i) {
        b[i - (n - lg - x + 1)] = s[i];
      }
      for (int i = n - lg + 1; i <= n; ++i) {
        c[i - (n - lg + 1)] = s[i];
      }
      ok = 1;
    }
  }
}
int main() {
  cin >> s;
  n = (int)s.size();
  s = '#' + s;
  pb[0] = 1;
  for (int i = 1; i <= n; ++i) pb[i] = pb[i - 1] * 10 % mod;
  for (int i = 1; i <= n; ++i) h[i] = (h[i - 1] * 10 + s[i] - '0') % mod;
  ok = 0;
  for (int i = 1; i <= n / 2 && ok == 0; ++i) {
    if (!ok) check(i, i);
    if (!ok) check(i, i - 1);
    if (!ok) check(i, (n - i - i));
    if (!ok) check(i, (n - i - (i - 1)));
  }
  cout << a << "+" << b << "=" << c << "\n";
  return 0;
}
