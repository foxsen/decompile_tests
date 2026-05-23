#include <bits/stdc++.h>
using namespace std;
const long long P = 1e9 + 7;
const int N = 2005;
const long long INF = (1ll << 62) - 1;
const double pi = acos(-1);
mt19937 rng(time(0));
int T, n;
int f[N][N * 2], g[N][N * 2];
char s[N], t[N];
void revbit(char s[]) {
  for (int i = 2; i <= n; i += 2)
    if (s[i] != '?') s[i] = '0' + '1' - s[i];
}
void calc(int f[][N * 2], char s[], char t[]) {
  f[0][n + 1] = 1;
  for (int i = (1); i <= (n); ++i)
    for (int j = (n + 1 - i); j <= (n + 1 + i); ++j) {
      f[i][j] = ((s[i] != '1' && t[i] != '1') ? f[i - 1][j] : 0) % P;
      (f[i][j] += (s[i] != '0' && t[i] != '0') ? f[i - 1][j] : 0) %= P;
      (f[i][j] += (s[i] != '0' && t[i] != '1') ? f[i - 1][j - 1] : 0) %= P;
      (f[i][j] += (s[i] != '1' && t[i] != '0') ? f[i - 1][j + 1] : 0) %= P;
    }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> (s + 1) >> (t + 1);
    revbit(s), revbit(t);
    calc(f, s, t);
    reverse(s + 1, s + n + 1), reverse(t + 1, t + n + 1);
    calc(g, s, t);
    int ans = 0;
    for (int i = (1); i <= (n - 1); ++i)
      for (int j = (n + 1 - i); j <= (n + 1 + i); ++j)
        ans = (1ll * abs(n + 1 - j) * f[i][j] % P * g[n - i][n + n + 2 - j] +
               ans) %
              P;
    cout << ans << endl;
    for (int i = (0); i <= (n); ++i)
      for (int j = (n + 1 - i); j <= (n + 1 + i); ++j) f[i][j] = g[i][j] = 0;
  }
  return 0;
}
