#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
  return os << "(" << x.first << "," << x.second << ")";
}
namespace tree {
struct Edge {};
int n;
vector<Edge> edges;
vector<vector<pair<int, int>>> adj;
void makeTree(int _n) {
  n = _n;
  adj = vector<vector<pair<int, int>>>(n + 1);
  edges.clear();
}
template <typename... T>
int addEdge(int from, int to, const T&... e) {
  int id = edges.size();
  adj[from].emplace_back(to, id);
  adj[to].emplace_back(from, id);
  edges.push_back({e...});
  return id;
}
vector<int> depth, pv, pe, pre, endpre, preseq, siz;
int logn;
vector<vector<int>> anc;
struct Jump {
  int sum;
  void init(int v) {
    Edge& e = edges[pe[v]];
    sum = 1;
  }
  void combine(const Jump& x, const Jump& a) { sum = x.sum + a.sum; }
};
vector<vector<Jump>> jump;
void dfs(int x, int p = -1) {
  siz[x] = 1;
  pre[x] = preseq.size();
  preseq.push_back(x);
  for (auto& e : adj[x]) {
    int y = e.first, eid = e.second;
    if (y == p) continue;
    depth[y] = depth[x] + 1;
    pv[y] = x;
    pe[y] = eid;
    dfs(y, x);
    siz[x] += siz[y];
  }
  endpre[x] = (int)preseq.size() - 1;
}
void init(int root = 1) {
  siz = vector<int>(n + 1);
  depth = vector<int>(n + 1);
  pv = vector<int>(n + 1, -1);
  pe = vector<int>(n + 1, -1);
  pre = vector<int>(n + 1, -1);
  endpre = vector<int>(n + 1, -1);
  preseq.clear();
  dfs(root);
  logn = 31 - __builtin_clz(n);
  anc = vector<vector<int>>(n + 1, vector<int>(logn + 1));
  for (int i = 1; i <= n; ++i) anc[i][0] = pv[i];
  for (int p = 1; p <= logn; ++p)
    for (int i = 1; i <= n; ++i)
      anc[i][p] = anc[i][p - 1] == -1 ? -1 : anc[anc[i][p - 1]][p - 1];
}
bool isAnc(int a, int b) { return pre[a] <= pre[b] && endpre[a] >= endpre[b]; }
int getChildTowards(int a, int sub) {
  int dh = depth[sub] - depth[a] - 1;
  for (int p = logn; p >= 0; --p)
    if (dh & (1 << p)) sub = anc[sub][p];
  return sub;
}
int getLca(int a, int b) {
  if (isAnc(a, b)) return a;
  if (isAnc(b, a)) return b;
  for (int p = logn; p >= 0; --p)
    if (anc[a][p] != -1 && !isAnc(anc[a][p], b)) a = anc[a][p];
  a = anc[a][0];
  return a;
}
void jumpUp(int a, int ancestor, function<void(Jump&)> f) {
  assert(isAnc(ancestor, a));
  int up = depth[a] - depth[ancestor];
  for (int p = logn; p >= 0; --p)
    if (up & (1 << p)) {
      f(jump[a][p]);
      a = anc[a][p];
    }
}
vector<int> chainRoot, chainBottom;
void dfsSiz(int x, int p = -1) {
  for (auto it = adj[x].begin(); it != adj[x].end(); ++it)
    if (it->first == p) {
      adj[x].erase(it);
      break;
    }
  siz[x] = 1;
  for (auto& e : adj[x]) {
    int y = e.first;
    dfsSiz(y, x);
    siz[x] += siz[y];
    if (siz[y] > siz[adj[x][0].first]) swap(e, adj[x][0]);
  }
}
void dfsHld(int x, int hldroot) {
  chainRoot[x] = hldroot;
  chainBottom[hldroot] = x;
  for (auto& e : adj[x]) {
    int y = e.first;
    dfsHld(y, y == adj[x][0].first ? hldroot : y);
  }
}
struct Chain {
  vector<int> vs;
  void init(int bot, int top) {
    vs.clear();
    for (int x = bot; x != pv[top]; x = pv[x]) vs.push_back(x);
  }
};
vector<Chain> chains;
void moveUp(int x, int y, function<void(Chain&, int, int)> f) {
  for (;;) {
    int z = chainRoot[x];
    bool isLastChain = z == chainRoot[y];
    f(chains[chainRoot[x]], x, isLastChain ? y : z);
    if (isLastChain) break;
    x = pv[z];
  }
}
void initHld(int root = 1) {
  siz = vector<int>(n + 1);
  dfsSiz(root);
  init(root);
  chainRoot = vector<int>(n + 1);
  chainBottom = vector<int>(n + 1);
  dfsHld(root, root);
  chains = vector<Chain>(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (chainRoot[i] != i) continue;
    chains[i].init(chainBottom[i], i);
  }
}
};  // namespace tree
using namespace tree;
const int MAXN = 100005;
vector<int> ds[MAXN], E[MAXN];
void go(int x, int p = -1) {
  ds[x].clear();
  for (int y : E[x]) {
    if (y == p) continue;
    go(y, x);
    ds[x].push_back(ds[y][0] + 1);
  }
  sort(ds[x].begin(), ds[x].end(), greater<int>());
  ds[x].resize(3);
  if (false)
    cerr << "x"
         << "=" << x << endl;
}
void go2(int x, int p = -1, int pd = 0) {
  ds[x].push_back(pd);
  sort(ds[x].begin(), ds[x].end(), greater<int>());
  ds[x].resize(3);
  for (int y : E[x]) {
    if (y == p) continue;
    int npd = ds[x][0] + 1;
    if (ds[y][0] + 1 == ds[x][0]) npd = ds[x][1] + 1;
    go2(y, x, npd);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    makeTree(n);
    for (int i = 1; i <= n; ++i) E[i].clear();
    for (int i = 1; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      addEdge(a, b);
      E[a].push_back(b);
      E[b].push_back(a);
    }
    init(a);
    go(a);
    vector<int> vec, path;
    for (int i = b;; i = pv[i]) {
      int d = ds[i][0];
      if (i != b) {
        int j = getChildTowards(i, b);
        if (ds[j][0] + 1 == d) d = ds[i][1];
      }
      path.push_back(i);
      vec.push_back(d);
      if (i == a) break;
    }
    go2(a);
    int len = vec.size();
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    Q.push({len - 1, 1});
    int l = 0, r = len - 1;
    while (!Q.empty() && l + 1 < r) {
      auto p = Q.front();
      Q.pop();
      int x = p.first, side = p.second;
      if (side == 0) {
        int r2 = max(0, len - 1 - vec[x] + x);
        while (r2 < r) {
          --r;
          Q.push({r, 1});
        }
      } else {
        int l2 = min(len - 1, x - (len - 1 - vec[x]));
        while (l2 > l) {
          ++l;
          Q.push({l, 0});
        }
      }
    }
    vector<bool> ok(n + 1);
    for (int i = 0; i < path.size(); ++i)
      if (i <= l || i >= r) ok[path[i]] = true;
    auto f = [&]() {
      int d = depth[b];
      assert(len == d + 1);
      if (false)
        cerr << "d"
             << "=" << d << endl;
      for (int i = 1; i <= n; ++i) {
        if (ds[i][0] >= d && ds[i][1] >= d && ds[i][2] >= d) {
          if (false)
            cerr << "i"
                 << "=" << i << endl;
          int mid = getLca(b, i);
          if (false)
            cerr << "mid"
                 << "=" << mid << endl;
          if (ok[mid]) return true;
        }
      }
      return false;
    };
    if (f())
      printf("YES\n");
    else
      printf("NO\n");
  }
}
