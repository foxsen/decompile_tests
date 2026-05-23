#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, m;
struct NODE {
  long long m1[10], m2[10];
  NODE() {
    for (int i = 0; i <= 9; i++) m1[i] = m2[i] = 2e10;
  }
  NODE operator+(const NODE& b) const {
    NODE res;
    for (int i = 0; i <= 9; i++) {
      res.m1[i] = min(m1[i], b.m1[i]);
      if (m1[i] < b.m1[i])
        res.m2[i] = min(m2[i], b.m1[i]);
      else
        res.m2[i] = min(m1[i], b.m2[i]);
    }
    return res;
  }
} t[N << 2];
void update(int l, int r, int rt, int x, int y) {
  if (l == r) {
    t[rt] = NODE();
    int num = y, c = 0;
    while (num) {
      if (num % 10) t[rt].m1[c] = y;
      num /= 10;
      c++;
    }
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m)
    update(l, m, rt << 1, x, y);
  else
    update(m + 1, r, rt << 1 | 1, x, y);
  t[rt] = t[rt << 1] + t[rt << 1 | 1];
}
NODE query(int l, int r, int rt, int L, int R) {
  if (L <= l && r <= R) return t[rt];
  int m = (l + r) >> 1;
  NODE res;
  if (L <= m) res = res + query(l, m, rt << 1, L, R);
  if (m < R) res = res + query(m + 1, r, rt << 1 | 1, L, R);
  return res;
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++) {
      int w;
      scanf("%d", &w);
      update(1, n, 1, i, w);
    }
    while (m--) {
      int op, x, y;
      scanf("%d%d%d", &op, &x, &y);
      if (op == 1)
        update(1, n, 1, x, y);
      else {
        NODE res = query(1, n, 1, x, y);
        long long ans = 2e10;
        for (int i = 0; i <= 9; i++) ans = min(ans, res.m1[i] + res.m2[i]);
        if (ans >= 2e10)
          puts("-1");
        else
          printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
