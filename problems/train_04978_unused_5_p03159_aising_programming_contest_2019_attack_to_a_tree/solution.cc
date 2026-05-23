#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = 1e16;
const int MAXN = 5050;

using Arr = array<ll, 2>;

int N;
int A[MAXN];
vector<int> adj[MAXN];

vector<Arr> dfs(int v, int p) {
   vector<Arr> dp(1);
   dp[0][0] = A[v];
   if (A[v] > 0) dp[0][1] = A[v];
   else dp[0][1] = INF;
   for (int u : adj[v]) if (u != p) {
      auto nxt = dfs(u, v);
      vector<Arr> ndp(dp.size() + nxt.size(), Arr{INF, INF});
      for (int i = 0; i < int(dp.size()); ++i) {
         for (int j = 0; j < int(nxt.size()); ++j) {
            // cut this edge
            if (nxt[j][0] < 0 || nxt[j][1] < INF) {
               ndp[i + j + 1][0] = min(ndp[i + j + 1][0], dp[i][0]);
               ndp[i + j + 1][1] = min(ndp[i + j + 1][1], dp[i][1]);
            }
            if (dp[i][0] < INF && nxt[j][0] < INF) {
               ndp[i + j][0] = min(ndp[i + j][0], dp[i][0] + nxt[j][0]);
            }
            if (dp[i][1] < INF && nxt[j][1] < INF) {
               ndp[i + j][1] = min(ndp[i + j][1], dp[i][1] + nxt[j][1]);
            }
         }
      }
      dp = move(ndp);
   }
   return dp;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   for (int i = 1; i <= N; ++i) cin >> A[i];
   for (int i = 0; i < N - 1; ++i) {
      int v, u;
      cin >> v >> u;
      adj[v].emplace_back(u);
      adj[u].emplace_back(v);
   }
   auto ans = dfs(1, -1);
   int z = 0;
   while (ans[z][0] >= 0 && ans[z][1] == INF) z++;
   cout << z << "\n";
   return 0;
}
