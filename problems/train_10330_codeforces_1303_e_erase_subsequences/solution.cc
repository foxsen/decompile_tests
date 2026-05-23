#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Min(T &a, T b) {
  a = min(a, b);
}
template <typename T>
void Max(T &a, T b) {
  a = max(a, b);
}
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 4e2 + 15;
int n, q, m;
int dp[N][N];
inline void yes() { cout << "YES" << '\n'; }
inline void no() { cout << "NO" << '\n'; }
string s, t;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> q;
  while (q--) {
    cin >> s >> t;
    n = s.size(), m = t.size();
    s = "#" + s + "#";
    t = "*" + t + "*";
    bool flag = false;
    for (int pos = 1; pos <= m; ++pos) {
      for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) dp[i][j] = -inf;
      dp[0][0] = 0;
      for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= pos; ++j) {
          Max(dp[i][j], dp[i - 1][j]);
          if (s[i] == t[j] && j) Max(dp[i][j], dp[i - 1][j - 1]);
          if (dp[i - 1][j] >= 0 && s[i] == t[pos + dp[i - 1][j] + 1])
            Max(dp[i][j], dp[i - 1][j] + 1);
        }
      flag |= dp[n][pos] >= m - pos;
    }
    if (flag)
      yes();
    else
      no();
  }
  return 0;
}
