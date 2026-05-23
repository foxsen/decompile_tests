#include <bits/stdc++.h>
const int MAX_N = 5123;
const int inf = (int)1e9 + 123;
using namespace std;
int n, m;
vector<int> g[MAX_N], first[MAX_N];
vector<int> st;
bool u[MAX_N];
int cl[MAX_N];
vector<int> v[MAX_N], q[MAX_N];
void dfs(int v) {
  u[v] = 1;
  for (auto to : g[v])
    if (!u[to]) dfs(to);
  st.push_back(v);
}
void go(int now, int color) {
  cl[now] = color;
  v[color].push_back(now);
  for (auto to : first[now])
    if (!cl[to]) go(to, color);
}
int dist[MAX_N];
queue<int> Q;
int calc(int v) {
  int color = cl[v];
  Q.push(v);
  for (int i = 1; i <= n; i++) dist[i] = inf;
  dist[v] = 0;
  int res = inf;
  while (!Q.empty()) {
    int now = Q.front();
    for (auto to : g[now])
      if (to == v) res = min(res, dist[now] + 1);
    Q.pop();
    for (auto to : g[now])
      if (cl[to] == color && dist[to] > dist[now] + 1) {
        dist[to] = dist[now] + 1;
        Q.push(to);
      }
  }
  return res;
}
int bad, cycle;
int main() {
  ios_base ::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    first[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!u[i]) dfs(i);
  reverse(st.begin(), st.end());
  for (auto i : st)
    if (!cl[i]) go(i, i);
  for (int i = 1; i <= n; i++)
    for (auto to : g[i])
      if (cl[i] != cl[to]) q[cl[i]].push_back(cl[to]);
  for (int i = 1; i <= n; i++)
    if (q[i].empty() && !v[i].empty()) {
      int mini = inf;
      for (auto j : v[i]) mini = min(mini, calc(j));
      if (mini == inf) continue;
      bad += mini, cycle++;
    }
  cout << bad * 998 + cycle + n;
  return 0;
}
