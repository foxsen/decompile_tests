#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 5;
const int LOGN = 19;
bool vis[MAX];
int depth[MAX];
int tin[MAX], tout[MAX];
int fa[MAX][LOGN];
vector<int> adj[MAX];
int timer = 0;
int dist(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int dis = 0;
  for (int i = LOGN - 1; i >= 0; i--) {
    if (depth[u] - (1 << i) >= depth[v]) {
      u = fa[u][i];
      dis += 1 << i;
    }
  }
  if (u == v) return dis;
  for (int i = LOGN - 1; i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i];
      v = fa[v][i];
      dis += 1 << i + 1;
    }
  }
  return dis + 2;
}
void dfs(int u, int parent) {
  vis[u] = true;
  ++timer;
  tin[u] = timer;
  fa[u][0] = parent;
  if (parent != -1) {
    for (int i = 1; i < LOGN; i++) {
      fa[u][i] = fa[parent][i - 1];
    }
    depth[u] = 1 + depth[parent];
  } else {
    depth[u] = 0;
  }
  for (auto v : adj[u]) {
    if (!vis[v]) {
      dfs(v, u);
    }
  }
  ++timer;
  tout[u] = timer;
}
void print(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < LOGN; j++) {
      cout << fa[i][j] << " ";
    }
    cout << endl;
  }
  cout << "printing tin and tout" << endl;
  for (int i = 1; i <= n; i++) {
    cout << "tin -> " << tin[i] << " and tout -> " << tout[i] << endl;
  }
  cout << "printing depth" << endl;
  for (int i = 1; i <= n; i++) {
    cout << "depth -> " << depth[i] << endl;
  }
}
int main() {
  int n;
  cin >> n;
  int u, v;
  set<int> s1, s2;
  memset(fa, -1, sizeof(fa));
  depth[1] = 1;
  int maxi = 1;
  s1.insert(1);
  for (int u = 2; u <= n + 1; u++) {
    cin >> v;
    depth[u] = 1 + depth[v];
    fa[u][0] = v;
    for (int i = 1; (1 << i) < depth[u]; i++)
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
    int d1 = s1.empty() ? 0 : dist(u, *s1.begin());
    int d2 = s2.empty() ? 0 : dist(u, *s2.begin());
    if (max(d1, d2) > maxi) {
      maxi = max(d1, d2);
      if (d1 >= d2) {
        for (int x : s2) {
          if (dist(x, u) == maxi) s1.insert(x);
        }
        s2.clear();
        s2.insert(u);
      } else {
        for (int x : s1) {
          if (dist(x, u) == maxi) s2.insert(x);
        }
        s1.clear();
        s1.insert(u);
      }
    } else if (max(d1, d2) == maxi) {
      if (d1 >= d2) {
        s2.insert(u);
      } else {
        s1.insert(u);
      }
    }
    cout << s1.size() + s2.size() << endl;
  }
  return 0;
}
