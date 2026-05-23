#include <bits/stdc++.h>
using namespace std;
const int N = 22, MOD = 1e9 + 7, mod = 205;
long long x, y, n, d, k, r;
pair<int, int> p[N];
int dp[550][550];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> x >> y >> n >> d;
  for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  k = d * d;
  for (int i = d; i >= -d; i--) {
    for (int j = d; j >= -d; j--) {
      if (i * i + j * j > k) {
        dp[i + mod][j + mod] = 1;
      } else {
        dp[i + mod][j + mod] = -1;
        for (int u = 0; u < n; u++) {
          int a, b, c, d;
          a = i + p[u].first;
          b = j + p[u].second;
          c = a * a;
          d = b * b;
          if (c + d <= k && dp[a + mod][b + mod] == -1) {
            dp[i + mod][j + mod] = 1;
            u = n + 1;
          }
        }
      }
    }
  }
  if (dp[x + mod][y + mod] == -1) {
    cout << "Dasha";
  } else
    cout << "Anton";
  return 0;
}
