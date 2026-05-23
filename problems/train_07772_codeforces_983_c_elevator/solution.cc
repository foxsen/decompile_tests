#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-12;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e3 + 4;
const int maxm = 720;
inline long long rule(long long x) { return (x %= MOD) += x < 0 ? MOD : 0; }
int hath[10000];
int rehath[maxm], up[maxm][10], down[maxm][10], dw[maxm][4][4],
    cost[maxm][4][4];
int ans = 0;
int dp[maxn][maxm];
vector<int> floors[maxm];
void dfs(int d, int lst, int val) {
  if (d == 4) {
    rehath[ans] = val;
    hath[val] = ans;
    ans++;
    return;
  }
  for (int i = lst; i <= 9; ++i) dfs(d + 1, i, val * 10 + i);
}
void init() {
  for (int i = 0; i < ans; ++i) {
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    int val = rehath[i];
    while (val) {
      cnt[val % 10]++;
      val /= 10;
    }
    val = rehath[i];
    for (int j = 1; j <= 9; ++j)
      if (cnt[j] == 0)
        down[i][j] = i;
      else {
        floors[i].push_back(j);
        int nxt = 0;
        cnt[j]--;
        for (int k = 1; k <= 9; ++k)
          for (int p = 0; p < cnt[k]; ++p) nxt = nxt * 10 + k;
        down[i][j] = hath[nxt];
        cnt[j]++;
      }
    for (int j = 1; j <= 9; ++j)
      if (val > 1000)
        up[i][j] = i;
      else {
        int nxt = 0;
        cnt[j]++;
        for (int k = 1; k <= 9; ++k)
          for (int p = 0; p < cnt[k]; ++p) nxt = nxt * 10 + k;
        up[i][j] = hath[nxt];
        cnt[j]--;
      }
  }
  for (int i = 0; i < ans; ++i) {
    for (int j = 0; j < floors[i].size(); ++j)
      for (int k = 0; k < floors[i].size(); ++k) {
        int& t = dw[i][j][k];
        t = i;
        cost[i][j][k] = abs(floors[i][j] - floors[i][k]);
        for (int ij = min(j, k); ij <= max(j, k); ++ij) {
          while (down[t][floors[i][ij]] != t)
            t = down[t][floors[i][ij]], cost[i][j][k]++;
        }
      }
  }
}
int n, x[maxn], y[maxn];
int main() {
  int ik, i, j, k, kase;
  dfs(0, 0, 0);
  init();
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  x[0] = 1;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  for (int i = 1; i <= n; ++i) {
    for (int s = 0; s < maxm; ++s) {
      if (dp[i - 1][s] == inf) continue;
      int sz = floors[s].size();
      for (int j = 0; j < sz; ++j)
        for (int k = 0; k < sz; ++k) {
          int st = dw[s][j][k];
          int upa = up[st][y[i]];
          dp[i][upa] = min(dp[i][upa], dp[i - 1][s] + cost[s][j][k] +
                                           abs(floors[s][j] - x[i - 1]) +
                                           abs(floors[s][k] - x[i]) + 1);
        }
      if (rehath[s] < 1000) {
        int upa = up[s][y[i]];
        dp[i][upa] = min(dp[i][upa], dp[i - 1][s] + 1 + abs(x[i] - x[i - 1]));
      }
    }
  }
  int ret = inf;
  for (int s = 0; s < maxm; ++s) {
    if (dp[n][s] == inf) continue;
    int sz = floors[s].size();
    ret = min(ret,
              dp[n][s] + cost[s][0][sz - 1] +
                  min(abs(x[n] - floors[s][0]), abs(x[n] - floors[s][sz - 1])));
  }
  cout << ret << endl;
  return 0;
}
