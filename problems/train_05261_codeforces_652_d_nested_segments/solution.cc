#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r, id;
  long long ans;
} maps[200005];
bool cmp(const node& a, const node& b) {
  if (a.l == b.l) return a.r > b.r;
  return a.l < b.l;
}
bool cmp2(const node& a, const node& b) { return a.id < b.id; }
int ans[200005], X[200005 * 2];
int find(int a, int l, int r) {
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (X[mid] >= a)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return l;
}
long long sum[200005 << 2];
void pustup(int i) { sum[i] = sum[i << 1] + sum[i << 1 | 1]; }
void update(int L, int n, int l, int r, int i) {
  if (l == r) {
    sum[i] += n;
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid)
    update(L, n, l, mid, i << 1);
  else
    update(L, n, mid + 1, r, i << 1 | 1);
  pustup(i);
}
long long query(int L, int R, int l, int r, int i) {
  if (L <= l && r <= R) {
    return sum[i];
  }
  int mid = (l + r) >> 1;
  long long ans = 0;
  if (L <= mid) ans = query(L, R, l, mid, i << 1);
  if (R > mid) ans += query(L, R, mid + 1, r, i << 1 | 1);
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &maps[i].l, &maps[i].r);
    maps[i].id = i;
    X[++cnt] = maps[i].r;
  }
  sort(X + 1, X + 1 + cnt);
  for (int i = 1; i <= n; i++) {
    maps[i].r = find(maps[i].r, 1, cnt);
    update(maps[i].r, 1, 1, cnt, 1);
  }
  sort(maps + 1, maps + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    maps[i].ans = query(1, maps[i].r, 1, cnt, 1) - 1;
    update(maps[i].r, -1, 1, cnt, 1);
  }
  sort(maps + 1, maps + 1 + n, cmp2);
  for (int i = 1; i <= n; i++) printf("%I64d\n", maps[i].ans);
}
