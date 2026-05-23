#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
T gcd(T x, T y) {
  for (T t; x; t = x, x = y % x, y = t)
    ;
  return y;
}
template <class edge>
struct Graph {
  vector<vector<edge> > adj;
  Graph(int n) {
    adj.clear();
    adj.resize(n + 5);
  }
  Graph() { adj.clear(); }
  void resize(int n) { adj.resize(n + 5); }
  void add(int s, edge e) { adj[s].push_back(e); }
  void del(int s, edge e) { adj[s].erase(find(iter(adj[s]), e)); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
const int maxn = 40;
int n, x;
int ans = -0x3F3F3F3F;
int w[maxn][maxn], v[maxn][maxn], f[maxn][maxn];
int calc(int i, int j, int xj) {
  return abs(w[i][j] + w[i][j + x] * f[i][x] + w[i + x][j] * xj +
             w[i + x][j + x] * f[i][x] * xj * f[x][x]);
}
void update() {
  int ret = w[x][x] * f[x][x];
  for (int _end_ = (x - 1), i = (1); i <= _end_; ++i) {
    ret += f[i][x] * f[x][x] * w[i + x][x] + f[i][x] * w[i][x];
  }
  for (int _end_ = (x - 1), j = (1); j <= _end_; ++j) {
    int a = w[x][j] + f[x][x] * w[x][j + x],
        b = -w[x][j] - f[x][x] * w[x][j + x];
    for (int _end_ = (x - 1), i = (1); i <= _end_; ++i) {
      a += calc(i, j, +1);
      b += calc(i, j, -1);
    }
    ret += max(a, b);
  }
  chkmax(ans, ret);
}
void dfs(int d) {
  if (d > x) {
    return update();
  }
  f[d][x] = +1, dfs(d + 1);
  f[d][x] = -1, dfs(d + 1);
}
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin >> n, x = (n + 1) / 2;
  for (int _end_ = (n), i = (1); i <= _end_; ++i) {
    for (int _end_ = (n), j = (1); j <= _end_; ++j) {
      cin >> w[i][j];
    }
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}
