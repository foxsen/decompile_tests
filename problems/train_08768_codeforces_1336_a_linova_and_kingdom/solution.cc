#include <bits/stdc++.h>
using namespace std;
vector<int> g[210000];
int size[210000];
int depth[210000];
int n, k;
void init() {
  int x, y;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
}
vector<int> ans;
void dfs(int pos, int f) {
  size[pos] = 1;
  depth[pos] = depth[f] + 1;
  for (auto p : g[pos])
    if (p != f) {
      dfs(p, pos);
      size[pos] += size[p];
    }
  ans.push_back(depth[pos] - size[pos]);
}
int main() {
  init();
  dfs(1, 1);
  sort(ans.begin(), ans.end());
  long long sum = 0;
  for (int i = 0; i < k; i++) sum += ans[n - 1 - i];
  cout << sum;
  return ~~(0 ^ 0 ^ 0);
}
