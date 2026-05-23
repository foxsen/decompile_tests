#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
const long long MOD = 1e9 + 7;
const int mod = 998244353;
inline long long qpow(long long b, long long e, long long m) {
  long long a = 1;
  for (; e; e >>= 1, b = b * b % m)
    if (e & 1) a = a * b % m;
  return a;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, x, y);
  long long z = x;
  x = y, y = z - y * (a / b);
  return d;
}
char s[maxn];
long long C[5009][5009];
void init() {
  C[0][0] = 1;
  for (int i = 1; i <= 5000; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      C[i][j] %= mod;
    }
  }
}
vector<int> ve;
int main() {
  init();
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  if (k == 0) {
    cout << "1" << '\n';
    return 0;
  }
  ve.push_back(0);
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') ve.push_back(i);
  }
  ve.push_back(n + 1);
  if (ve.size() - 2 < k) {
    cout << 1 << '\n';
    return 0;
  }
  long long ans = 0;
  for (int i = 1;; i++) {
    if (i + k >= ve.size()) break;
    ans += C[ve[i + k] - ve[i - 1] - 1][k];
    if (i + k < (int)ve.size() - 1) ans -= C[ve[i + k] - ve[i] - 1][k - 1];
    ans %= mod;
  }
  ans = (ans % mod + mod) % mod;
  cout << ans << '\n';
}
