#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};
const int drr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dcc[8] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int i = 0; i < ((int)((t).size())); i++) s << t[i] << " ";
  return s;
}
class UnionFind {
 private:
  vector<int> rank, p;

 public:
  UnionFind(int n) {
    for (int i = 0; i < n; i++) p.push_back(i);
    rank.assign(n, 0);
  }
  int findSet(int s) { return (p[s] == s) ? s : (p[s] = findSet(p[s])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      p[y] = x;
    else {
      p[x] = y;
      if (rank[x] == rank[y]) rank[y]++;
    }
  }
};
bool fcomp(double A, double B) {
  double EPSILON = numeric_limits<double>::epsilon();
  double diff = A - B;
  return fabs(diff) < EPSILON;
}
double x_y(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int vis[300000], ct, n, m, res, ys = 1;
vector<vector<pair<int, int> > > adj;
void dfs(int id, int f) {
  vis[id] = f;
  ct++;
  for (auto v : adj[id]) {
    if (vis[v.first] != -1) {
      int ck = v.second;
      if (!f) ck = v.second ^ 1;
      if (vis[v.first] != ck) ys = 0;
      continue;
    }
    if (f)
      dfs(v.first, v.second);
    else
      dfs(v.first, v.second ^ 1);
  }
  res += f ^ 1;
}
int main() {
  int(testow);
  scanf("%d", &(testow));
  while (testow--) {
    scanf("%d%d", &n, &m);
    adj.assign(n + 1, {});
    ys = 1;
    for (int i = 0; i < m; i++) {
      int(i1), (i2);
      scanf("%d %d", &(i1), &(i2));
      string s;
      cin >> s;
      if (s[0] == 'i') {
        adj[i1].push_back({i2, 0});
        adj[i2].push_back({i1, 0});
      } else {
        adj[i1].push_back({i2, 1});
        adj[i2].push_back({i1, 1});
      }
    }
    for (int i = 1; i <= n; i++) vis[i] = -1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[i] != -1) continue;
      ct = 0, res = 0;
      dfs(i, 1);
      ans += (res < ct - res ? ct - res : res);
    }
    if (!ys) {
      cout << -1 << endl;
      continue;
    }
    cout << ans << endl;
  }
  return 0;
}
