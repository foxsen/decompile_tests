#include <bits/stdc++.h>
using namespace std;
int n;
int a[300005];
int rev[300005];
int der[1200005];
void makeT(int idx, int l, int r) {
  if (l == r) {
    der[idx] = (l > 0 ? (rev[l] < rev[l - 1]) : 0);
    return;
  }
  int m = (l + r) / 2;
  makeT(idx * 2, l, m);
  makeT(idx * 2 + 1, m + 1, r);
  der[idx] = der[idx * 2] + der[idx * 2 + 1];
}
int getSum(int idx, int l, int r, int a, int b) {
  if (l == a && r == b) return der[idx];
  int m = (a + b) / 2;
  int ans = 0;
  if (l <= m) ans += getSum(idx * 2, l, min(r, m), a, m);
  if (r >= m + 1) ans += getSum(idx * 2 + 1, max(l, m + 1), r, m + 1, b);
  return ans;
}
void setT(int idx, int pos, int val, int a, int b) {
  if (a == b) {
    der[idx] = val;
    return;
  }
  int m = (a + b) / 2;
  if (pos <= m)
    setT(idx * 2, pos, val, a, m);
  else
    setT(idx * 2 + 1, pos, val, m + 1, b);
  der[idx] = der[idx * 2] + der[idx * 2 + 1];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    rev[a[i]] = i;
  }
  int q;
  scanf("%d", &q);
  makeT(1, 1, n);
  for (int t = 0; t < q; t++) {
    int tp, x, y;
    scanf("%d%d%d", &tp, &x, &y);
    if (tp == 1) {
      int ans = 1 + (x + 1 <= y ? getSum(1, x + 1, y, 1, n) : 0);
      printf("%d\n", ans);
    } else {
      swap(a[x], a[y]);
      rev[a[x]] = x;
      rev[a[y]] = y;
      if (a[x] > 1) setT(1, a[x], rev[a[x]] < rev[a[x] - 1], 1, n);
      if (a[x] + 1 <= n) setT(1, a[x] + 1, rev[a[x] + 1] < rev[a[x]], 1, n);
      if (a[y] > 1) setT(1, a[y], rev[a[y]] < rev[a[y] - 1], 1, n);
      if (a[y] + 1 <= n) setT(1, a[y] + 1, rev[a[y] + 1] < rev[a[y]], 1, n);
    }
  }
  return 0;
}
