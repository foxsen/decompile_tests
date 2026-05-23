#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int M = 6000005;
int col[N], rec[N], root[N], cnt = 0;
int lc[M], rc[M], key[M], rightmost[M];
inline void Insert(int x, int y, int l, int r, int pos, int val) {
  key[x] = key[y] + val;
  if (l == r) {
    rightmost[x] = key[x];
    return;
  }
  int mid = (l + r) >> 1, tmp;
  if (pos <= mid) {
    tmp = ++cnt;
    rc[x] = rc[y];
    Insert(tmp, lc[y], l, mid, pos, val);
    lc[x] = tmp;
  } else {
    tmp = ++cnt;
    lc[x] = lc[y];
    Insert(tmp, rc[y], mid + 1, r, pos, val);
    rc[x] = tmp;
  }
  rightmost[x] = rightmost[rc[x]];
}
inline int Query(int x, int l, int r, int kth) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  if (key[rc[x]] > kth)
    return Query(rc[x], mid + 1, r, kth);
  else if (key[rc[x]] == kth) {
    if (rightmost[lc[x]] == 0)
      return Query(lc[x], l, mid, 0);
    else
      return Query(rc[x], mid + 1, r, kth);
  } else
    return Query(lc[x], l, mid, kth - key[rc[x]]);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &col[i]);
  for (int i = 1; i <= n; i++) {
    root[i] = ++cnt;
    if (rec[col[i]]) {
      Insert(root[i], root[i - 1], 1, n, rec[col[i]], -1);
      Insert(root[i], root[i], 1, n, i, 1);
    } else
      Insert(root[i], root[i - 1], 1, n, i, 1);
    rec[col[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    int r = n, ans = 0;
    while (r >= 1) {
      ans++;
      if (key[root[r]] <= i) break;
      r = Query(root[r], 1, n, i) - 1;
    }
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}
