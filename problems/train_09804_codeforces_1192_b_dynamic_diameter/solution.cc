#include <bits/stdc++.h>
using namespace std;
inline void read(int &first) {
  register int c = getchar();
  first = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    first = (first << 1) + (first << 3) + c - 48;
  }
  if (neg) first = -first;
}
inline void read(long long &first) {
  register int c = getchar();
  first = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    first = (first << 1) + (first << 3) + c - 48;
  }
  if (neg) first = -first;
}
inline void writeln(long long first) {
  char buffor[21];
  register int i = 0;
  int neg = 0;
  if (first < 0) {
    neg = 1;
    first = -first;
  }
  do {
    buffor[i++] = (first % 10) + '0';
    first /= 10;
  } while (first);
  i--;
  if (neg) putchar('-');
  while (i >= 0) putchar(buffor[i--]);
  putchar('\n');
}
inline void write(long long first) {
  char buffor[21];
  register int i = 0;
  int neg = 0;
  if (first < 0) {
    neg = 1;
    first = -first;
  }
  do {
    buffor[i++] = (first % 10) + '0';
    first /= 10;
  } while (first);
  i--;
  if (neg) putchar('-');
  while (i >= 0) putchar(buffor[i--]);
  putchar(' ');
}
const int N = 2e5 + 7;
const long long oo = (long long)1e18 + 7;
int n, q, Time;
int st[N], ft[N], h[N];
long long W;
long long depthAt[N];
vector<pair<int, long long> > adj[N];
struct node {
  long long mn, mx;
  long long pre, suf;
  long long tot;
};
const node nullNode = {0, 0, 0, 0, 0};
struct segTree {
  node tree[4 * N];
  long long lazy[4 * N];
  node merge(node a, node b) {
    node res;
    res.mn = min(a.mn, b.mn);
    res.mx = max(a.mx, b.mx);
    res.pre = max(max(a.pre, b.pre), a.mx - 2 * b.mn);
    res.suf = max(max(a.suf, b.suf), b.mx - 2 * a.mn);
    res.tot = max(max(a.tot, b.tot), max(a.pre + b.mx, a.mx + b.suf));
    return res;
  }
  void Build(int first, int low, int high) {
    if (low == high) {
      long long val = depthAt[low];
      tree[first] = {val, val, -val, -val, 0};
    } else {
      int mid = low + high >> 1;
      Build(2 * first, low, mid);
      Build(2 * first + 1, mid + 1, high);
      tree[first] = merge(tree[2 * first], tree[2 * first + 1]);
    }
  }
  void Lazy(int first, bool isLeaf) {
    tree[first].mn += lazy[first];
    tree[first].mx += lazy[first];
    tree[first].pre -= lazy[first];
    tree[first].suf -= lazy[first];
    if (!isLeaf) {
      lazy[2 * first] += lazy[first];
      lazy[2 * first + 1] += lazy[first];
    }
    lazy[first] = 0;
  }
  void Update(int first, int l, int r, int i, int j, long long val) {
    Lazy(first, (l == r));
    if (l > j || r < i) return;
    if (l >= i && r <= j) {
      tree[first].mn += val;
      tree[first].mx += val;
      tree[first].pre -= val;
      tree[first].suf -= val;
      if (l != r) {
        lazy[2 * first] += val;
        lazy[2 * first + 1] += val;
      }
      return;
    }
    int mid = l + r >> 1;
    Update(2 * first, l, mid, i, j, val);
    Update(2 * first + 1, mid + 1, r, i, j, val);
    tree[first] = merge(tree[2 * first], tree[2 * first + 1]);
  }
} IT;
struct edge {
  int u, v;
  long long w;
  edge() {}
  edge(int u, int v, long long w) : u(u), v(v), w(w) {}
} e[N];
void dfs(int u, long long curDepth) {
  depthAt[++Time] = curDepth;
  st[u] = Time;
  for (auto nxt : adj[u]) {
    int v = nxt.first;
    long long w = nxt.second;
    if (!st[v]) {
      h[v] = h[u] + 1;
      dfs(v, curDepth + w);
      depthAt[++Time] = curDepth;
    }
    ft[u] = Time;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  if (fopen("test.inp", "r"))
    freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
  read(n);
  read(q);
  read(W);
  for (int i = 1; i < n; i++) {
    int u, v;
    long long w;
    read(u);
    read(v);
    read(w);
    adj[u].push_back(pair<int, long long>(v, w));
    adj[v].push_back(pair<int, long long>(u, w));
    e[i] = {u, v, w};
  }
  h[1] = 1;
  dfs(1, 0);
  for (int i = 1; i < n; i++)
    if (h[e[i].u] > h[e[i].v]) swap(e[i].u, e[i].v);
  long long last = 0;
  IT.Build(1, 1, Time);
  for (int i = 1; i <= q; i++) {
    int id;
    long long w;
    read(id);
    read(w);
    id = (id + last) % (n - 1) + 1;
    w = (w + last) % W;
    int u = e[id].v;
    long long delta = w - e[id].w;
    IT.Update(1, 1, Time, st[u], ft[u], delta);
    IT.Lazy(1, 0);
    last = IT.tree[1].tot;
    e[id].w = w;
    writeln(last);
  }
}
