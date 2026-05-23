#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 28;
const double INF = 1e12, EPS = 1e-9;
const int mod = (int)1e9 + 7;
int n, k;
long long dp[2][2], ans;
void run() {
  string a, b;
  cin >> a >> b >> k;
  dp[0][0] = 1;
  n = a.size();
  if (b.size() != n) {
    cout << 0 << endl;
    return;
  }
  int cur = 0, next = 1;
  for (int i = 0; i < k; i++) {
    dp[next][0] = dp[cur][1] * (n - 1) % mod;
    dp[next][1] = (dp[cur][0] + dp[cur][1] * (n - 2)) % mod;
    swap(cur, next);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (a[j] != b[(i + j) % n]) goto NEXT;
    (ans += dp[cur][i != 0]) %= mod;
  NEXT:;
  }
  cout << ans << endl;
}
int main() { run(); }
