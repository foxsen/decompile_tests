#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)4e5;
struct state {
  int next[37], len, suff;
  state() {
    memset(next, -1, sizeof(next));
    suff = -1;
    len = 0;
  }
} st[2 * maxn];
int sz = 1, last = 0;
vector<int> g[maxn];
char second[maxn];
int L[maxn], R[maxn], n;
int dp[maxn * 3][11], cnt[maxn * 2], was[maxn * 2];
long long ans;
void addAutomat(int ch) {
  int p = last;
  int nv = sz++;
  st[nv].len = st[last].len + 1;
  memset(st[nv].next, -1, sizeof(st[nv].next));
  for (; p != -1 && st[p].next[ch] == -1; p = st[p].suff) st[p].next[ch] = nv;
  if (p == -1)
    st[nv].suff = 0;
  else {
    int q = st[p].next[ch];
    if (st[q].len == st[p].len + 1)
      st[nv].suff = q;
    else {
      int clone = sz++;
      memcpy(st[clone].next, st[q].next, sizeof(st[clone].next));
      st[clone].suff = st[q].suff;
      st[clone].len = st[p].len + 1;
      for (; p != -1 && st[p].next[ch] == q; p = st[p].suff)
        st[p].next[ch] = clone;
      st[nv].suff = st[q].suff = clone;
    }
  }
  last = nv;
}
int Count(int v) {
  if (v == 0) return 1;
  if (cnt[v] != -1) return cnt[v];
  cnt[v] = 0;
  for (typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); ++it) {
    int to = *it;
    cnt[v] += Count(to);
  }
  return cnt[v];
}
void Dfs(int v) {
  if (was[v]) return;
  was[v] = true;
  for (int i = 0; i <= n; ++i)
    if (st[v].next[26 + i] != -1) {
      dp[v][i] = 1;
    }
  for (int i = 0; i < 26; ++i)
    if (st[v].next[i] != -1) {
      int u = st[v].next[i];
      Dfs(u);
      for (int j = 0; j <= n; ++j) dp[v][j] += dp[u][j];
    }
  if (v && dp[v][0]) {
    bool ok = true;
    for (int i = 1; ok && i <= n; ++i)
      if (!(L[i] <= dp[v][i] && dp[v][i] <= R[i])) ok = false;
    if (ok) {
      ans += Count(v);
    }
  }
}
int main() {
  scanf("%s", second);
  for (int i = 0; second[i]; ++i) addAutomat(second[i] - 'a');
  addAutomat(26);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("\n%s %d %d", &second, &L[i], &R[i]);
    for (int j = 0; second[j]; ++j) addAutomat(second[j] - 'a');
    addAutomat(i + 26);
  }
  for (int i = 0; i < sz; ++i) {
    for (int ch = 0; ch < 26; ++ch)
      if (st[i].next[ch] != -1) {
        g[st[i].next[ch]].push_back(i);
      }
  }
  memset(cnt, -1, sizeof(cnt));
  Dfs(0);
  cout << ans << endl;
  return 0;
}
