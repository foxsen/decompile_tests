#include <bits/stdc++.h>
using namespace std;
const long long N = 200005, logN = 21;
struct data {
  long long ls, rs, val;
} tree[N * logN];
long long cur, rt[N], n, q, sortb[N], b[N];
inline void init() { cur = 0; }
inline void push_up(long long p) {
  tree[p].val = tree[tree[p].ls].val + tree[tree[p].rs].val;
}
inline long long build(long long l, long long r) {
  long long k = cur++;
  if (l == r) {
    tree[k].val = 0;
    return k;
  }
  long long mid = (l + r) >> 1;
  tree[k].ls = build(l, mid);
  tree[k].rs = build(mid + 1, r);
  push_up(k);
  return k;
}
inline long long insert(long long nod, long long l, long long r, long long pos,
                        long long add) {
  long long k = cur++;
  tree[k] = tree[nod];
  if (l == r) {
    tree[k].val += add;
    return k;
  }
  long long mid = (l + r) >> 1;
  if (pos <= mid)
    tree[k].ls = insert(tree[nod].ls, l, mid, pos, add);
  else
    tree[k].rs = insert(tree[nod].rs, mid + 1, r, pos, add);
  push_up(k);
  return k;
}
inline long long ask(long long l, long long r, long long i, long long j,
                     long long nod) {
  if (i > j) return 0;
  if (l == i && r == j) return tree[nod].val;
  long long mid = l + r >> 1;
  if (j <= mid)
    return ask(l, mid, i, j, tree[nod].ls);
  else if (i > mid)
    return ask(mid + 1, r, i, j, tree[nod].rs);
  else
    return ask(l, mid, i, mid, tree[nod].ls) +
           ask(mid + 1, r, mid + 1, j, tree[nod].rs);
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  write(a);
  puts("");
}
long long an[N][9];
int main() {
  n = read();
  long long m = read();
  init();
  rt[0] = build(1, n);
  for (long long i = 1; i <= n; i++) {
    rt[i] = insert(rt[i - 1], 1, n, read(), 1);
  }
  for (long long i = 1; i <= m; i++) {
    long long l = read(), d = read(), r = read(), h = read();
    an[i][0] = ask(1, n, 1, d - 1, rt[l - 1]);
    an[i][1] = ask(1, n, 1, h, rt[l - 1]);
    an[i][2] = ask(1, n, 1, n, rt[l - 1]);
    an[i][3] = ask(1, n, 1, d - 1, rt[r]) - an[i][0];
    an[i][4] = ask(1, n, 1, h, rt[r]) - an[i][1];
    an[i][5] = ask(1, n, 1, n, rt[r]) - an[i][2];
    an[i][6] = ask(1, n, 1, d - 1, rt[n]) - an[i][0] - an[i][3];
    an[i][7] = ask(1, n, 1, h, rt[n]) - an[i][1] - an[i][4];
    an[i][8] = ask(1, n, 1, n, rt[n]) - an[i][2] - an[i][5];
    an[i][1] -= an[i][0];
    an[i][2] -= an[i][0] + an[i][1];
    an[i][4] -= an[i][3];
    an[i][5] -= an[i][3] + an[i][4];
    an[i][7] -= an[i][6];
    an[i][8] -= an[i][6] + an[i][7];
  }
  for (long long i = 1; i <= m; i++) {
    writeln(an[i][0] * (an[i][4] + an[i][5] + an[i][7] + an[i][8]) +
            (long long)an[i][1] * (n - an[i][1] - an[i][2] - an[i][0]) +
            (long long)an[i][2] * (an[i][3] + an[i][4] + an[i][6] + an[i][7]) +
            (long long)an[i][3] * (an[i][4] + an[i][5] + an[i][7] + an[i][8]) +
            (long long)an[i][4] * (an[i][5] + an[i][6] + an[i][7] + an[i][8]) +
            (long long)an[i][5] * (an[i][6] + an[i][7]) +
            (long long)an[i][4] * (an[i][4] - 1) / 2);
  }
  return 0;
}
