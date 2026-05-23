#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], int i, vector<bool> &vis) {
  vis[i] = 1;
  for (auto it : adj[i]) {
    if (!vis[it])
      dfs(adj, it, vis);
    else {
      cout << it << " ";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  vector<int> adj[n + 1];
  for (int i = 1; i < n + 1; i = i + 1) {
    int x;
    cin >> x;
    adj[i].push_back(x);
  }
  vector<bool> vis(n + 1, 0);
  for (int i = 1; i < n + 1; i = i + 1) {
    vis = vector<bool>(n + 1, 0);
    dfs(adj, i, vis);
  }
  return 0;
}
