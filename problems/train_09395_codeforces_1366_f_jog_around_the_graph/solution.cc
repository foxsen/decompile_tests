#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int mod = 1000000007;
int dp[N][N];
vector<int> v[N], w[N];
pair<int, int> a[N], b[N];
void update(int &first, int second) {
  if (first == -1 || first < second) first = second;
}
int main() {
  int n, m, r;
  scanf("%d%d%d", &n, &m, &r);
  memset(dp, -1, sizeof(dp));
  dp[0][1] = 0;
  for (int i = 1; i <= m; i++) {
    int first, second, z;
    scanf("%d%d%d", &first, &second, &z);
    v[first].push_back(second);
    w[first].push_back(z);
    v[second].push_back(first);
    w[second].push_back(z);
  }
  long long ans = 0;
  for (int t = 0; t < m; t++) {
    for (int j = 1; j <= n; j++) {
      if (dp[t][j] == -1) continue;
      for (int k = 0; k < v[j].size(); k++) {
        int vv = v[j][k];
        int d = w[j][k];
        update(dp[t + 1][vv], dp[t][j] + d);
      }
    }
    int mx = -1;
    for (int j = 1; j <= n; j++) update(mx, dp[t + 1][j]);
    ans = (ans + mx) % mod;
  }
  for (int i = 1; i <= n; i++) {
    b[i] = make_pair(0, dp[m][i]);
    for (int j = 0; j < w[i].size(); j++) b[i].first = max(b[i].first, w[i][j]);
  }
  int c = 0;
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    for (int j = i + 1; j <= n; j++) {
      if (b[i].first <= b[j].first && b[i].second <= b[j].second) flag = false;
    }
    if (flag) a[++c] = b[i];
  }
  r -= m;
  int pre = 0;
  for (int i = 1; i <= c; i++) {
    int mi = r;
    for (int j = i + 1; j <= c; j++) {
      int t = (a[i].second - a[j].second) / (a[j].first - a[i].first);
      mi = min(mi, t);
    }
    if (mi <= pre) continue;
    ans = (ans + 1LL * (mi - pre) * a[i].second) % mod;
    ans =
        (ans + 1LL * (mi - pre) * (mi + pre + 1) / 2 % mod * a[i].first) % mod;
    pre = mi;
  }
  cout << ans << endl;
  return 0;
}
