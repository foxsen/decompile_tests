#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10, modd = 1e9 + 7, inf = 0x3f3f3f3f, INF = 0x7fffffff,
          hmod1 = 0x48E2DCE7, hmod2 = 0x60000005;
const int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const double eps = 1e-8;
template <class T>
inline void sc(T &x) {
  char c;
  x = 0;
  while ((c = getchar()) < '0')
    ;
  while (c >= '0' && c <= '9') x = x * 10 + (c - 48), c = getchar();
}
inline long long min(long long a, long long b) { return a < b ? a : b; }
inline long long max(long long a, long long b) { return a > b ? a : b; }
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
inline long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d;
  (b == 0 ? (x = 1, y = 0, d = a)
          : (d = exgcd(b, a % b, y, x), y -= a / b * x));
  return d;
}
inline long long qpow(long long a, long long n) {
  long long sum = 1;
  while (n) {
    if (n & 1) sum = sum * a % modd;
    a = a * a % modd;
    n >>= 1;
  }
  return sum;
}
inline long long qmul(long long a, long long n) {
  long long sum = 0;
  while (n) {
    if (n & 1) sum = (sum + a) % modd;
    a = (a + a) % modd;
    n >>= 1;
  }
  return sum;
}
inline long long inv(long long a) { return qpow(a, modd - 2); }
inline long long madd(long long a, long long b) {
  return (a % modd + b % modd) % modd;
}
inline long long mmul(long long a, long long b) { return a % modd * b % modd; }
inline void uadd(long long &a, long long b) { a = madd(a, b); }
inline void umul(long long &a, long long b) { a = mmul(a, b); }
struct Edge {
  int to, next, id;
} edge[maxn];
int n, m, e, head[maxn], vis[maxn], cnt;
void add_edge(int u, int v, int id) {
  edge[++e].to = v;
  edge[e].next = head[u];
  edge[e].id = id;
  head[u] = e;
}
void dfs1(int pos) {
  vis[pos] = 1, cnt++;
  for (int i = head[pos]; i; i = edge[i].next) {
    if (vis[edge[i].to - n]) continue;
    dfs1(edge[i].to - n);
  }
}
void dfs2(int pos) {
  vis[pos - n] = 1, cnt++;
  for (int i = head[pos]; i; i = edge[i].next) {
    if (vis[edge[i].to]) continue;
    dfs2(edge[i].to + n);
  }
}
void print(int t) {
  if (!t) {
    cout << "No" << endl;
    return;
  }
  cout << "Yes" << endl;
  if (t == 1) {
    cout << cnt << ' ' << n - cnt << endl;
    for (int i = 1; i <= n; i++)
      if (vis[i]) cout << i << ' ';
    cout << endl;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) cout << i << ' ';
    cout << endl;
  }
  if (t == 2) {
    cout << n - cnt << ' ' << cnt << endl;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) cout << i << ' ';
    cout << endl;
    for (int i = 1; i <= n; i++)
      if (vis[i]) cout << i << ' ';
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int kase, a, b;
  cin >> kase;
  while (kase--) {
    e = 0;
    cin >> n >> m;
    for (int i = 0; i <= 2 * n; i++) vis[i] = head[i] = 0;
    while (m--) {
      cin >> a >> b;
      add_edge(a, b + n, a);
      add_edge(b + n, a, a);
    }
    cnt = 0;
    for (int i = 0; i <= n; i++) vis[i] = 0;
    dfs1(1);
    if (cnt != n) {
      print(1);
      continue;
    }
    cnt = 0;
    for (int i = 0; i <= n; i++) vis[i] = 0;
    dfs2(n + 1);
    if (cnt != n) {
      print(2);
      continue;
    }
    print(0);
  }
}
