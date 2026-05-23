#include <bits/stdc++.h>
using namespace std;
int ma[200010 << 2];
void build() { memset(ma, 0, sizeof(ma)); }
void update(int u, int l, int r, int pos, int val) {
  if (l == r) {
    ma[u] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid)
    update(u << 1, l, mid, pos, val);
  else
    update(u << 1 | 1, mid + 1, r, pos, val);
  ma[u] = max(ma[u << 1], ma[u << 1 | 1]);
}
int query(int u, int l, int r, int L, int R) {
  if (l == L && r == R) return ma[u];
  int mid = (l + r) / 2;
  if (R <= mid)
    return query(u << 1, l, mid, L, R);
  else if (L > mid)
    return query(u << 1 | 1, mid + 1, r, L, R);
  else
    return max(query(u << 1, l, mid, L, mid),
               query(u << 1 | 1, mid + 1, r, mid + 1, R));
}
int a[200010];
int main() {
  int n, t, c;
  while (~scanf("%d%d%d", &n, &t, &c)) {
    build();
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) update(1, 1, n, i, a[i]);
    int ans = 0;
    for (int i = c; i <= n; ++i)
      if (query(1, 1, n, i - c + 1, i) <= t) ++ans;
    printf("%d\n", ans);
  }
  return 0;
}
