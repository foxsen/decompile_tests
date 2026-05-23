#include <bits/stdc++.h>
using namespace std;
const double inf = 1e15;
const int maxn = 2e5 + 0.5;
int n, a[maxn + 10];
vector<int> G[maxn + 10];
long long dp[maxn + 5][2];
void update(long long& x, long long val) {
  if (val > x) x = val;
}
void dfs(int x) {
  int siz = G[x].size();
  dp[x][0] = 0;
  dp[x][1] = -inf;
  for (int(i) = 0; (i) < (siz); (i)++) {
    int y = G[x][i];
    dfs(y);
    long long ret0 = dp[x][0], ret1 = dp[x][1];
    update(dp[x][0], max(ret1 + dp[y][1], ret0 + dp[y][0]));
    update(dp[x][1], max(ret1 + dp[y][0], ret0 + dp[y][1]));
  }
  dp[x][1] = max(dp[x][1], dp[x][0] + a[x]);
}
int main() {
  std::ios::sync_with_stdio(false);
  while (cin >> n) {
    for (int(i) = 1; (i) <= (n); (i)++) G[i].clear();
    int x;
    for (int(i) = 1; (i) <= (n); (i)++) {
      cin >> x >> a[i];
      if (~x) G[x].push_back(i);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << endl;
  }
  return 0;
}
