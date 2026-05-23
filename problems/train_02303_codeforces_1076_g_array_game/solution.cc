#include <bits/stdc++.h>
using namespace std;
const int M = 200005;
int read() {
  int x = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * flag;
}
int n, m, k, all, la[4 * M];
long long d;
struct node {
  int s[1 << 5];
  node() { memset(s, 0, sizeof s); }
} tr[4 * M][2];
void up(int x) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < all; j++)
      tr[x][i].s[j] = tr[x << 1][i].s[tr[x << 1 | 1][i].s[j]];
}
void init(int x, int t, int f) {
  for (int i = 0; i < all; i++) {
    if (i != all - 1 || !f)
      tr[x][t].s[i] = (i >> 1) + (1 << m - 1);
    else
      tr[x][t].s[i] = (i >> 1);
  }
}
void build(int i, int l, int r) {
  if (l == r) {
    scanf("%lld", &d);
    init(i, 0, d % 2);
    init(i, 1, (d % 2) ^ 1);
    return;
  }
  int mid = (l + r) >> 1;
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
  up(i);
}
void flip(int x) {
  la[x] ^= 1;
  swap(tr[x][0], tr[x][1]);
}
void down(int x) {
  if (!la[x]) return;
  flip(x << 1);
  flip(x << 1 | 1);
  la[x] = 0;
}
void upd(int i, int l, int r, int L, int R) {
  if (L > r || l > R) return;
  if (L <= l && r <= R) {
    flip(i);
    return;
  }
  down(i);
  int mid = (l + r) >> 1;
  upd(i << 1, l, mid, L, R);
  upd(i << 1 | 1, mid + 1, r, L, R);
  up(i);
}
node ask(int i, int l, int r, int L, int R) {
  if (L <= l && r <= R) return tr[i][0];
  int mid = (l + r) >> 1;
  down(i);
  if (L <= mid && R <= mid) return ask(i << 1, l, mid, L, R);
  if (L > mid && R > mid) return ask(i << 1 | 1, mid + 1, r, L, R);
  node t1 = ask(i << 1, l, mid, L, R), res;
  node t2 = ask(i << 1 | 1, mid + 1, r, L, R);
  for (int j = 0; j < all; j++) res.s[j] = t1.s[t2.s[j]];
  return res;
}
int main() {
  n = read();
  m = read();
  k = read();
  all = (1 << m);
  build(1, 1, n);
  while (k--) {
    int op = read(), l = read(), r = read();
    if (op == 1) {
      scanf("%lld", &d);
      if (d % 2) upd(1, 1, n, l, r);
    } else {
      node ans = ask(1, 1, n, l, r);
      if (ans.s[all - 1] >> (m - 1))
        puts("1");
      else
        puts("2");
    }
  }
}
