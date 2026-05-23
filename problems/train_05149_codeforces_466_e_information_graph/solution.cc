#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, numpackets;
vector<pair<int, int> > queries[N];
int ans[N];
vector<int> children[N];
vector<int> toremove[N];
vector<int> toadd[N];
set<int> nums[N];
bool done[N];
struct DSU {
  int p[N];
  DSU() {
    for (int i = 0; i < N; ++i) p[i] = i;
  }
  inline int get(int x) { return p[x] == x ? x : (p[x] = get(p[x])); }
  inline void unite(int x, int y) { p[x] = y; }
} dsu;
void dfs(int u) {
  int bestch = -1;
  for (int v : children[u]) {
    dfs(v);
    if (bestch == -1 || nums[bestch].size() < nums[v].size()) {
      bestch = v;
    }
  }
  if (bestch != -1) {
    swap(nums[u], nums[bestch]);
  }
  for (int p : toadd[u]) {
    nums[u].insert(p);
  }
  for (int v : children[u]) {
    if (v == bestch) continue;
    while (!nums[v].empty()) {
      auto it = nums[v].begin();
      nums[u].insert(*it);
      nums[v].erase(it);
    }
  }
  for (pair<int, int>& query : queries[u]) {
    int p = query.first, id = query.second;
    ans[id] = nums[u].find(p) != nums[u].end();
  }
  for (int p : toremove[u]) {
    nums[u].erase(p);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  numpackets = 0;
  for (int i = 1; i <= m; ++i) {
    ans[i] = -1;
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      children[y].push_back(x);
      dsu.unite(x, y);
    } else if (t == 2) {
      int x;
      cin >> x;
      int root = dsu.get(x);
      ++numpackets;
      toadd[x].push_back(numpackets);
      toremove[root].push_back(numpackets);
    } else {
      int x, p;
      cin >> x >> p;
      queries[x].emplace_back(p, i);
    }
  }
  memset(done, false, sizeof(done));
  for (int i = 1; i <= n; ++i) {
    int root = dsu.get(i);
    if (!done[root]) {
      done[root] = true;
      dfs(root);
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (ans[i] != -1) {
    }
    if (ans[i] == 0) {
      cout << "NO\n";
    } else if (ans[i] == 1) {
      cout << "YES\n";
    }
  }
}
