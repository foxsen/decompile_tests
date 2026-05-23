#include <bits/stdc++.h>
inline long long read() {
  long long x = 0;
  char ch = getchar(), w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * w;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
using namespace std;
int n;
const int N = 420000 * 2;
struct Edge {
  int u, v, nxt;
} e[N];
int head[N], en;
void addl(int x, int y) {
  e[++en].u = x, e[en].v = y, e[en].nxt = head[x], head[x] = en;
}
bool ans[N];
int siz[N], rt, res = 1e9;
void dfs(int x, int F) {
  siz[x] = 1;
  int mx = 0;
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].v;
    if (y == F) continue;
    dfs(y, x);
    siz[x] += siz[y];
    mx = max(mx, siz[y]);
  }
  mx = max(mx, n - siz[x]);
  if (mx < res) {
    res = mx;
    rt = x;
  }
}
vector<pair<int, int> > sub;
void solve(int x, int F, int sum, int pre) {
  if (sum <= n / 2) ans[x] = 1;
  for (int i = 0; i < 2 && i < sub.size(); ++i) {
    if (sub[i].second == pre) continue;
    if (n - siz[x] - sub[i].first <= n / 2) ans[x] = 1;
  }
  for (int i = head[x]; i; i = e[i].nxt) {
    int y = e[i].v;
    if (y == F) continue;
    solve(y, x, sum, pre);
  }
}
int main() {
  n = read();
  for (int i = 1; i < n; ++i) {
    int x = read(), y = read();
    addl(x, y);
    addl(y, x);
  }
  dfs(1, 0);
  dfs(rt, 0);
  ans[rt] = 1;
  for (int i = head[rt]; i; i = e[i].nxt)
    sub.push_back(make_pair(siz[e[i].v], e[i].v));
  sort(sub.begin(), sub.end(), greater<pair<int, int> >());
  for (int i = head[rt]; i; i = e[i].nxt) {
    int to = e[i].v;
    solve(to, rt, n - siz[to], to);
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
