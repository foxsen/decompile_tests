#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int N = 500005;
const double EPS = 1e-9;
int n, m, arr[N], u, v;
char c;
vector<int> adj[N];
vector<pair<int, int> > pre[N];
int s[N], d[N];
int ndfn;
void godfs(int cur = 0, int depth = 0) {
  s[cur] = ndfn++;
  pre[depth].push_back(
      pair<int, int>(s[cur], pre[depth].back().second ^ (1 << arr[cur])));
  for (auto ver : adj[cur]) godfs(ver, depth + 1);
  d[cur] = ndfn;
}
int solve(int test) {
  scanf("%d%d", &n, &m);
  for (register int i = 0; i < n - 1; i++)
    scanf("%d", &u), adj[u - 1].push_back(i + 1);
  for (register int i = 0; i < n; i++) scanf(" %c", &c), arr[i] = c - 'a';
  for (register int i = 0; i < n; i++) pre[i].push_back(pair<int, int>(-1, 0));
  godfs();
  while (m--) {
    scanf("%d%d", &u, &v);
    u--, v--;
    int r = lower_bound(pre[v].begin(), pre[v].end(), pair<int, int>(d[u], 0)) -
            pre[v].begin() - 1;
    int l = lower_bound(pre[v].begin(), pre[v].end(), pair<int, int>(s[u], 0)) -
            pre[v].begin();
    if (l == r && l == 0) {
      puts("Yes");
      continue;
    }
    int sum = pre[v][r].second ^ pre[v][l - 1].second;
    int out = 0;
    while (sum) out += sum & 1, sum = sum >> 1;
    puts(out > 1 ? "No" : "Yes");
  }
  return test;
}
int32_t main() {
  int t = 1;
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
