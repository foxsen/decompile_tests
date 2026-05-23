#include <bits/stdc++.h>
using namespace std;
long long n, m, c;
vector<long long> G[2005];
long long dp[2005][4005];
int ldp[2005][8005], rdp[2005][8005];
long long zero = 4002;
bool used[2005];
long long dfs(int v) {
  used[v] = true;
  for (long long(i) = (0); (i) <= ((int)G[v].size() - 1); (i)++) {
    if (used[G[v][i]]) continue;
    return dfs(G[v][i]) + 1;
  }
  return 1;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  long long u, v;
  for (long long(i) = (1); (i) <= (m); (i)++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<long long> vec;
  used[1] = true;
  for (long long(i) = (0); (i) <= ((int)G[1].size() - 1); (i)++) {
    long long v = G[1][i];
    if (used[v]) continue;
    vec.push_back(dfs(v) + 1);
  }
  c = vec.size();
  dp[0][0] = 1;
  for (long long(i) = (0); (i) <= (c - 1); (i)++) {
    for (long long(j) = (0); (j) <= (m); (j)++) {
      (dp[i + 1][j] += dp[i][j]) %= 1000000007;
      if (j + vec[i] <= m) (dp[i + 1][j + vec[i]] += dp[i][j]) %= 1000000007;
    }
  }
  ldp[0][zero] = 1;
  for (long long(i) = (0); (i) <= (c - 1); (i)++) {
    for (long long(j) = (-m); (j) <= (m); (j)++) {
      (ldp[i + 1][zero + j] += ldp[i][zero + j]) %= 1000000007;
      if (j + vec[i] <= m)
        (ldp[i + 1][zero + j + vec[i]] += ldp[i][zero + j]) %= 1000000007;
      if (j - vec[i] >= -m)
        (ldp[i + 1][zero + j - vec[i]] += ldp[i][zero + j]) %= 1000000007;
    }
  }
  rdp[c + 1][zero] = 1;
  for (int i = c + 1; i >= 2; i--) {
    for (long long(j) = (-m); (j) <= (m); (j)++) {
      (rdp[i - 1][zero + j] += rdp[i][zero + j]) %= 1000000007;
      if (j + vec[i - 2] <= m)
        (rdp[i - 1][zero + j + vec[i - 2]] += rdp[i][zero + j]) %= 1000000007;
      if (j - vec[i - 2] >= -m)
        (rdp[i - 1][zero + j - vec[i - 2]] += rdp[i][zero + j]) %= 1000000007;
    }
  }
  long long ans = 0;
  if (m % 2 == 0) ans += dp[c][m / 2];
  for (long long(i) = (1); (i) <= (c); (i)++) {
    for (int j = vec[i - 1] - 2; j >= -vec[i - 1] + 2; j--) {
      for (long long(k) = (-m); (k) <= (m); (k)++) {
        if (k + j < -m || k + j > m) continue;
        ans += (long long)ldp[i - 1][zero + k] *
               (long long)rdp[i + 1][zero + k + j] % 1000000007 * 2 %
               1000000007;
        ans %= 1000000007;
      }
    }
  }
  if (m % 2) {
    for (long long(i) = (0); (i) <= (c + 1); (i)++) {
      for (long long(j) = (-m); (j) <= (m); (j)++) {
        ldp[i][zero + j] = rdp[i][zero + j] = 0;
      }
    }
    ldp[0][zero] = 1;
    for (long long(i) = (0); (i) <= (c - 1); (i)++) {
      for (long long(j) = (-m); (j) <= (m); (j)++) {
        if (j + vec[i] <= m)
          (ldp[i + 1][zero + j + vec[i]] += ldp[i][zero + j]) %= 1000000007;
        if (j - vec[i] >= -m)
          (ldp[i + 1][zero + j - vec[i]] += ldp[i][zero + j]) %= 1000000007;
      }
    }
    rdp[c + 1][zero] = 1;
    for (int i = c + 1; i >= 2; i--) {
      for (long long(j) = (-m); (j) <= (m); (j)++) {
        if (j + vec[i - 2] <= m)
          (rdp[i - 1][zero + j + vec[i - 2]] += rdp[i][zero + j]) %= 1000000007;
        if (j - vec[i - 2] >= -m)
          (rdp[i - 1][zero + j - vec[i - 2]] += rdp[i][zero + j]) %= 1000000007;
      }
    }
    for (long long(i) = (1); (i) <= (c); (i)++) {
      long long j = vec[i - 1] - 1;
      for (long long(k) = (-m); (k) <= (m); (k)++) {
        if (k + j < -m || k + j > m) continue;
        ans += (long long)ldp[i - 1][zero + k] *
               (long long)rdp[i + 1][zero + k + j] % 1000000007 * 2 %
               1000000007;
        ans %= 1000000007;
      }
      j = -vec[i - 1] + 1;
      for (long long(k) = (-m); (k) <= (m); (k)++) {
        if (k + j < -m || k + j > m) continue;
        ans += (long long)ldp[i - 1][zero + k] *
               (long long)rdp[i + 1][zero + k + j] % 1000000007 * 2 %
               1000000007;
        ans %= 1000000007;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
