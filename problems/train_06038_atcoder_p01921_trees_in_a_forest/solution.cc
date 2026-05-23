//
// Writer: kurita
// states: AC
// O(N log(N))
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<int> > Graph;
map<vector<int>, int> tree_hash;

vector<Graph> ConectedComponent(Graph &f) {
  int n = f.size(), pos = 0;
  vector<bool> used(n, false);
  vector<Graph> res;
  queue<int> que;
  while(pos < n){
    vector<int> used_vertex;
    int size = 0;
    que.push(pos);
    used[pos] = true;
    while(not que.empty()){
      size++;
      int v = que.front();
      used_vertex.push_back(v);
      que.pop();
      for (int i = 0; i < f[v].size(); i++) {
        if(used[f[v][i]] == true)continue;
        que.push(f[v][i]);
        used[f[v][i]] = true;
      }
    }
    sort(used_vertex.begin(), used_vertex.end());
    Graph g(used_vertex.size());
    for (int i = 0; i < used_vertex.size(); i++) {
      for (int j = 0; j < f[used_vertex[i]].size(); j++) {
        g[i].push_back(lower_bound(used_vertex.begin(), used_vertex.end(), f[used_vertex[i]][j]) -
                       used_vertex.begin());
      }
    }
    res.push_back(g);
    while(pos < n and used[pos])pos++;
  }
  return res;
}

vector<int> BFS(const Graph &g, vector<int> &dist, int v){
  int n = g.size();
  queue<pii> que;
  vector<int> parent(n);
  for (int i = 0; i < n; i++) parent[i] = i;
  que.push(pii(v, 0));
  dist[v] = 0;
  while(not que.empty()){
    int v = que.front().first;
    int d = que.front().second;
    que.pop();
    for (int i = 0; i < g[v].size(); i++) {
      if(dist[g[v][i]] >= 0)continue;
      dist[g[v][i]] = d + 1;
      parent[g[v][i]] = v;
      que.push(pii(g[v][i], d + 1));
    }
  }
  return parent;
}

inline vector<int> CenterTree(const Graph &g, int v = 0){
  int n = g.size();
  vector<int> dist(n, -1);
  BFS(g, dist, v);
  int u, maxi = -1;
  for (int i = 0; i < n; i++) {
    if(dist[i] > maxi){
      u = i, maxi = dist[i];
    }
  }
  dist = vector<int>(n, -1);
  vector<int> parent = BFS(g, dist, u);
  int diam = 0;
  for (int i = 0; i < n; i++) {
    if(dist[i] > diam) diam = dist[i], v = i;
  }
  
  for (int i = 0; i < diam/2; i++) v = parent[v];
  
  vector<int> res;
  res.push_back(v);
  if(diam%2 != 0)res.push_back(parent[v]);
  return res;
}

int AHUHash(const Graph &t, int v, int parent = -1){
  if(t[v].size() == 1 and parent != -1)return 0;
  vector<int> res;
  for (int i = 0; i < t[v].size(); i++) {
    if(t[v][i] == parent)continue;
    res.emplace_back(AHUHash(t, t[v][i], v));
  }
  sort(res.begin(), res.end());
  if(tree_hash.count(res) == 0){
    tree_hash[res] = 0;
    tree_hash[res] = tree_hash.size();
  }
  return tree_hash[res];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  Graph forest(n);
  int to, from;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &to, &from);
    to--, from--;
    forest[to].push_back(from);
    forest[from].push_back(to);
  }
  int nn;
  std::cin >> nn;
  Graph tree(nn);
  for (int i = 0; i < nn - 1; i++) {
    scanf("%d %d", &to, &from);
    to--, from--;
    tree[to].push_back(from);
    tree[from].push_back(to);
  }
  int ans = 0;
  vector<int> ct = CenterTree(tree);
  vector<int> th(ct.size());
  for (int i = 0; i < ct.size(); i++) {
    th[i] = AHUHash(tree, ct[i]);
  }
  vector<Graph> tree_set = ConectedComponent(forest);
  for (auto t: tree_set) {
    if(t.size() != nn)continue;
    vector<int> cf = CenterTree(t);
    vector<int> fh(cf.size());
    for (int j = 0; j < cf.size(); j++) {
      fh[j] = AHUHash(t, cf[j]);
    }
    for (int j = 0; j < th.size(); j++) {
      for (int k = 0; k < fh.size(); k++) {
        if(th[j] == fh[k])ans++, j = k = 1e9;
      }
    }
  }
  std::cout << ans << std::endl;
  return 0;
}