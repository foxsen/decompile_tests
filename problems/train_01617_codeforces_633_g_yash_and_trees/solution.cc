#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
const int maxM = 1e3 + 5;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long sq(long long x) { return (x * x) % MOD; }
long long modP(long long a, long long b) {
  return (!b ? 1 : (sq(modP(a, b / 2)) * (b % 2 ? a : 1)) % MOD);
}
int n, m, a[maxN], b[maxN];
int lazy[4 * maxN];
int st[maxN], fn[maxN], T;
vector<int> G[maxN];
bitset<maxM> prime, seg[4 * maxN], null;
void DFS(int v, int p = -1) {
  st[v] = T++;
  for (auto u : G[v]) {
    if (u == p) continue;
    DFS(u, v);
  }
  fn[v] = T;
  return;
}
void build(int id = 1, int s = 0, int e = n) {
  if (e - s <= 1) {
    seg[id].set(a[s] % m);
    return;
  }
  int md = (s + e) / 2;
  build(2 * id, s, md);
  build(2 * id + 1, md, e);
  seg[id] = seg[2 * id] | seg[2 * id + 1];
  return;
}
void apply(int id, int x) {
  seg[id] = (seg[id] << x) | (seg[id] >> (m - x));
  lazy[id] = (lazy[id] + x) % m;
  return;
}
void shift(int id) {
  if (lazy[id] == 0) return;
  apply(2 * id, lazy[id] % m);
  apply(2 * id + 1, lazy[id] % m);
  lazy[id] = 0;
  return;
}
void update(int l, int r, int x, int id = 1, int s = 0, int e = n) {
  if (l <= s && e <= r) {
    apply(id, x % m);
    return;
  }
  if (l >= e || s >= r) return;
  int md = (s + e) / 2;
  shift(id);
  update(l, r, x, 2 * id, s, md);
  update(l, r, x, 2 * id + 1, md, e);
  seg[id] = seg[2 * id] | seg[2 * id + 1];
  return;
}
bitset<maxM> get(int l, int r, int id = 1, int s = 0, int e = n) {
  if (l <= s && e <= r) return seg[id];
  if (l >= e || s >= r) return null;
  int md = (e + s) / 2;
  shift(id);
  return (get(l, r, 2 * id, s, md) | get(l, r, 2 * id + 1, md, e));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  prime.set();
  prime.set(0, 0);
  prime.set(1, 0);
  for (int i = 2; i < m; i++) {
    if (prime[i] == 1) {
      for (int j = 2 * i; j < m; j += i) {
        prime.set(j, 0);
      }
    }
  }
  for (int i = m; i < maxM; i++) prime.set(i, 0);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  DFS(0);
  for (int i = 0; i < n; i++) {
    a[st[i]] = b[i];
  }
  build();
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int v, x;
      cin >> v >> x;
      v--;
      update(st[v], fn[v], x);
    } else {
      int v;
      cin >> v;
      v--;
      cout << (prime & get(st[v], fn[v])).count() << "\n";
    }
  }
  return 0;
}
