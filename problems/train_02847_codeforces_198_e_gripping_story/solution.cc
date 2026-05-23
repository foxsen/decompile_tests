#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0;
  bool f = 0;
  char ch = ' ';
  while (!isdigit(ch)) {
    f |= (ch == '-');
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = getchar();
  }
  return (f) ? (-s) : (s);
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10) {
    putchar(x + '0');
    return;
  }
  write(x / 10);
  putchar((x % 10) + '0');
}
const int N = 250005;
int n, pp[N], jyl = 0, id[N];
long long rr[N];
bool limit[N];
struct node {
  int m, p, r;
  long long dis;
} Fe[N];
inline bool cmpdis(int aa, int bb) { return Fe[aa].dis < Fe[bb].dis; }
inline long long sqr(long long x) { return 1ll * x * x; }
struct segtree {
  int sum;
  set<pair<int, int> > wwx;
} T[N << 2];
inline void build(int x, int l, int r) {
  int i;
  T[x].sum = r - l + 1;
  for (i = l; i <= r; i++) T[x].wwx.insert(pair<int, int>(Fe[id[i]].m, id[i]));
  if (l == r) return;
  int mid = (l + r) >> 1;
  build((x << 1), l, mid);
  build((x << 1 | 1), mid + 1, r);
}
inline void query(int x, int l, int r, long long sr, int sp) {
  if (Fe[id[l]].dis > sr || T[x].sum == 0) return;
  if (Fe[id[r]].dis <= sr) {
    set<pair<int, int> >::iterator it;
    while (T[x].sum && T[x].wwx.begin()->first <= sp) {
      it = T[x].wwx.begin();
      int oo = it->second;
      if (!limit[oo]) {
        limit[oo] = 1;
        jyl++;
        rr[jyl] = 1ll * Fe[oo].r * Fe[oo].r;
        pp[jyl] = Fe[oo].p;
      }
      T[x].wwx.erase(it);
      T[x].sum--;
    }
    return;
  }
  int mid = (l + r) >> 1;
  query((x << 1), l, mid, sr, sp);
  query((x << 1 | 1), mid + 1, r, sr, sp);
}
int main() {
  int i;
  long long x0, y0, x, y;
  x0 = read();
  y0 = read();
  pp[0] = read();
  rr[0] = read();
  rr[0] = sqr(rr[0]);
  n = read();
  for (i = 1; i <= n; i++) {
    x = read(), y = read(), Fe[i].m = read(), Fe[i].p = read(),
    Fe[i].r = read();
    Fe[i].dis = 1ll * (sqr(x - x0) + sqr(y - y0));
    id[i] = i;
  }
  sort(id + 1, id + n + 1, cmpdis);
  build(1, 1, n);
  for (i = 0; jyl <= n && i <= jyl; i++) query(1, 1, n, rr[i], pp[i]);
  write(jyl), putchar('\n');
  return 0;
}
