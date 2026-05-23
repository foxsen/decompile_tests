#include <bits/stdc++.h>
using namespace std;
int base = 1000000000, low[200010 * 4], high[200010 * 4], a[200010 * 4], n, m;
long long gt[200010 * 4][3], add[200010 * 4], sum[200010 * 4], d[200010 * 4];
void more(int s, int value) {
  long long giatri, tich;
  giatri = value;
  add[s] = (add[s] + value) % base;
  tich = (giatri * sum[high[s] - low[s] + 1]) % base;
  gt[s][1] = (gt[s][1] + tich) % base;
  tich = (giatri * sum[high[s] - low[s]]) % base;
  gt[s][2] = (gt[s][2] + tich) % base;
}
void down(int s) {
  more(s * 2, add[s]);
  more(s * 2 + 1, add[s]);
  add[s] = 0;
}
void update(int s) {
  long long v1, v2;
  gt[s][1] = gt[s * 2][1];
  v2 = d[high[s * 2] - low[s * 2] + 1];
  v1 = d[high[s * 2] - low[s * 2] + 2];
  v1 = (v1 * gt[s * 2 + 1][1]) % base;
  v2 = (v2 * gt[s * 2 + 1][2]) % base;
  v1 = (v1 + v2) % base;
  gt[s][1] = (gt[s][1] + v1) % base;
  gt[s][2] = gt[s * 2][2];
  v2 = d[high[s * 2] - low[s * 2]];
  v1 = d[high[s * 2] - low[s * 2] + 1];
  v1 = (v1 * gt[s * 2 + 1][1]) % base;
  v2 = (v2 * gt[s * 2 + 1][2]) % base;
  v1 = (v1 + v2) % base;
  gt[s][2] = (gt[s][2] + v1) % base;
}
void push(int trai, int phai, int value, int s) {
  if ((trai <= low[s]) && (high[s] <= phai))
    more(s, value);
  else {
    down(s);
    if (trai <= high[s * 2]) push(trai, phai, value, s * 2);
    if (phai > high[s * 2]) push(trai, phai, value, s * 2 + 1);
    update(s);
  }
}
void change(int pivot, int value, int s) {
  if (low[s] == high[s]) {
    gt[s][1] = value;
    gt[s][2] = 0;
    add[s] = 0;
  } else {
    down(s);
    if (pivot <= high[s * 2])
      change(pivot, value, s * 2);
    else
      change(pivot, value, s * 2 + 1);
    update(s);
  }
}
int get(int trai, int phai, int s) {
  if ((trai <= low[s]) && (high[s] <= phai)) {
    long long v1, v2, value;
    v2 = d[low[s] - trai];
    v1 = d[low[s] - trai + 1];
    v1 = (v1 * gt[s][1]) % base;
    v2 = (v2 * gt[s][2]) % base;
    value = (v1 + v2) % base;
    return value;
  } else {
    down(s);
    long long value = 0;
    if (trai <= high[s * 2]) value = (value + get(trai, phai, s * 2)) % base;
    if (phai > high[s * 2]) value = (value + get(trai, phai, s * 2 + 1)) % base;
    update(s);
    return value;
  }
}
void build(int s, int dau, int cuoi) {
  low[s] = dau;
  high[s] = cuoi;
  if (dau == cuoi) {
    gt[s][1] = a[dau];
    gt[s][2] = 0;
    add[s] = 0;
  } else {
    int mid;
    mid = (dau + cuoi) / 2;
    build(s * 2, dau, mid);
    build(s * 2 + 1, mid + 1, cuoi);
    update(s);
  }
}
void init() {
  int i;
  d[0] = 0;
  d[1] = 1;
  for (i = 2; i <= n; i++) d[i] = (d[i - 1] + d[i - 2]) % base;
  sum[0] = 0;
  for (i = 1; i <= n; i++) sum[i] = (sum[i - 1] + d[i]) % base;
}
int main() {
  int i, tp, pivot, value, trai, phai, ans;
  scanf("%d%d", &n, &m);
  init();
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, 1, n);
  for (i = 1; i <= m; i++) {
    scanf("%d", &tp);
    if (tp == 1) {
      scanf("%d%d", &pivot, &value);
      change(pivot, value, 1);
    } else if (tp == 2) {
      scanf("%d%d", &trai, &phai);
      ans = get(trai, phai, 1);
      printf("%d\n", ans);
    } else {
      scanf("%d%d%d", &trai, &phai, &value);
      push(trai, phai, value, 1);
    }
  }
  return 0;
}
