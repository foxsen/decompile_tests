#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > adj;
vector<bool> top;
vector<int> branched;
vector<bool> visited;
vector<bool> fertile;
int root = -1;
void fail() {
  cout << "No" << endl;
  exit(0);
}
void dfsFindRoot(int u) {
  if (root != -1) return;
  visited[u] = true;
  bool leaf = true;
  for (int child : adj[u]) {
    if (visited[child]) continue;
    leaf = false;
  }
  if (!leaf) {
    branched[u] = 0;
    for (int child : adj[u]) {
      if (visited[child]) continue;
      dfsFindRoot(child);
      branched[u] += branched[child];
    }
    if (root != -1) return;
    if (branched[u] >= 3) {
      root = u;
    }
  }
}
void dfs(int u) {
  visited[u] = true;
  bool leaf = true;
  for (int child : adj[u]) {
    if (visited[child]) continue;
    leaf = false;
  }
  if (!leaf) {
    branched[u] = 0;
    int numTops = 0;
    for (int child : adj[u]) {
      if (visited[child]) continue;
      dfs(child);
      if (fertile[child]) top[u] = true;
      branched[u] += branched[child];
      if (top[child]) {
        numTops++;
        top[u] = true;
      }
    }
    if (u != root && numTops > 1)
      fail();
    else if (numTops > 2)
      fail();
    if (branched[u] >= 3) {
      top[u] = true;
    } else if (branched[u] == 2)
      fertile[u] = true;
  }
}
int main() {
  int m;
  cin >> n;
  adj = vector<vector<int> >(n, vector<int>(0));
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (n <= 4) {
    cout << "YES" << endl;
    return 0;
  }
  top = vector<bool>(n, false);
  branched = vector<int>(n, 1);
  visited = vector<bool>(n, false);
  dfsFindRoot(0);
  if (root == -1) {
    cout << "Yes" << endl;
    return 0;
  }
  top = vector<bool>(n, false);
  branched = vector<int>(n, 1);
  visited = vector<bool>(n, false);
  fertile = vector<bool>(n, false);
  dfs(root);
  cout << "Yes" << endl;
}
