#include <bits/stdc++.h>
using namespace std;
const int N = 40005;
const int mod = 1e9 + 7;
const int bs = 1e7 + 19;
pair<int, int> a[N];
int n, st[N], ed[N], p[N], dp[1005];
int k, tot = n, q;
vector<int> t[N << 2];
bool vis[N];
void modify(int x, int l, int r, int L, int R, int id) {
  if (L <= l && r <= R) {
    t[x].push_back(id);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) modify(x << 1, l, mid, L, R, id);
  if (R > mid) modify(x << 1 | 1, mid + 1, r, L, R, id);
  return;
}
void solve(int l, int r, int id) {
  int ls[1005] = {0};
  for (int i = 0; i < (int)t[id].size(); ++i) {
    int v = t[id][i];
    for (int j = k; j >= 0; --j) {
      int now = j + a[v].second;
      if (now <= k) dp[now] = max(dp[now], dp[j] + a[v].first);
    }
  }
  if (l == r) {
    if (vis[l]) {
      int ans = 0;
      for (int i = 1; i <= k; ++i) {
        ans = (ans + 1ll * dp[i] * p[i - 1] % mod) % mod;
      }
      printf("%d\n", ans);
    }
    return;
  }
  int mid = (l + r) >> 1;
  memcpy(ls, dp, sizeof(dp));
  solve(l, mid, id << 1);
  memcpy(dp, ls, sizeof(dp));
  solve(mid + 1, r, id << 1 | 1);
  return;
}
int main() {
  p[0] = 1;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= 1005; ++i) p[i] = 1ll * p[i - 1] * bs % mod;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
    st[i] = 1;
  }
  scanf("%d", &q);
  tot = n;
  for (int i = 1; i <= q; ++i) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      ++tot;
      scanf("%d%d", &a[tot].first, &a[tot].second);
      st[tot] = i;
    } else if (opt == 2) {
      int x;
      scanf("%d", &x);
      ed[x] = i;
    } else {
      vis[i] = 1;
    }
  }
  for (int i = 1; i <= tot; ++i)
    if (!ed[i]) ed[i] = q;
  for (int i = 1; i <= tot; ++i) modify(1, 1, q, st[i], ed[i], i);
  solve(1, q, 1);
  return 0;
}
