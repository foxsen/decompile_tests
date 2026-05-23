#include <bits/stdc++.h>
using namespace std;
int sa[4 * 200005], sb[4 * 200005], a, b, n = 200003;
void modify_sa(int pos, int val, int id = 1, int l = 0, int r = n) {
  if (r - l < 2) {
    sa[id] += val;
    sa[id] = min(sa[id], a);
    return;
  }
  int mid = (l + r) / 2;
  if (pos < mid)
    modify_sa(pos, val, 2 * id, l, mid);
  else
    modify_sa(pos, val, 2 * id + 1, mid, r);
  sa[id] = sa[2 * id] + sa[2 * id + 1];
}
void modify_sb(int pos, int val, int id = 1, int l = 0, int r = n) {
  if (r - l < 2) {
    sb[id] += val;
    sb[id] = min(sb[id], b);
    return;
  }
  int mid = (l + r) / 2;
  if (pos < mid)
    modify_sb(pos, val, 2 * id, l, mid);
  else
    modify_sb(pos, val, 2 * id + 1, mid, r);
  sb[id] = sb[2 * id] + sb[2 * id + 1];
}
int sum_sa(int b, int e, int id = 1, int l = 0, int r = n) {
  if (b >= r || e <= l) return 0;
  if (l >= b && r <= e) return sa[id];
  int mid = (l + r) / 2;
  return sum_sa(b, e, 2 * id, l, mid) + sum_sa(b, e, 2 * id + 1, mid, r);
}
int sum_sb(int b, int e, int id = 1, int l = 0, int r = n) {
  if (b >= r || e <= l) return 0;
  if (l >= b && r <= e) return sb[id];
  int mid = (l + r) / 2;
  return sum_sb(b, e, 2 * id, l, mid) + sum_sb(b, e, 2 * id + 1, mid, r);
}
int main() {
  int m, k, q, i;
  scanf("%d", &m);
  scanf("%d", &k);
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &q);
  memset(sa, 0, sizeof(sa));
  memset(sb, 0, sizeof(sb));
  for (i = 0; i < q; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int pos, val;
      scanf("%d", &pos);
      scanf("%d", &val);
      modify_sa(pos, val);
      modify_sb(pos, val);
    } else {
      int st;
      scanf("%d", &st);
      printf("%d\n", sum_sb(0, st) + sum_sa(st + k, n));
    }
  }
  return 0;
}
