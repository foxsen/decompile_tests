#include <bits/stdc++.h>
using namespace std;
long long t[400000];
long long a[1 << 17];
void build_segment_tree(long long v, long long tl, long long tr, bool op) {
  if (tl == tr) {
    t[v] = a[tl];
    return;
  }
  long long tm = tl + (tr - tl) / 2;
  build_segment_tree(2 * v, tl, tm, !op);
  build_segment_tree(2 * v + 1, tm + 1, tr, !op);
  if (op)
    t[v] = t[2 * v] | t[2 * v + 1];
  else
    t[v] = t[2 * v] ^ t[2 * v + 1];
}
void update_lazy_propagation(long long v, long long tl, long long tr,
                             long long pos, long long val, bool op) {
  if (tl == tr) {
    t[v] = val;
    return;
  }
  long long tm = tl + (tr - tl) / 2;
  if (pos <= tm)
    update_lazy_propagation(2 * v, tl, tm, pos, val, !op);
  else
    update_lazy_propagation(2 * v + 1, tm + 1, tr, pos, val, !op);
  if (op)
    t[v] = t[2 * v] | t[2 * v + 1];
  else
    t[v] = t[2 * v] ^ t[2 * v + 1];
}
signed main() {
  long long n, q;
  cin >> n >> q;
  long long size = 1 << n;
  for (long long i = 0; i < size; i++) cin >> a[i];
  build_segment_tree(1, 0, size - 1, n & 1);
  while (q--) {
    long long pos, val;
    cin >> pos >> val;
    pos--;
    update_lazy_propagation(1, 0, size - 1, pos, val, n & 1);
    cout << t[1] << endl;
  }
}
