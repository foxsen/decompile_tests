#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int c[N][N], sz[N * N], mp[N * N], dp[N][N];
int n, cn;
bool vis[N][N];
string s[N];
void dfs(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= n || vis[x][y] || s[x][y] == 'X') return;
  vis[x][y] = true;
  c[x][y] = cn;
  sz[cn]++;
  dfs(x - 1, y);
  dfs(x + 1, y);
  dfs(x, y - 1);
  dfs(x, y + 1);
}
int updRow(int x, int y, int k) {
  int i, j, temp = 0;
  for (i = y - k + 1; i <= y; i++) {
    if (x - k >= 0) {
      if (mp[c[x - k][i]] == 0) temp += sz[c[x - k][i]];
      mp[c[x - k][i]]++;
    }
    if (x + 1 < n) {
      if (mp[c[x + 1][i]] == 0) temp += sz[c[x + 1][i]];
      mp[c[x + 1][i]]++;
    }
  }
  return temp;
}
void remRow(int x, int y, int k) {
  int i, j;
  for (i = y - k + 1; i <= y; i++) {
    if (x - k >= 0) mp[c[x - k][i]]--;
    if (x + 1 < n) mp[c[x + 1][i]]--;
  }
}
int updCol(int x, int y, int k) {
  int i, j, temp = 0;
  for (i = x - k + 1; i <= x; i++) {
    if (y - k >= 0) {
      if (mp[c[i][y - k]] == 0) temp += sz[c[i][y - k]];
      mp[c[i][y - k]]++;
    }
    if (y + 1 < n) {
      if (mp[c[i][y + 1]] == 0) temp += sz[c[i][y + 1]];
      mp[c[i][y + 1]]++;
    }
  }
  return temp;
}
void remCol(int x, int y, int k) {
  int i, j;
  for (i = x - k + 1; i <= x; i++) {
    if (y - k >= 0) mp[c[i][y - k]]--;
    if (y + 1 < n) mp[c[i][y + 1]]--;
  }
}
int get(int x, int y, int k) {
  int ret = dp[x][y];
  if (x >= k) ret -= dp[x - k][y];
  if (y >= k) ret -= dp[x][y - k];
  if (x >= k && y >= k) ret += dp[x - k][y - k];
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int i, j, k, it;
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (!vis[i][j] && s[i][j] == '.') {
        cn++;
        dfs(i, j);
      }
      if (s[i][j] == 'X') dp[i][j]++;
      if (i > 0) dp[i][j] += dp[i - 1][j];
      if (j > 0) dp[i][j] += dp[i][j - 1];
      if (i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
    }
  }
  int out = 0;
  for (i = k - 1; i < n; i++) {
    int ans = 0, temp;
    memset(mp, 0, sizeof(mp));
    for (it = i - k + 1; it <= i; it++) {
      for (j = 0; j < k; j++) {
        mp[c[it][j]]++;
        if (mp[c[it][j]] == 1) ans += sz[c[it][j]];
      }
    }
    int t1 = updCol(i, k - 1, k), t2 = updRow(i, k - 1, k);
    temp = ans + get(i, k - 1, k) + t1 + t2;
    remCol(i, k - 1, k);
    remRow(i, k - 1, k);
    out = max(out, temp);
    for (j = k; j < n; j++) {
      for (it = i - k + 1; it <= i; it++) {
        int v = c[it][j - k];
        if (mp[v] == 1) ans -= sz[v];
        mp[v]--;
        v = c[it][j];
        mp[v]++;
        if (mp[v] == 1) ans += sz[v];
      }
      t1 = updCol(i, j, k), t2 = updRow(i, j, k);
      temp = ans + get(i, j, k) + t1 + t2;
      remCol(i, j, k);
      remRow(i, j, k);
      out = max(out, temp);
    }
  }
  cout << out << "\n";
}
