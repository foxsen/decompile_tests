#include <bits/stdc++.h>
using namespace std;
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < 48) c = getchar();
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x;
}
const int maxn = 1e5 + 10;
int n, q;
long long sum[maxn << 2], tag[maxn << 2];
int len[maxn << 2], col[maxn << 2];
void maintain(int k) {
  sum[k] = sum[k << 1] + sum[k << 1 | 1];
  col[k] = col[k << 1] == col[k << 1 | 1] ? col[k << 1] : 0;
}
void pushtag(int k, long long x) { sum[k] += x * len[k], tag[k] += x; }
void pushdown(int k) {
  long long &x = tag[k];
  if (x) pushtag(k << 1, x), pushtag(k << 1 | 1, x), x = 0;
  if (col[k]) col[k << 1] = col[k << 1 | 1] = col[k];
}
void build(int k, int l, int r) {
  len[k] = r - l + 1;
  if (l == r) {
    col[k] = l;
    return;
  }
  build(k << 1, l, ((l + r) >> 1)), build(k << 1 | 1, ((l + r) >> 1) + 1, r),
      maintain(k);
}
void upd(int k, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr && col[k]) {
    pushtag(k, abs(col[k] - x)), col[k] = x;
    return;
  }
  pushdown(k);
  if (ql <= ((l + r) >> 1)) upd(k << 1, l, ((l + r) >> 1), ql, qr, x);
  if (qr > ((l + r) >> 1)) upd(k << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr, x);
  maintain(k);
}
long long query(int k, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return sum[k];
  pushdown(k);
  long long res = 0;
  if (ql <= ((l + r) >> 1)) res = query(k << 1, l, ((l + r) >> 1), ql, qr);
  if (qr > ((l + r) >> 1))
    res += query(k << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr);
  return res;
}
int main() {
  cin >> n >> q;
  build(1, 1, n);
  while (q--) {
    int op = read(), l = read(), r = read();
    if (op == 1) {
      int x = read();
      upd(1, 1, n, l, r, x);
    } else {
      printf("%I64d\n", query(1, 1, n, l, r));
    }
  }
  return 0;
}
