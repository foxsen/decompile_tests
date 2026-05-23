#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T>
inline void scan_d(T &ret) {
  char c;
  int flag = 0;
  ret = 0;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-') {
    flag = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') ret = ret * 10 + (c - '0'), c = getchar();
  if (flag) ret = -ret;
}
const int maxn = 200000 + 10;
vector<int> v[maxn];
int dp[maxn], ge;
void dfs(int u, int fa, int dep, int flag) {
  int sz = v[u].size();
  if (dep % 2) {
    if (flag)
      dp[u] = maxn;
    else
      dp[u] = 0;
    for (int i = 0; i < sz; i++)
      if (v[u][i] != fa) {
        dfs(v[u][i], u, dep + 1, flag);
        if (flag)
          dp[u] = min(dp[u], dp[v[u][i]]);
        else
          dp[u] += dp[v[u][i]];
      }
    if (dp[u] == maxn || dp[u] == 0) {
      if (flag) ge++;
      dp[u] = 1;
    }
  } else {
    if (flag)
      dp[u] = 0;
    else
      dp[u] = maxn;
    for (int i = 0; i < sz; i++)
      if (v[u][i] != fa) {
        dfs(v[u][i], u, dep + 1, flag);
        if (flag)
          dp[u] += dp[v[u][i]];
        else
          dp[u] = min(dp[u], dp[v[u][i]]);
      }
    if (dp[u] == maxn || dp[u] == 0) {
      if (flag) ge++;
      dp[u] = 1;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int t1, t2;
    scanf("%d%d", &t1, &t2);
    v[t1].push_back(t2);
    v[t2].push_back(t1);
  }
  int ans1, ans2;
  ge = 0;
  dfs(1, 1, 1, 1);
  ans1 = ge - dp[1] + 1;
  dfs(1, 1, 1, 0);
  ans2 = dp[1];
  printf("%d %d\n", ans1, ans2);
  return 0;
}
