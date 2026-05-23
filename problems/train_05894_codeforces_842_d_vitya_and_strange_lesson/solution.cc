#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 19) - 1;
const int MAXN = 600010;
int cnt[MAXN << 2];
int dig[20];
void update(int x, int l, int r, int rt) {
  if (l == r) {
    cnt[rt] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(x, l, mid, rt << 1);
  else
    update(x, mid + 1, r, rt << 1 | 1);
  cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
}
int query(int dep, int l, int r, int rt) {
  if (l == r) return 0;
  int mid = (l + r) >> 1;
  if (dig[dep]) {
    if (cnt[rt << 1 | 1] == r - mid)
      return query(dep - 1, l, mid, rt << 1) + (1 << dep);
    return query(dep - 1, mid + 1, r, rt << 1 | 1);
  } else {
    if (cnt[rt << 1] == mid - l + 1)
      return query(dep - 1, mid + 1, r, rt << 1 | 1) + (1 << dep);
    return query(dep - 1, l, mid, rt << 1);
  }
}
int main() {
  int n, m, t;
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%d", &t), update(t, 0, N, 1);
  while (m--) {
    scanf("%d", &t);
    for (int i = 0; i <= 18; i++)
      if (t & 1 << i) dig[i] ^= 1;
    printf("%d\n", query(18, 0, N, 1));
  }
  return 0;
}
