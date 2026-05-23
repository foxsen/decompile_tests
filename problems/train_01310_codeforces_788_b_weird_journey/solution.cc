#include <bits/stdc++.h>
using namespace std;
bool mark[1000005], visited[1000005];
long long loop, res, n, m;
vector<int> graph[1000005];
void dfs(int u) {
  visited[u] = 1;
  int len = graph[u].size();
  for (int i = 0; i < len; i++) {
    int v = graph[u][i];
    if (visited[v] == 1) continue;
    dfs(v);
  }
}
long long compute(long long num) { return (num * (num - 1)) / 2LL; }
int main() {
  cin >> n >> m;
  loop = 0;
  for (long long i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    mark[u] = 1;
    mark[v] = 1;
    if (u != v) {
      graph[u].push_back(v);
      graph[v].push_back(u);
    } else
      loop++;
  }
  int cmp = 0;
  for (long long i = 1; i <= n; i++) {
    if (mark[i] == 0) continue;
    if (visited[i]) continue;
    cmp++;
    dfs(i);
  }
  if (cmp > 1) {
    cout << 0 << endl;
    return 0;
  }
  res = 0;
  for (long long i = 1; i <= n; i++) res += compute(graph[i].size());
  res += (long long)compute(loop);
  res += (long long)(loop * (m - loop));
  cout << res << endl;
  return 0;
}
