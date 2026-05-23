#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, next;
} e[1000005];
int head[1000005], dep[1000005], fa[1000005];
int top[1000005], sz[1000005], pos[1000005];
long long ans[1000005], s1[1000005], s2[1000005];
vector<int> v[1000005];
int tot, rt, n, T;
void adde(int x, int y) {
  e[++tot] = (edge){y, head[x]};
  head[x] = tot;
}
void dfs(int x) {
  v[dep[x]].push_back(x);
  sz[x] = 1;
  for (int i = head[x]; i; i = e[i].next) {
    fa[e[i].to] = x;
    dep[e[i].to] = dep[x] + 1;
    dfs(e[i].to);
    sz[x] += sz[e[i].to];
  }
}
void dfs2(int x, int tp) {
  pos[x] = ++T;
  top[x] = tp;
  int k = 0;
  for (int i = head[x]; i; i = e[i].next)
    if (sz[e[i].to] > sz[k]) k = e[i].to;
  if (k) dfs2(k, tp);
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != k) dfs2(e[i].to, e[i].to);
}
void add(int x, int v) {
  for (int k = x; x <= n; x += x & (-x)) s1[x] += v, s2[x] += k * v;
}
long long sum(int x) {
  long long ans = 0;
  for (int k = x; k; k -= k & (-k)) ans += s1[k];
  ans *= (x + 1);
  for (int k = x; k; k -= k & (-k)) ans -= s2[k];
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x)
      adde(x, i);
    else
      rt = i;
  }
  dep[rt] = 1;
  dfs(rt);
  dfs2(rt, rt);
  for (int i = 2; i <= n; i++) {
    vector<int>::iterator it;
    for (it = v[i].begin(); it != v[i].end(); it++)
      for (int k = fa[*it]; k; k = fa[top[k]])
        add(pos[top[k]], 1), add(pos[k] + 1, -1);
    for (it = v[i].begin(); it != v[i].end(); it++)
      for (int k = fa[*it]; k; k = fa[top[k]])
        ans[*it] += sum(pos[k]) - sum(pos[top[k]] - 1);
  }
  for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
}
