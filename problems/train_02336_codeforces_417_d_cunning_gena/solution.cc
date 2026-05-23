#include <bits/stdc++.h>
using namespace std;
const long long PINF = numeric_limits<long long>::max();
const long long M = 1E9 + 7;
const double EPS = 1E-9;
struct frnd {
  int solved = 0;
  long long cost, monitors;
};
bool cmp(frnd a, frnd b) { return a.monitors < b.monitors; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, b;
  cin >> n >> m >> b;
  vector<frnd> friends(n + 1);
  for (int i = 0; i < n; i++) {
    int cnt;
    cin >> friends[i].cost >> friends[i].monitors >> cnt;
    for (int j = 0; j < cnt; j++) {
      int problem;
      cin >> problem;
      friends[i].solved |= (1 << (problem - 1));
    }
  }
  sort(friends.begin(), friends.end(), cmp);
  vector<long long> dp(1 << m, PINF);
  int full_mask = (1 << m) - 1;
  long long ans = PINF;
  dp[0] = 0;
  for (int f = 1; f <= n; f++) {
    for (int mask = 0; mask < (1 << m); mask++) {
      if (dp[mask] < PINF) {
        int new_mask = mask | friends[f].solved;
        dp[new_mask] = min(dp[new_mask], dp[mask] + friends[f].cost);
      }
    }
    if (dp[full_mask] < PINF) {
      ans = min(ans, dp[full_mask] + b * friends[f].monitors);
    }
  }
  if (ans == PINF)
    cout << -1 << '\n';
  else
    cout << ans << "\n";
  return 0;
}
