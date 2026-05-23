#include <bits/stdc++.h>
using namespace std;
const int N = 414514;
int n, tt;
int f[N], r[N];
int rt[N], ls[N * 30], rs[N * 30], sz[N * 30];
long long su[N * 30], as;
void add(int &i, int l, int r, int s) {
  if (!i) i = ++tt;
  if (l == r) {
    sz[i] = 1, su[i] = s;
    return;
  }
  if (s <= ((l + r) >> 1))
    add(ls[i], l, ((l + r) >> 1), s);
  else
    add(rs[i], ((l + r) >> 1) + 1, r, s);
  sz[i] = sz[ls[i]] + sz[rs[i]];
  su[i] = su[ls[i]] + su[rs[i]];
}
void merge(int &x, int y) {
  if (!x || !y) {
    x = x | y;
    return;
  }
  as -= 1ll * su[ls[x]] * sz[rs[x]] + 1ll * su[ls[y]] * sz[rs[y]];
  merge(ls[x], ls[y]);
  merge(rs[x], rs[y]);
  as += 1ll * su[ls[x]] * sz[rs[x]];
  sz[x] += sz[y];
  su[x] += su[y];
  return;
}
int get(int x) { return x == f[x] ? x : f[x] = get(f[x]); }
void mrg(int x, int y) {
  x = get(x), y = get(y);
  f[y] = x;
  as -= 1ll * su[rt[x]] * x + 1ll * su[rt[y]] * y;
  merge(rt[x], rt[y]);
  as += 1ll * su[rt[x]] * x;
  r[x] = r[y];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 4e5; i++) f[i] = r[i] = i;
  for (int i = 1, x, y; i <= n; i++) {
    scanf("%d%d", &x, &y);
    int k = rt[x] ? r[get(x)] + 1 : x;
    as -= 1ll * x * y;
    as += 1ll * k * y;
    add(rt[k], 1, n, y);
    if (rt[k - 1]) mrg(k - 1, k);
    if (rt[k + 1]) mrg(k, k + 1);
    printf("%lld\n", as);
  }
}
