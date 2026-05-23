#include <bits/stdc++.h>
using namespace std;
const long long INFll = 1ll * 1000000100 * 1000000100;
const long double PI =
    3.141592653589793238462643383279502884197169399375105820974944;
vector<vector<int>> g;
int n, k;
vector<int> dist, par;
void bfs(int node) {
  queue<int> q;
  dist.assign(n, 1000000100);
  par.assign(n, -1);
  dist[node] = 0;
  q.push(node);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dist[v] == 1000000100) {
        par[v] = u;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}
void dfs(int node, int num, int p) {
  int cnt = 0;
  for (int v : g[node]) {
    if (v == p) continue;
    cnt++;
    dfs(v, num + 1, node);
  }
  if (num == k && cnt) {
    cout << "No" << endl;
    exit(0);
  } else if (num > k) {
    cout << "No" << endl;
    exit(0);
  } else if (num < k && cnt < 3) {
    cout << "No" << endl;
    exit(0);
  }
}
int main() {
  cin >> n >> k;
  g.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  bfs(0);
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (dist[i] > dist[x]) x = i;
  }
  int y = x;
  bfs(x);
  for (int i = 0; i < n; i++) {
    if (dist[i] > dist[y]) y = i;
  }
  int d = dist[y] / 2;
  if (dist[y] % 2) {
    cout << "No" << endl;
    exit(0);
  }
  int second = y;
  for (int i = 0; i < d; i++) second = par[second];
  dfs(second, 0, -1);
  cout << "Yes" << endl;
}
