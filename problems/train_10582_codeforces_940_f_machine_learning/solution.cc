#include <bits/stdc++.h>
using std::lower_bound;
using std::sort;
using std::swap;
using std::unique;
const int N(3e5 + 5);
template <class type>
inline const void read(type &in) {
  in = 0;
  char ch(getchar());
  while (ch < 48 || ch > 57) ch = getchar();
  while (ch > 47 && ch < 58)
    in = (in << 3) + (in << 1) + (ch & 15), ch = getchar();
}
int belong[N], n, m, target[N], goal[N], cnt[N], num[N], lsh[N], a[N], ans[N],
    tot;
struct query {
  int l, r, t, id;
  inline query() {}
  inline query(const int &l, const int &r, const int &t, const int &id)
      : l(l), r(r), t(t), id(id) {}
  inline const bool operator<(const query &q) const {
    return belong[l] ^ belong[q.l]   ? belong[l] < belong[q.l]
           : belong[r] ^ belong[q.r] ? belong[r] < belong[q.r]
                                     : t < q.t;
  }
} q[N];
inline const int pos(const int &x) {
  return lower_bound(lsh + 1, lsh + tot + 1, x) - lsh;
}
inline const void add(const int &x) {
  if (cnt[a[x]]) num[cnt[a[x]]]--;
  num[++cnt[a[x]]]++;
}
inline const void del(const int &x) {
  num[cnt[a[x]]]--;
  if (cnt[a[x]]) num[--cnt[a[x]]]++;
}
inline const void upd(const int &x, const int &l, const int &r) {
  const int p(target[x]);
  if (p >= l && p <= r) del(p);
  swap(a[p], goal[x]);
  if (p >= l && p <= r) add(p);
}
inline const int ask() {
  for (int i(1); i <= n; i++)
    if (!num[i]) return i;
}
int main() {
  read(n);
  read(m);
  for (int i(1); i <= n; i++) read(a[i]), lsh[++tot] = a[i];
  int l(1), r(0), t(0), qcnt(0), ccnt(0);
  for (int i(1), opt, x, y; i <= m; i++)
    if (read(opt), read(x), read(y), opt & 1)
      qcnt++, q[qcnt] = query(x, y, ccnt, qcnt);
    else
      target[++ccnt] = x, lsh[++tot] = goal[ccnt] = y;
  sort(lsh + 1, lsh + tot + 1);
  tot = unique(lsh + 1, lsh + tot + 1) - lsh - 1;
  for (int i(1); i <= n; i++) a[i] = pos(a[i]);
  for (int i(1); i <= ccnt; i++) goal[i] = pos(goal[i]);
  const int size(pow(n, 2.0 / 3));
  for (int i(1); i <= n; i++) belong[i] = (i - 1) / size + 1;
  sort(q + 1, q + qcnt + 1);
  for (int i(1); i <= m; i++) {
    while (r < q[i].r) add(++r);
    while (l > q[i].l) add(--l);
    while (r > q[i].r) del(r--);
    while (l < q[i].l) del(l++);
    while (t < q[i].t) upd(++t, l, r);
    while (t > q[i].t) upd(t--, l, r);
    ans[q[i].id] = ask();
  }
  for (int i(1); i <= qcnt; i++) printf("%d\n", ans[i]);
  return 0;
}
