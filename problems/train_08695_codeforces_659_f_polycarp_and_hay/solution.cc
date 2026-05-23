#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:536870912")
const int MOD = 1000000007;
const int INF = 1000000001;
const int MAXN = 100010;
const long double EPS = 1e-6;
const int HASH_POW = 29;
const long double PI = acos(-1.0);
using namespace std;
void my_return(int code) { exit(code); }
int n, m, p[1010][1010], ans[1010][1010];
bool u[1010][1010];
long long goal;
int ord[1000010];
bool cmp(int a, int b) { return p[a / m][a % m] > p[b / m][b % m]; }
int par[1000010], sz[1000010];
int find_parent(int v) {
  if (par[v] == v) return v;
  return par[v] = find_parent(par[v]);
}
void union_sets(int u, int v) {
  u = find_parent(u);
  v = find_parent(v);
  if (u == v) return;
  if (sz[u] < sz[v]) swap(u, v);
  par[v] = u;
  sz[u] += sz[v];
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  mt19937 mt_rand(time(0));
  scanf("%d %d %I64d", &n, &m, &goal);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &p[i][j]);
  for (int i = 0; i < n * m; ++i) ord[i] = i;
  sort(ord, ord + n * m, cmp);
  int val = -1, initx = -1, inity = -1;
  for (int i = 0; i < n * m; ++i) {
    par[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < n * m; ++i) {
    int x = ord[i] / m, y = ord[i] % m;
    if (x > 0 && p[x - 1][y] >= p[x][y]) union_sets((x - 1) * m + y, ord[i]);
    if (x < n - 1 && p[x + 1][y] >= p[x][y])
      union_sets((x + 1) * m + y, ord[i]);
    if (y > 0 && p[x][y - 1] >= p[x][y]) union_sets(x * m + y - 1, ord[i]);
    if (y < m - 1 && p[x][y + 1] >= p[x][y]) union_sets(x * m + y + 1, ord[i]);
    if (goal % p[x][y] == 0) {
      if (sz[find_parent(ord[i])] >= goal / p[x][y]) {
        val = p[x][y];
        initx = x;
        inity = y;
      }
    }
  }
  if (val == -1) {
    printf("NO\n");
    my_return(0);
  }
  queue<pair<int, int> > Q;
  Q.push(make_pair(initx, inity));
  u[initx][inity] = true;
  int cnt = goal / val;
  while (cnt > 0) {
    int x = Q.front().first, y = Q.front().second;
    ans[x][y] = val;
    --cnt;
    Q.pop();
    if (x > 0 && !u[x - 1][y] && p[x - 1][y] >= val) {
      Q.push(make_pair(x - 1, y));
      u[x - 1][y] = true;
    }
    if (x < n - 1 && !u[x + 1][y] && p[x + 1][y] >= val) {
      Q.push(make_pair(x + 1, y));
      u[x + 1][y] = true;
    }
    if (y > 0 && !u[x][y - 1] && p[x][y - 1] >= val) {
      Q.push(make_pair(x, y - 1));
      u[x][y - 1] = true;
    }
    if (y < m - 1 && !u[x][y + 1] && p[x][y + 1] >= val) {
      Q.push(make_pair(x, y + 1));
      u[x][y + 1] = true;
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) printf("%d ", ans[i][j]);
    printf("\n");
  }
  my_return(0);
}
