#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long dp[7000][2];
long long cnt[7000][2];
vector<long long> moves[2];
void dfs(long long i, long long j, long long n) {
  if (dp[i][j] == 0) {
    for (long long ele : moves[1 ^ j]) {
      long long dest = (i - ele + n) % n;
      if (dp[dest][1 ^ j] == -1) {
        dp[dest][1 ^ j] = 1;
        dfs(dest, 1 ^ j, n);
      }
    }
  } else {
    for (long long ele : moves[1 ^ j]) {
      long long dest = (i - ele + n) % n;
      cnt[dest][1 ^ j]++;
      if (dp[dest][1 ^ j] == -1 && cnt[dest][1 ^ j] == moves[1 ^ j].size()) {
        dp[dest][1 ^ j] = 0;
        dfs(dest, 1 ^ j, n);
      }
    }
  }
}
int32_t main() {
  c_p_c();
  long long n;
  cin >> n;
  long long k1;
  cin >> k1;
  while (k1--) {
    long long m;
    cin >> m;
    moves[0].push_back(m);
  }
  long long k2;
  cin >> k2;
  while (k2--) {
    long long m;
    cin >> m;
    moves[1].push_back(m);
  }
  memset(dp, -1, sizeof(dp));
  memset(cnt, 0, sizeof(cnt));
  dp[0][0] = 0;
  dp[0][1] = 0;
  dfs(0, 0, n);
  dfs(0, 1, n);
  for (long long i = 1; i < n; i++) {
    if (dp[i][0] == -1)
      cout << "Loop"
           << " ";
    else if (dp[i][0] == 0)
      cout << "Lose"
           << " ";
    else
      cout << "Win"
           << " ";
  }
  cout << endl;
  for (long long i = 1; i < n; i++) {
    if (dp[i][1] == -1)
      cout << "Loop"
           << " ";
    else if (dp[i][1] == 0)
      cout << "Lose"
           << " ";
    else
      cout << "Win"
           << " ";
  }
}
