#include <bits/stdc++.h>
using namespace std;
int N, i, j, T, level, subtree[100111], centroid[100111][20], nc, M, Q, ans[20];
vector<vector<int>> G;
vector<int> persons[100111];
set<int> ps, plist[100111][20];
bool vis[100111];
void dfs(int v, int p);
int find_centroid(int v, int sz);
void dfs2(int v, int p);
int main() {
  scanf("%d", &N);
  scanf("%d", &M);
  scanf("%d", &Q);
  G.resize(N + 1);
  for (i = 0; i < (N - 1); i++) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (i = 0; i < (M); i++) {
    int a;
    scanf("%d", &a);
    persons[a].push_back(i + 1);
  }
  queue<pair<int, int>> q;
  q.push({1, 1});
  while (!q.empty()) {
    pair<int, int> c = q.front();
    q.pop();
    level = c.second;
    dfs(c.first, -1);
    nc = find_centroid(c.first, subtree[c.first]);
    dfs2(nc, -1);
    vis[nc] = true;
    for (auto &v : G[nc])
      if (!vis[v]) q.push({v, level + 1});
  }
  while (Q--) {
    int v, u, a, lv, lu;
    scanf("%d", &v);
    scanf("%d", &u);
    scanf("%d", &a);
    for (lv = 1; centroid[v][lv]; lv++)
      ;
    lv--;
    for (lu = 1; centroid[u][lu]; lu++)
      ;
    lu--;
    int lca = min(lv, lu);
    while (centroid[v][lca] != centroid[u][lca]) lca--;
    int taken = 0;
    set<int> &first = plist[v][lca], &second = plist[u][lca];
    auto f = first.begin(), s = second.begin();
    while (taken < a && (f != first.end() || s != second.end())) {
      if (f == first.end()) {
        ans[taken++] = *s;
        s++;
      } else if (s == second.end()) {
        ans[taken++] = *f;
        f++;
      } else if (*f < *s) {
        ans[taken++] = *f;
        f++;
      } else if (*f > *s) {
        ans[taken++] = *s;
        s++;
      } else {
        ans[taken++] = *f;
        f++;
        s++;
      }
    }
    printf("%d", taken);
    for (i = 0; i < (taken); i++) printf(" %d", ans[i]);
    printf("\n");
  }
}
void dfs(int v, int p) {
  subtree[v] = 1;
  for (auto &n : G[v]) {
    if (!vis[n] && n != p) {
      dfs(n, v);
      subtree[v] += subtree[n];
    }
  }
}
int find_centroid(int v, int sz) {
  int branch = v;
  for (auto &n : G[v]) {
    if (!vis[n] && subtree[n] > sz / 2) branch = n;
  }
  if (branch == v) return v;
  subtree[v] -= subtree[branch];
  subtree[branch] += subtree[v];
  return find_centroid(branch, sz);
}
void dfs2(int v, int p) {
  centroid[v][level] = nc;
  ps.insert((persons[v]).begin(), (persons[v]).end());
  auto it = ps.begin();
  for (int i = 0; i < 10 && it != ps.end(); i++, it++)
    plist[v][level].insert(*it);
  for (auto &n : G[v]) {
    if (!vis[n] && n != p) dfs2(n, v);
  }
  for (auto x : persons[v]) ps.erase(x);
}
