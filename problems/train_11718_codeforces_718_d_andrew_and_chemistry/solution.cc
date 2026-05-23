#include <bits/stdc++.h>
using namespace std;
int n, m, tot;
vector<int> e[100005];
map<vector<int>, int> h;
map<int, int> f[100005];
set<int> s;
inline void addEdge(int u, int v) { e[u].push_back(v); }
inline int R() {
  char c;
  int res, sign = 1;
  while ((c = getchar()) > '9' || c < '0')
    if (c == '-') sign = -1;
  res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
  return res * sign;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int dfs(int u, int fa) {
  vector<int> rec;
  if (f[u][fa]) return f[u][fa];
  for (int v : e[u]) {
    if (v == fa) continue;
    rec.push_back(dfs(v, u));
  }
  sort(rec.begin(), rec.end());
  if (!h[rec]) h[rec] = ++tot;
  return f[u][fa] = h[rec];
}
int main() {
  n = R();
  for (int i = 1, u, v; i < n; i++)
    u = R(), v = R(), addEdge(u, v), addEdge(v, u);
  for (int i = 1; i <= n; i++)
    if (e[i].size() < 4) s.insert(dfs(i, 0));
  write(s.size());
}
