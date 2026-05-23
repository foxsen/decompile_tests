#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e7 + 10;
const int Mod = 1e9 + 7;
const int P = 1e7 + 10;
map<int, int> mp;
int cntmp = 0, maxv = 0, pri = 0;
int prime[P], minp[P];
bool vis[P];
void get_prime() {
  minp[1] = 1;
  for (int i = 2; i < P; i++) {
    if (!vis[i]) {
      prime[++pri] = i;
      minp[i] = i;
    }
    for (int j = 1; j <= pri; j++) {
      if (prime[j] * i >= P) break;
      minp[prime[j] * i] = min(prime[j], minp[i]);
      vis[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
struct Edge {
  int v, nxt;
} E[N << 1];
int n, m, head[N], tot = 0;
int fa[N][17], dep[N], a[N];
void add(int u, int v) {
  E[++tot] = (Edge){v, head[u]};
  head[u] = tot;
}
void dfs_lca(int u, int father) {
  dep[u] = dep[father] + 1;
  fa[u][0] = father;
  for (int i = 1; i < 17; i++) {
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
  }
  for (int i = head[u]; i; i = E[i].nxt) {
    int v = E[i].v;
    if (v == father) continue;
    dfs_lca(v, u);
  }
}
int cal_lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int delta = dep[x] - dep[y];
  for (int i = 0; i < 17; i++)
    if ((delta >> i) & 1) x = fa[x][i];
  if (x == y) return x;
  for (int k = 16; k >= 0; k--) {
    if (fa[x][k] != fa[y][k]) {
      x = fa[x][k];
      y = fa[y][k];
    }
  }
  return fa[x][0];
}
struct Node {
  int id, val;
  bool typ;
  Node(int id = 0, int val = 0, bool typ = 0) : id(id), val(val), typ(typ) {}
};
int cnt[P], ans[N];
vector<Node> chg[N];
int mul(int a, int b) { return 1ll * a * b % Mod; }
int fast_pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    b >>= 1;
    a = mul(a, a);
  }
  return res;
}
void modify(int pos, int val) {
  int now = a[pos];
  while (now != 1) {
    int tmp = minp[now], vl = 1;
    while (now % tmp == 0) {
      now /= tmp;
      cnt[vl *= tmp] += val;
    }
  }
}
int calc(int pos, int now) {
  int res = 1;
  while (now != 1) {
    int tmp = minp[now], vl = 1, sum = 0;
    while (now % tmp == 0) {
      now /= tmp;
      sum += cnt[vl *= tmp];
    }
    res = mul(res, fast_pow(tmp, sum));
  }
  return res;
}
void dfs(int u) {
  modify(u, 1);
  for (auto cur : chg[u]) {
    if (cur.typ) {
      ans[cur.id] = mul(ans[cur.id], calc(u, cur.val));
    } else {
      ans[cur.id] = mul(ans[cur.id], fast_pow(calc(u, cur.val), Mod - 2));
    }
  }
  for (int i = head[u]; i; i = E[i].nxt) {
    if (E[i].v == fa[u][0]) continue;
    dfs(E[i].v);
  }
  modify(u, -1);
}
int main() {
  get_prime();
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    add(u, v);
    add(v, u);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  dfs_lca(1, 0);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int x, y, val;
    scanf("%d %d %d", &x, &y, &val);
    int f = cal_lca(x, y), g = fa[f][0];
    chg[x].push_back(Node(i, val, 1));
    chg[y].push_back(Node(i, val, 1));
    chg[f].push_back(Node(i, val, 0));
    chg[g].push_back(Node(i, val, 0));
    ans[i] = 1;
  }
  dfs(1);
  for (int i = 1; i <= m; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
