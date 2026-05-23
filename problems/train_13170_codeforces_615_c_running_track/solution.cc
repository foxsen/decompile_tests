#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int N = 2105;
int dp[N], lcp[N][N], lcpr[N][N], lmatch[N];
pair<int, int> subs[N];
int par[N];
string s, t;
int n, m;
void print(int idx) {
  if (idx != 0) print(par[idx]);
  cout << subs[idx].first + 1 << " " << subs[idx].second + 1 << "\n";
}
int main() {
  cin >> s >> t;
  n = s.size();
  m = t.size();
  for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (t[i] != s[j])
        lcp[i][j] = 0;
      else
        lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }
  }
  reverse(s.begin(), s.end());
  for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (t[i] != s[j])
        lcpr[i][j] = 0;
      else
        lcpr[i][j] = lcpr[i + 1][j + 1] + 1;
    }
  }
  for (int i = 0; i < m; ++i) {
    int midx = max_element(lcp[i], lcp[i] + n) - lcp[i];
    lmatch[i] = lcp[i][midx];
    subs[i] = {midx, midx + lmatch[i] - 1};
    midx = max_element(lcpr[i], lcpr[i] + n) - lcpr[i];
    if (lmatch[i] < lcpr[i][midx]) {
      lmatch[i] = lcpr[i][midx];
      subs[i] = {n - 1 - midx, n - 1 - midx - lmatch[i] + 1};
    }
  }
  fill(dp + 1, dp + m + 1, INF);
  for (int i = 0; i < m; ++i) {
    if (dp[i + lmatch[i]] > dp[i] + 1) {
      dp[i + lmatch[i]] = dp[i] + 1;
      par[i + lmatch[i]] = i;
    }
  }
  if (dp[m] >= INF) {
    puts("-1");
    return 0;
  }
  cout << dp[m] << "\n";
  print(par[m]);
  return 0;
}
