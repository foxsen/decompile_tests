#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[100005];
long long parent[100005];
vector<long long> temp;
void find_parent(long long v, long long par) {
  parent[v] = par;
  for (auto p : adj[v])
    if (p != par) find_parent(p, v);
}
long long find_col(long long x, long long y) {
  long long z;
  if (x == 1 && y == 2) z = 3;
  if (x == 2 && y == 1) z = 3;
  if (x == 1 && y == 3) z = 2;
  if (x == 3 && y == 1) z = 2;
  if (x == 2 && y == 3) z = 1;
  if (x == 3 && y == 2) z = 1;
  return z;
}
void dfs(long long v, long long par) {
  if (temp[v] == 0) {
    temp[v] = find_col(temp[par], temp[parent[par]]);
  }
  for (auto p : adj[v])
    if (p != par) dfs(p, v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, i, j, x, y;
  cin >> n;
  long long c1[n + 1], c2[n + 1], c3[n + 1];
  for (i = 1; i <= n; i++) cin >> c1[i];
  for (i = 1; i <= n; i++) cin >> c2[i];
  for (i = 1; i <= n; i++) cin >> c3[i];
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (i = 1; i <= n; i++) {
    if (adj[i].size() > 2) {
      cout << "-1";
      return 0;
    }
  }
  find_parent(1, 0);
  long long ans = 1e18, cost;
  long long col[n + 1];
  temp.assign(n + 1, 0);
  temp[1] = 1;
  temp[adj[1][0]] = 2;
  if (adj[1].size() == 2) temp[adj[1][1]] = 3;
  dfs(1, 0);
  cost = 0;
  for (i = 1; i <= n; i++) {
    if (temp[i] == 1) cost += c1[i];
    if (temp[i] == 2) cost += c2[i];
    if (temp[i] == 3) cost += c3[i];
  }
  if (cost < ans) {
    ans = cost;
    for (i = 1; i <= n; i++) col[i] = temp[i];
  }
  temp.assign(n + 1, 0);
  temp[1] = 1;
  temp[adj[1][0]] = 3;
  if (adj[1].size() == 2) temp[adj[1][1]] = 2;
  dfs(1, 0);
  cost = 0;
  for (i = 1; i <= n; i++) {
    if (temp[i] == 1) cost += c1[i];
    if (temp[i] == 2) cost += c2[i];
    if (temp[i] == 3) cost += c3[i];
  }
  if (cost < ans) {
    ans = cost;
    for (i = 1; i <= n; i++) col[i] = temp[i];
  }
  temp.assign(n + 1, 0);
  temp[1] = 2;
  temp[adj[1][0]] = 1;
  if (adj[1].size() == 2) temp[adj[1][1]] = 3;
  dfs(1, 0);
  cost = 0;
  for (i = 1; i <= n; i++) {
    if (temp[i] == 1) cost += c1[i];
    if (temp[i] == 2) cost += c2[i];
    if (temp[i] == 3) cost += c3[i];
  }
  if (cost < ans) {
    ans = cost;
    for (i = 1; i <= n; i++) col[i] = temp[i];
  }
  temp.assign(n + 1, 0);
  temp[1] = 2;
  temp[adj[1][0]] = 3;
  if (adj[1].size() == 2) temp[adj[1][1]] = 1;
  dfs(1, 0);
  cost = 0;
  for (i = 1; i <= n; i++) {
    if (temp[i] == 1) cost += c1[i];
    if (temp[i] == 2) cost += c2[i];
    if (temp[i] == 3) cost += c3[i];
  }
  if (cost < ans) {
    ans = cost;
    for (i = 1; i <= n; i++) col[i] = temp[i];
  }
  temp.assign(n + 1, 0);
  temp[1] = 3;
  temp[adj[1][0]] = 1;
  if (adj[1].size() == 2) temp[adj[1][1]] = 2;
  dfs(1, 0);
  cost = 0;
  for (i = 1; i <= n; i++) {
    if (temp[i] == 1) cost += c1[i];
    if (temp[i] == 2) cost += c2[i];
    if (temp[i] == 3) cost += c3[i];
  }
  if (cost < ans) {
    ans = cost;
    for (i = 1; i <= n; i++) col[i] = temp[i];
  }
  temp.assign(n + 1, 0);
  temp[1] = 3;
  temp[adj[1][0]] = 2;
  if (adj[1].size() == 2) temp[adj[1][1]] = 1;
  dfs(1, 0);
  cost = 0;
  for (i = 1; i <= n; i++) {
    if (temp[i] == 1) cost += c1[i];
    if (temp[i] == 2) cost += c2[i];
    if (temp[i] == 3) cost += c3[i];
  }
  if (cost < ans) {
    ans = cost;
    for (i = 1; i <= n; i++) col[i] = temp[i];
  }
  cout << ans << "\n";
  for (i = 1; i <= n; i++) cout << col[i] << " ";
}
