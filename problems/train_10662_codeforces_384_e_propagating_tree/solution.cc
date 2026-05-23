#include <bits/stdc++.h>
using namespace std;
const int c = 2e5 + 5;
int strength[c], level[c], size[c], visited[c], tree_even[4 * c],
    tree_odd[4 * c], M;
std::vector<int> v[c], preorder;
map<int, int> Map;
int dfs(int vertex, int lev) {
  if (visited[vertex]) return 0;
  visited[vertex] = 1;
  level[vertex] = lev;
  size[vertex] = 1;
  preorder.push_back(vertex);
  Map[vertex] = (int)preorder.size() - 1;
  for (int i = 0; i < (int)v[vertex].size(); i++) {
    size[vertex] += dfs(v[vertex][i], lev + 1);
  }
  return size[vertex];
}
void update(int index, int s, int e, int l, int r, int val) {
  if (e < l || s > r) return;
  if (s >= l && e <= r) {
    if (M == 0)
      tree_even[index] += val;
    else
      tree_odd[index] += val;
    return;
  }
  int mid = (s + e) / 2;
  update(2 * index, s, mid, l, r, val);
  update(2 * index + 1, mid + 1, e, l, r, val);
  return;
}
int sum;
int query(int index, int l, int r, int i) {
  if (i < l || i > r) return 0;
  if (l <= i && i <= r) {
    if (M == 0)
      sum += tree_even[index] - tree_odd[index];
    else
      sum += tree_odd[index] - tree_even[index];
  }
  if (l == r) return 0;
  int mid = (l + r) / 2;
  query(2 * index, l, mid, i);
  query(2 * index + 1, mid + 1, r, i);
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, v1, v2, type, node, upd, start;
  cin >> n >> m;
  for (int i = 1; i < n + 1; i++) cin >> strength[i];
  for (int i = 0; i < n - 1; i++) {
    cin >> v1 >> v2;
    v[v1].push_back(v2);
    v[v2].push_back(v1);
  }
  preorder.push_back(0);
  dfs(1, 0);
  while (m--) {
    cin >> type;
    if (type == 1) {
      cin >> node >> upd;
      start = Map[node];
      M = level[node] % 2;
      update(1, 1, n, start, start + size[node] - 1, upd);
    } else {
      cin >> node;
      start = Map[node];
      M = level[node] % 2;
      sum = strength[node];
      query(1, 1, n, start);
      cout << sum << "\n";
    }
  }
  return 0;
}
