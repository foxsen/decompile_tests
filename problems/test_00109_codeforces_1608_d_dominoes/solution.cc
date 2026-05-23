#include <bits/stdc++.h>
using namespace std;
char ch[100010][5];
const int mod = 998244353;
int fac[200010], facinv[200010];
long long qpow(long long a, long long b) {
  long long m = 1;
  while (b) {
    if (b & 1) m = m * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return m;
}
void init(int x) {
  fac[0] = 1;
  int i;
  for (i = 1; i <= x; ++i) fac[i] = (long long)fac[i - 1] * i % mod;
  facinv[x] = qpow(fac[x], mod - 2);
  for (i = x; i >= 1; --i) facinv[i - 1] = (long long)facinv[i] * i % mod;
}
long long C(int a, int b) {
  if (b < 0 || b > a) return 0;
  return (long long)fac[a] * facinv[b] % mod * facinv[a - b] % mod;
}
int main() {
  init(200000);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int i, x = 0, x1 = 0;
  for (i = 1; i <= n; ++i) {
    cin >> ch[i];
    if (ch[i][0] == 'W') {
      if (ch[i][1] == 'W')
        ++x;
      else if (ch[i][1] == '?')
        ++x1;
    } else if (ch[i][0] == 'B') {
      if (ch[i][1] == 'B')
        --x;
      else if (ch[i][1] == '?')
        --x, ++x1;
    } else {
      if (ch[i][1] == 'W')
        ++x1;
      else if (ch[i][1] == 'B')
        ++x1, --x;
      else
        x1 += 2, --x;
    }
  }
  long long ans = C(x1, -x);
  bool flag = 0;
  for (i = 1; i <= n; ++i) {
    if (ch[i][0] == ch[i][1]) {
      if (ch[i][0] != '?') flag = 1;
    }
  }
  if (!flag) {
    int cnt1 = 0, cnt2 = 0, cnt = 0;
    for (i = 1; i <= n; ++i) {
      if (ch[i][0] == 'W')
        ++cnt1;
      else if (ch[i][0] == 'B')
        ++cnt2;
      else {
        if (ch[i][1] == 'W')
          ++cnt2;
        else if (ch[i][1] == 'B')
          ++cnt1;
        else
          ++cnt;
      }
    }
    if (!cnt1 || !cnt2) {
      if (!cnt1 && !cnt2)
        ans = (ans + mod - qpow(2, cnt) + 2) % mod;
      else
        ans = (ans + mod - qpow(2, cnt) + 1) % mod;
    } else
      ans = (ans + mod - qpow(2, cnt)) % mod;
  }
  cout << ans << '\n';
  return 0;
}
