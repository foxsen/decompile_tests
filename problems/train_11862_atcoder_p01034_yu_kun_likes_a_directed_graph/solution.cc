#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edge;
#define to first
#define cost second

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m, w;
  cin >> n >> m >> w;

  vector<int> in(n, 0);
  vector<vector<edge>> G(n);
  for(int i = 0; i < m; ++i) {
    int s, t, c;
    cin >> s >> t >> c;
    G[s].emplace_back(t, c);
    ++in[t];
  }

  const int abs_w = abs(w);

  vector<vector<int>> dp(n, vector<int>(abs_w, false));
  queue<int> que;

  for(int v = 0; v < n; ++v) {
    if(in[v] == 0) que.push(v);
  }

  int ans = INT_MIN;
  while(!que.empty()) {
    const int v = que.front();
    que.pop();

    for(int i = 0; i < abs_w; ++i) {
      if(dp[v][i]) {
	ans = max(ans, i - abs_w);
      }
    }

    for(const auto &e : G[v]) {
      for(int i = abs_w - 1 - e.cost; i >= 0; --i) {
	dp[e.to][i + e.cost] |= (i == 0 ? true : dp[v][i]);
      }

      if(--in[e.to] == 0) {
	que.push(e.to);
      }
    }
  }

  cout << (ans == INT_MIN ? "NA" : to_string(ans)) << endl;

  return 0;
}
