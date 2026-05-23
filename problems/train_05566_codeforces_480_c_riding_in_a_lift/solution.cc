#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
struct Problem {
  static const ULL M = 1000000007;
  void Solve() {
    UL N, A, B, K;
    cin >> N >> A >> B >> K;
    A--;
    B--;
    vector<pair<UL, UL>> R(N);
    for (UL i = 0; i < (N); i++) {
      UL D = max(i, B) - min(i, B) - 1;
      UL l = i - min(i, D);
      UL r = i + min(N - i - 1, D);
      r++;
      R[i] = {l, r};
    }
    vector<ULL> dp[2];
    dp[0].resize(N + 1);
    dp[1].resize(N + 1);
    dp[0][A] = 1;
    for (UL i = 0; i < (K); i++) {
      for (UL j = 0; j < (N + 1); j++) dp[1][j] = 0;
      for (UL j = 0; j < (N); j++) {
        dp[1][R[j].first] += dp[0][j];
        dp[1][j] -= dp[0][j];
        dp[1][j + 1] += dp[0][j];
        dp[1][R[j].second] -= dp[0][j];
      }
      for (UL j = 0; j < (N); j++) dp[1][j + 1] += dp[1][j];
      for (UL j = 0; j < (N + 1); j++) dp[0][j] = dp[1][j] % M;
    }
    ULL ans = 0;
    for (UL i = 0; i < (N + 1); i++) ans += dp[0][i];
    ans %= M;
    cout << ans << endl;
  }
  Problem();
};
int main() {
  unique_ptr<Problem> p(new Problem());
  p->Solve();
  return 0;
}
Problem::Problem() { cout << fixed << setprecision(10); }
