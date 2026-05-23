#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
int N;
long long X, Y;
vector<int> G[MAX];
long long dp[MAX][2];
bool is_star() {
  for (int i = 0; i < N; i++) {
    if (G[i].size() == N - 1) {
      return true;
    }
  }
  return false;
}
long long DP(int u, int p, int k) {
  if (dp[u][k] != -1) {
    return dp[u][k];
  }
  dp[u][k] = Y * N;
  int ch = 0;
  for (int v : G[u])
    if (v != p) {
      ch++;
    }
  if (k == 0) {
    dp[u][k] = 0;
    for (int v : G[u])
      if (v != p) {
        dp[u][k] += Y + DP(v, u, 0);
      }
    vector<long long> diff;
    for (int v : G[u])
      if (v != p) {
        diff.push_back((X + DP(v, u, 1)) - (Y + DP(v, u, 0)));
      }
    int chosen1 = -1;
    if (diff.size() >= 1) {
      for (int i = 0; i < diff.size(); i++) {
        if (diff[i] < 0) {
          if (chosen1 == -1 || diff[i] < diff[chosen1]) {
            chosen1 = i;
          }
        }
      }
      if (chosen1 != -1) {
        dp[u][k] += diff[chosen1];
      }
    }
    int chosen2 = -1;
    if (diff.size() >= 2) {
      for (int i = 0; i < diff.size(); i++) {
        if (diff[i] < 0 && i != chosen1) {
          if (chosen2 == -1 || diff[i] < diff[chosen2]) {
            chosen2 = i;
          }
        }
      }
      if (chosen2 != -1) {
        dp[u][k] += diff[chosen2];
      }
    }
  } else {
    dp[u][k] = 0;
    for (int v : G[u])
      if (v != p) {
        dp[u][k] += Y + DP(v, u, 0);
      }
    vector<long long> diff;
    for (int v : G[u])
      if (v != p) {
        diff.push_back((X + DP(v, u, 1)) - (Y + DP(v, u, 0)));
      }
    int chosen1 = -1;
    if (diff.size() >= 1) {
      for (int i = 0; i < diff.size(); i++) {
        if (chosen1 == -1 || diff[i] < diff[chosen1]) {
          chosen1 = i;
        }
      }
      if (chosen1 != -1) {
        dp[u][k] += diff[chosen1];
      }
    }
  }
  return dp[u][k];
}
long long solve_lower() {
  memset(dp, -1, sizeof dp);
  return min(DP(0, -1, 0), DP(0, -1, 1));
}
long long solve_higher() {
  if (is_star()) {
    return (N - 2) * Y + X;
  } else {
    return (N - 1) * Y;
  }
}
int main() {
  cin >> N >> X >> Y;
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  long long ans;
  if (X <= Y) {
    ans = solve_lower();
  } else {
    ans = solve_higher();
  }
  cout << ans << endl;
}
